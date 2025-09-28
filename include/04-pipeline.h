#pragma once
#include "02-codegen.h"
#include <vector>
#include <iostream>

class Pipeline {
    std::vector<Instruction> instructions;
public:
    Pipeline(const std::vector<Instruction>& instrs);
    void simulate();
};
/*
#pragma once
#include "02-codegen.h"
#include <vector>
#include <iostream>

class Pipeline {
    std::vector<Instruction> instructions;
public:
    Pipeline(const std::vector<Instruction>& instrs) : instructions(instrs) {}
    void simulate() {
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
};

*/
