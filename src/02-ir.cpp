#include "03-ir.h"

// IRInstr constructor
IRInstr::IRInstr(IROp o, const std::string &l, const std::string &r1, const std::string &r2)
    : op(o), lhs(l), rhs1(r1), rhs2(r2) {}

// IR methods
void IR::addInstruction(const IRInstr &instr) {
    instructions.push_back(instr);
}

const std::vector<IRInstr>& IR::getInstructions() const {
    return instructions;
}

void IR::printIR() const {
    for (auto &instr : instructions) {
        std::string opStr;
        switch (instr.op) {
            case IROp::ADD: opStr = "+"; break;
            case IROp::SUB: opStr = "-"; break;
            case IROp::MUL: opStr = "*"; break;
            case IROp::DIV: opStr = "/"; break;
        }
        std::cout << instr.lhs << " = " << instr.rhs1 << " " << opStr << " " << instr.rhs2 << "\n";
    }
}
