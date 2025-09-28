/*#include "04-pipeline.h"
#include <iostream>

void Pipeline::simulate() {
    std::cout << "Pipeline Simulation:\n";
    int cycle = 1;
    for(const auto &instr : instructions) {
        std::cout << "Cycle " << cycle << ": IF " << instr.op << " " << instr.dest;
        if(!instr.src1.empty()) std::cout << ", " << instr.src1;
        if(!instr.src2.empty()) std::cout << ", " << instr.src2;
        std::cout << "\n";
        cycle++;
    }
}*/
#include "04-pipeline.h"

Pipeline::Pipeline(const std::vector<Instruction> &instrs) : instructions(instrs) {}

void Pipeline::simulate() {
    int cycle=1;
    for(auto &inst: instructions){
        std::string instrStr = (inst.op=="LOAD") ? inst.op+" "+inst.arg1 : inst.op+" "+inst.dest;
        std::cout << "Cycle " << cycle++ << ": IF " << instrStr << "\n";
        std::cout << "Cycle " << cycle++ << ": ID " << instrStr << "\n";
        std::cout << "Cycle " << cycle++ << ": EX " << instrStr << "\n";
        std::cout << "Cycle " << cycle++ << ": MEM " << instrStr << "\n";
        std::cout << "Cycle " << cycle++ << ": WB " << instrStr << "\n";
        std::cout << "-----\n";
    }
}

