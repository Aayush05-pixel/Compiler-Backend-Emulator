/*#include "02-codegen.h"
#include <iostream>

std::vector<Instruction> CodeGen::generateISA(
    const std::string &lhs,
    const std::string &rhs1,
    const std::string &rhs2,
    const std::string &op
) {
    std::vector<Instruction> instructions;

    // Load rhs1 and rhs2 into registers
    instructions.push_back({"LOAD", "R2", rhs1, ""});
    instructions.push_back({"LOAD", "R3", rhs2, ""});

    // Perform operation
    std::string opcode;
    if(op == "+") opcode = "ADD";
    else if(op == "-") opcode = "SUB";
    else if(op == "*") opcode = "MUL";
    else if(op == "/") opcode = "DIV";
    else opcode = "UNKNOWN";

    instructions.push_back({opcode, "R1", "R2", "R3"});

    // Store result
    instructions.push_back({"STORE", lhs, "R1", ""});

    return instructions;
}

void CodeGen::printISA(const std::vector<Instruction> &instructions) {
    std::cout << "Generated Assembly:\n";
    for(const auto &instr : instructions) {
        std::cout << instr.op << " " << instr.dest;
        if(!instr.src1.empty()) std::cout << ", " << instr.src1;
        if(!instr.src2.empty()) std::cout << ", " << instr.src2;
        std::cout << "\n";
    }
}
*/
#include "02-codegen.h"
#include <iostream>

std::vector<Instruction> Codegen::generateISA(const IR& ir, SymbolTable& symtab) {
    std::vector<Instruction> isa;
    for (auto &instr : ir.getInstructions()) {
        Instruction i;
        // LOAD rhs1
        i.op = "LOAD"; i.arg1 = instr.rhs1; isa.push_back(i);
        // LOAD rhs2
        i.op = "LOAD"; i.arg1 = instr.rhs2; isa.push_back(i);
        // Operation
        switch(instr.op){
            case IROp::ADD: i.op="ADD"; break;
            case IROp::SUB: i.op="SUB"; break;
            case IROp::MUL: i.op="MUL"; break;
            case IROp::DIV: i.op="DIV"; break;
        }
        i.dest = instr.lhs; i.arg1 = instr.rhs1; i.arg2 = instr.rhs2;
        isa.push_back(i);

        // compute result
        int val1 = symtab.getValue(instr.rhs1);
        int val2 = symtab.getValue(instr.rhs2);
        int res;
        if(instr.op==IROp::ADD) res = val1 + val2;
        else if(instr.op==IROp::SUB) res = val1 - val2;
        else if(instr.op==IROp::MUL) res = val1 * val2;
        else res = val1 / val2;
        symtab.setValue(instr.lhs,res);
    }
    return isa;
}

void Codegen::printISA(const std::vector<Instruction>& instructions) {
    for(auto &i: instructions){
        if(i.op=="LOAD") std::cout << i.op << " " << i.arg1 << "\n";
        else std::cout << i.op << " " << i.dest << " <- " << i.arg1 << "," << i.arg2 << "\n";
    }
}

