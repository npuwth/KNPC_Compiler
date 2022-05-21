#pragma once
#include<string>
#include<map>
#include<memory>

namespace SymTable {
    struct SymTableEntry {
    Type type;
};

struct SymTable {
    std::map<std::string, std::unique_ptr<SymTableEntry>> mp;
    SymTable* parent;
    SymTable(SymTable* _parent);
    void register_val(const string name);
};
}
