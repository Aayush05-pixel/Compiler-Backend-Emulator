#include "01-symbol_table.h"
#include "03-ir.h"
#include "02-codegen.h"
#include "04-pipeline.h"
#include <iostream>

int main() {
    SymbolTable symtab;

    // --- Step 1: Define variables ---
    std::string varA = "a", varB = "b", varC = "c";
    float valA, valB, valC;

    // Ask user for values of b and c
    std::cout << "Enter value for " << varB << ": ";
    std::cin >> valB;
    std::cout << "Enter value for " << varC << ": ";
    std::cin >> valC;

    // Add variables to Symbol Table
    symtab.setValue(varA, valA);
    symtab.setValue(varB, valB);
    symtab.setValue(varC, valC);

    // --- Step 2: Choose operation ---
    char op;
    std::cout << "Choose operation ( + - * / ): ";
    std::cin >> op;

    IROp irOp;
    switch(op) {
        case '+': irOp = IROp::ADD; break;
        case '-': irOp = IROp::SUB; break;
        case '*': irOp = IROp::MUL; break;
        case '/': irOp = IROp::DIV; break;
        default: 
            std::cout << "Invalid operation!\n";
            return 1;
    }

    // --- Step 3: Build IR ---
    IR ir;
    ir.addInstruction(IRInstr(irOp, varA, varB, varC));

    std::cout << "\n=== IR ===\n";
    ir.printIR();

    // --- Step 4: Generate ISA ---
    Codegen codegen;
    auto instructions = codegen.generateISA(ir, symtab);

    std::cout << "\n=== ISA ===\n";
    codegen.printISA(instructions);

    // --- Step 5: Compute result ---
    int result;
    switch(op) {
        case '+': result = valB + valC; break;
        case '-': result = valB - valC; break;
        case '*': result = valB * valC; break;
        case '/': result = valB / valC; break;
    }
    std::cout << "\n=== Result ===\n";
    std::cout << varA << " = " << result << "\n";

    // --- Step 6: Pipeline Simulation ---
    std::cout << "\n=== Pipeline ===\n";
    Pipeline pipeline(instructions);
    pipeline.simulate();

    return 0;
}

    
    /*
#include "01-symbol_table.h"
#include "03-ir.h"
#include "02-codegen.h"
#include "04-pipeline.h"
#include <iostream>

int main() {
    SymbolTable symtab;
    symtab.setValue("b",5);
    symtab.setValue("c",10);

    IR ir;
    ir.addInstruction(IRInstr(IROp::ADD,"a","b","c"));
    //ir.addInstruction(IRInstr(IROp::MUL,"a","b","c"));

    std::cout << "=== IR ===\n"; ir.printIR();
    Codegen codegen;
    auto isa = codegen.generateISA(ir,symtab);

    std::cout << "\n=== ISA ===\n"; codegen.printISA(isa);

    std::cout << "\n=== Result ===\n";
    symtab.print();

    std::cout << "\n=== Pipeline ===\n";
    Pipeline pipeline(isa); pipeline.simulate();

    return 0;
}*/
