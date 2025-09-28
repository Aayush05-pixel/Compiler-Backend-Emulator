/*#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>

struct Instruction {
    std::string op;   // e.g., "LOAD", "ADD", "STORE"
    std::string dest;
    std::string src1;
    std::string src2;
};

class CodeGen {
public:
    // Generate instructions for a simple binary operation
    std::vector<Instruction> generateISA(
        const std::string &lhs,
        const std::string &rhs1,
        const std::string &rhs2,
        const std::string &op
    );

    void printISA(const std::vector<Instruction> &instructions);
};

#endif


// include codegen.h
#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>
#include <iostream>
#include "03-ir.h"

struct Instruction {
    std::string op;
    std::string arg;
};

class Codegen {
public:
    std::vector<Instruction> generateISA(const IR &ir);
    void printISA(const std::vector<Instruction> &instructions) const;
};

#endif
*/
#pragma once
#include "03-ir.h"
#include "01-symbol_table.h"
#include <vector>
#include <string>

struct Instruction {
    std::string op;
    std::string arg1, arg2, dest;
    Instruction() = default;
};

class Codegen {
public:
    std::vector<Instruction> generateISA(const IR& ir, SymbolTable& symtab);
    void printISA(const std::vector<Instruction>& instructions);
};
