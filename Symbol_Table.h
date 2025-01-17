#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct Parameters {
    string type;  
    string name;  
    
    Parameters(const string& type, const string& name);
};

struct Function {
    string name;               
    string returnType;         
    vector<Parameters> Param;  
    Function(const string& name, const string& returnType, const vector<Parameters>& params);
    Function();
};

struct Class {
    string name;  
    Class(const string& name);
};

struct Variable {
    string name;   
    string type;   
    string value;  
    string constanta;
    Variable(const string& name, const string& type, const string& value = "");
};

extern vector<Variable> variabile;
extern vector<Variable> global_variabile;
bool existsVar(string name);
bool existsVarMain(string name);
string getValue(string name);
string TypeOf(string name);
class SymTable {
public:
    string scopeName;             
    SymTable* parent;             

    vector<Variable> variables;   
    vector<Function> functions;   
    vector<Class> classes;        

    vector<SymTable*> children;
    
    SymTable(const string& name, SymTable* parent = nullptr);
    
    void addVariable(const Variable &var);
    Variable* getVariable(const string& name);
    void addFunction(const Function &func);
    void addClass(const Class &cls);
    void updateValue(Variable &var, string new_value);
    bool getFunctionName(string name);
    Function* getFunction(const std::string& name);
    //Variable* getVariable(const std::string& name);
    void addChild(SymTable* child);
    void print(ostream &os, int indent = 0) const;
};

#endif 
