/*#pragma once
#include <string>
#include <vector>

enum class IROp { ADD, SUB, MUL, DIV };

struct IRInstr {
    IROp op;
    std::string dest;
    std::string src1;
    std::string src2;

    IRInstr(IROp o, const std::string &d, const std::string &s1, const std::string &s2);
};

class IR {
    std::vector<IRInstr> instructions;
public:
    void addInstruction(const IRInstr &instr);
    void printIR() const;
    const std::vector<IRInstr>& getInstructions() const;
};
*/
#pragma once
#include <vector>
#include <string>
#include <iostream>

enum class IROp { ADD, SUB, MUL, DIV };

struct IRInstr {
    IROp op;
    std::string lhs, rhs1, rhs2;
    IRInstr(IROp o, const std::string& l, const std::string& r1, const std::string& r2); // only declaration
};

class IR {
    std::vector<IRInstr> instructions;
public:
    void addInstruction(const IRInstr& instr);  // only declaration
    const std::vector<IRInstr>& getInstructions() const;
    void printIR() const;
};
