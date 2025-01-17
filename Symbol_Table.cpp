#include "Symbol_Table.h"
vector<Variable> variabile;
vector<Variable> global_variabile;

bool existsVar(string name){
    for (auto &var : global_variabile) 
          if(var.name==name)
                return 1;
    return 0;
}
bool existsVarMain(string name){
    for (auto &var : variabile) 
          if(var.name==name)
                return 1;
    return 0;
}
string TypeOf(string name){
    string rasp=" ";
    for (auto &var : global_variabile) 
       if(var.name==name)
         { rasp= var.type;}
    return rasp;
}
string getValue(string name){
    string val=" ";
    for (auto &var : global_variabile) 
       if(var.name==name)
         { val= var.value;}
    return val;
}
Parameters::Parameters(const string& type, const string& name)
    : type(type), name(name) {}

Function::Function(const string& name, const string& returnType, const vector<Parameters>& params)
    : name(name), returnType(returnType), Param(params) {}
Function::Function(){}

Class::Class(const string& name)
    : name(name) {}

Variable::Variable(const string& name, const string& type, const string& value)
    : name(name), type(type), value(value) {}

SymTable::SymTable(const string& name, SymTable* parent)
    : scopeName(name), parent(parent) {}

void SymTable::addVariable(const Variable &var) {
    variables.push_back(var);
}

Variable* SymTable::getVariable(const string& name)
{
    for (auto& var : variables) 
    {
        if (var.name == name) 
        {
            return &var;
        }
    }
    return nullptr;
}
void SymTable::updateValue(Variable &var,string value) {

     for (auto &vari : variables)
         if(vari.name==var.name)
          vari.value=value;
}
bool SymTable::getFunctionName(string name) {

     for (auto &func : functions)
     { 
         if(func.name==name)
          {  
             return 1;}
     }
        return 0;
}
Function* SymTable::getFunction(const std::string& name) {
    string funcName = string(name);
    for (auto &func : functions)
    {
        if (func.name == funcName)
        {
            return &func;  
        }
    }
    return nullptr;  
}

void SymTable::addFunction(const Function &func) {
    functions.push_back(func);
}

void SymTable::addClass(const Class &cls) {
    classes.push_back(cls);
}

void SymTable::addChild(SymTable* child) {
    children.push_back(child);
}

void SymTable::print(ostream &os, int indent) const {
    string indentStr(indent, ' ');
    os << indentStr << "Scope: " << scopeName << "\n";

     if (!classes.empty()) {
        os << indentStr << "  Classes:\n";
        for (const auto &cls : classes)
            os << indentStr << "    " << cls.name << "\n";
    }
    
    if (!variables.empty()) {
        os << indentStr << "  Variables:\n";
        for (const auto &var : variables) {
             os << indentStr << "    ";
            if(!var.constanta.empty())
            os << var.constanta<<" ";
            os<< var.type << " " << var.name;
            if (!var.value.empty())
                os << " = " << var.value;
            os << "\n";
        }
    }
    
    if (!functions.empty()) {
        os << indentStr << "  Functions:\n";
        for (const auto &func : functions) {
            os << indentStr << "    " << func.returnType << " " << func.name << "(";
            for (size_t i = 0; i < func.Param.size(); ++i) {
                os << func.Param[i].type << " " << func.Param[i].name;
                if (i < func.Param.size() - 1)
                    os << ", ";
            }
            os << ")\n";
        }
    }
    os<<"\n";
    
    for (const auto child : children) {
        child->print(os, indent + 2);
    }
}
