#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

class SymbolTable {
    std::unordered_map<std::string,int> table;
public:
    void setValue(const std::string& name, int val) { table[name] = val; }
    int getValue(const std::string& name) const { return table.at(name); }
    bool hasSymbol(const std::string& name) const { return table.find(name) != table.end(); }
    void print() const {
        std::cout << "Symbol Table:\n";
        for(auto &p: table) std::cout << p.first << " = " << p.second << "\n";
    }
};

/*
#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class SymbolTable {
    std::unordered_map<std::string, int> intVars;
public:
    void addSymbol(const std::string& name, const std::string& type) {
        if (type == "int") intVars[name] = 0;
    }

    void setValue(const std::string& name, int value) {
        if (intVars.find(name) != intVars.end()) intVars[name] = value;
    }

    int getValue(const std::string& name) const {
        auto it = intVars.find(name);
        if (it != intVars.end()) return it->second;
        return 0;
    }

    void print() const {
        for (auto &p : intVars) {
            std::cout << p.first << " = " << p.second << "\n";
        }
    }
};
*/
