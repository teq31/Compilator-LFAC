%{

#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include<fstream>
#include "AST.h"
#include "limbaj.tab.h"
#include "Symbol_Table.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyleng;
extern int yylex();

void yyerror(const char * s);

using namespace std;

class AST ast;

SymTable* globalTable = new SymTable("global");
SymTable* classTable = nullptr;
SymTable* functionTable = nullptr;
SymTable* blockTable=nullptr;
SymTable* mainTable=nullptr;
SymTable* currentTable=globalTable;
SymTable* parentTable=nullptr;
string scope;
string altscope;


bool isInteger(const std::string& str) 
{
    try 
    {
        std::stoi(str);
        return true;
    } 
    catch (const std::invalid_argument& ia) 
    {
        return false;
    } 
    catch (const std::out_of_range& oor) 
    {
        return false;
    }
}

bool isFloat(const std::string& str) 
{
    try 
    {
        std::stof(str);
        return true;
    } 
    catch (const std::invalid_argument& ia) 
    {
        return false;
    } 
    catch (const std::out_of_range& oor) 
    {
        return false;
    }
}

bool isBoolean(const std::string& str) 
{
    return (str == "true" || str == "false");
}

%}

%union {
    int num;
    float num_with_dot;
    bool bolean;
    char chr;
    char* string;
struct Node *nod;
struct ParamInfo *parametru;
struct Function *functie;
struct Function *metoda; 
struct Parameters *parameter;
struct Variable *variabila;
}

%token           BGINMAIN ENDMAIN ASSIGN BGINCLASS ENDCLASS CONST IF ELSE WHILE FOR BGINGLOBAL ENDGLOBAL BGINFUNC ENDFUNC PRINT
%token           LT LE GT GE EQ NEQ AND OR NOT 
%token<string>   ID TYPE TYPEOF
%token<num>      INT 
%token<num_with_dot> FLOAT   
%token<bolean>        BOOL 
%token<chr>        CHAR 
%token<string>     STRING CLASS 

%type<nod> print expression 
%type<string> array_list 
%type<parameter> param param_call 
%type<functie> list_param list_param_call
%type<metoda> list_param_class
%type<variabila> declarations assignments declaration1 assignments1 decl
%type<parameter> param_class
%type <num> nume




%left OR
%left AND
%left EQ NEQ
%left GT LT LE GE
%left '+' '-' 
%left '*' '/' 
%left '^' 
%left NOT
%left '(' ')' '[' ']'

%start progr

%%
progr: user_defined_data_types global_variables functions main { 
                                                                    cout <<"The program works!! /ᐠ - ˕ -マ \n";
                                                                    ofstream outFile("symbol_tables.txt");
                                                                    if (!outFile) {
                                                                        cerr << "Nu s-a putut deschide fișierul pentru scriere!" << endl;
                                                                        return 1;
                                                                    }
                                                                    globalTable->print(outFile);
                                                                    outFile.close();
                                                                  cout << "Tabela de simboluri a fost scrisă în symbol_tables.txt" << endl;
                                                               };

user_defined_data_types:
                       | BGINCLASS class_list ENDCLASS
                       ;

class_list :
                | class_list clasa 
                ;

clasa: CLASS nume   '{' list_class_fields methods'}' ';' 

nume: ID  { scope = $1 ;
            classTable = new SymTable(scope, globalTable);
            globalTable->addChild(classTable);
            globalTable->addClass(Class(scope));

           }
           ;

list_class_fields :  list_class_fields param_class ';'
                   |
                   ; 

param_class: TYPE ID 
{
    if (classTable->getVariable($2)) 
    {
        yyerror("Variable already exists in the class scope.");
    } 
    else
    {
        $$ = new Parameters($1, $2);
        classTable->addVariable(Variable($2, $1));
    }
};

list_param_class : param_class 
                    {
                        if (classTable->getVariable($1->name)) 
                        {
                            yyerror("Parameter conflicts with an existing variable in the class scope.");
                        } 
                        else
                        {
                            $$ = new Function();
                            $$->Param.push_back(*$1);
                        }
                    }
                    | list_param ',' param 
                    {
                        if (classTable->getVariable($3->name)) 
                        {
                            yyerror("Parameter conflicts with an existing variable in the class scope.");
                        }
                        else
                        {
                            $$->Param.push_back(*$3);
                        }
                    };

  
methods: 
    |TYPE ID '(' list_param_class ')' '{' 
    {
        scope = $2 ;
        if (classTable->getFunctionName(scope.c_str())) 
        {
            yyerror("Method redefinition");
        }
        else
        {
            functionTable = new SymTable(scope, classTable);
            currentTable=functionTable;
            classTable->addChild(functionTable);
            classTable->addFunction(Function($2,$1,$4->Param));}
    }  list1 '}'
    {
        Function* currentFunction = globalTable->getFunction(scope);
        if (currentFunction) 
        {
            for (const auto &var : variabile) 
            {
                bool conflictWithParam = false;
                for (const auto &parametru : currentFunction->Param) 
                {
                    if (parametru.name == var.name) 
                    {
                        conflictWithParam = true;
                        break;
                    }
                }
                if (functionTable->getVariable(var.name)) 
                {
                    yyerror("Variable already exists in the function scope.");
                } 
                else if (conflictWithParam) 
                {
                    yyerror("Variable conflicts with a function parameter.");
                } 
                else 
                {
                    functionTable->addVariable(var);
                }
            }
        }
        variabile.clear();
    }
    |TYPE ID '('')' '{' 
    {
        scope = $2 ;
        if (globalTable->getFunctionName(scope.c_str())) 
        {
            yyerror("Function redefinition");
        }
        else 
        {
            functionTable = new SymTable(scope, classTable);
            currentTable=functionTable;
            classTable->addChild(functionTable);
            classTable->addFunction(Function($2,$1,std::vector<Parameters>()));
        }
    } list1 '}'
    {
        for (const auto &var : variabile) 
        {
            if (functionTable->getVariable(var.name)) 
            {
                yyerror("Variable already exists in the function scope.");
            }
            functionTable->addVariable(var);
        }
        variabile.clear();
    }  
    ;

global_variables:
                | BGINGLOBAL global_variables_list ENDGLOBAL
                ;

global_variables_list :     
	      |  global_variables_list decl ';'   
	      ;

decl:  TYPE ID { 
                    if(!existsVar($2)) 
                    {   

                        globalTable->addVariable(Variable($2,$1,""));
                        $$=new Variable($2,$1);
                        global_variabile.push_back(*$$);
                    }
                    else 
                    {
                        string err="Variable '"+string($2)+"' was already declared ";
                        yyerror(err.c_str());
                    }
               }
    
       ;
       
functions:
          | BGINFUNC functions_list ENDFUNC
          ;

functions_list :     
	      |  functions_list decl_func 
	      ;

decl_func  : TYPE ID '(' list_param ')' '{'     
              {
            
                scope = $2; 
                if (globalTable->getFunctionName(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    functionTable = new SymTable(scope, globalTable);
                    currentTable=functionTable;
                    globalTable->addChild(functionTable);
                    globalTable->addFunction(Function($2,$1,$4->Param));
                }
              }
            list1 '}'    
            {  
                Function* currentFunction = globalTable->getFunction(scope);
                if (currentFunction) 
                {
                    for (const auto &var : variabile) 
                    {
                        bool conflictWithParam = false;
                        for (const auto &parametru : currentFunction->Param) 
                        {
                            if (parametru.name == var.name) 
                            {
                                conflictWithParam = true;
                                break;
                            }
                        }
                        if (functionTable->getVariable(var.name)) 
                        {
                            yyerror("Variable already exists in the function scope.");
                        } 
                        else if (conflictWithParam) 
                        {
                            yyerror("Variable conflicts with a function parameter.");
                        } 
                        else 
                        {
                            functionTable->addVariable(var);
                        }
                    }
                }
                variabile.clear();
            }
           |TYPE ID '(' ')' '{' { scope = $2; 
                if (globalTable->getFunctionName(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    functionTable = new SymTable(scope, globalTable);
                    currentTable=functionTable;
                    globalTable->addChild(functionTable);
                    globalTable->addFunction(Function($2,$1,std::vector<Parameters>()));
                }
              } list1 '}'
              {   
                for (const auto &var : variabile) 
                {
                    if (functionTable->getVariable(var.name)) 
                    {
                        yyerror("Variable already exists in the function scope.");
                    }
                    functionTable->addVariable(var);
                }
                variabile.clear();
                  
              }

           ;

list_param : param    {
                         $$=new Function();
                         $$->Param.push_back(*$1);
                      }
            | list_param ','  param {
                                    $$->Param.push_back(*$3);
                                    }
            ;        

param : TYPE ID {
                     Function* currentFunction = globalTable->getFunction(scope);
                     
                     if (currentFunction) 
                     {
                         for (const auto &parametru : currentFunction->Param) 
                         {
                             if (parametru.name == $2) 
                             {
                                 yyerror("Duplicate parameter name in the function.");
                             }
                         }
                     }
                     $$ = new Parameters($1, $2);
                };

           
list1: list1 statement1 ';' 
     | list1 IF '(' expr ')' { blockTable = new SymTable("block", currentTable);
                                    parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     } cont1
     | list1 WHILE '(' expr ')' '{' { blockTable = new SymTable("block", currentTable);
                                       parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     } list1 '}'  { currentTable=parentTable; }
     | list1 FOR '(' expr_for ')' '{' { blockTable = new SymTable("block", currentTable);
                                         parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     }list1 '}'  { currentTable=parentTable; }
     |
     ;

cont1: '{' list1 '}' { currentTable=parentTable; }
    |'{' list1 '}' ELSE '{' list1 '}' { currentTable=parentTable;}
;
statement1: declaration1
           |assignments1
;
declaration1: TYPE ID {   $$=new Variable($2,$1);
                           if(currentTable==functionTable)
                             variabile.push_back(*$$);
                           else
                             currentTable->addVariable(Variable($2,$1));

                          
                      }
;
assignments1:ID ASSIGN ID {    string val;
                               for (auto &var : variabile) 
                                    if(var.name==$3)
                                       val=var.value;
                                for (auto &var : variabile) 
                                     if(var.name==$1)
                                        var.value=val;
                            }
          |ID ASSIGN INT {   
                             for (auto &var : variabile) 
                                if(var.name==$1)
                                  {            
                                    $$=new Variable("",$1,to_string($3).c_str());
                                    var.value=$$->value;
                                  }
                                    
                        }
          |ID ASSIGN FLOAT {
                for (auto &var : variabile) 
                     if(var.name==$1)
                    {            
                         $$=new Variable("",$1,to_string($3).c_str());
                         var.value=$$->value;
                     }
          }
          |ID ASSIGN STRING {
            for (auto &var : variabile) 
                    if(var.name==$1)
                     {            
                         $$=new Variable("",$1,$3);
                         var.value=$$->value;
                    }
          }
          |ID ASSIGN CHAR{
            for (auto &var : variabile) 
                 if(var.name==$1)
                 {            
                     $$=new Variable("",$1,to_string($3).c_str());
                     var.value=$$->value;
                 }
          }
          |ID ASSIGN BOOL{
            for (auto &var : variabile) 
               if(var.name==$1)
                {   string val=to_string($3).c_str();
                    if(val=="1")
                         val="true";
                     if(val=="0")
                          val="false";
                                                    
                     $$=new Variable("",$1,val);
                     var.value=$$->value;
                                            
                 }
          }
           
          ;
          
expr: op GT op
    | op LT op
    | op GE op
    | op LE op
    | op EQ op
    | op NEQ op
    ;

expr_for: ID ASSIGN INT ';' ID LT INT ';' ID '+'
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == $1) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string($1) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
    | ID ASSIGN INT ';' ID LE INT ';' ID '+'
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == $1) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string($1) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
    | ID ASSIGN INT ';' ID GT INT ';' ID '-'
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == $1) 
            {  
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string($1) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
    | ID ASSIGN INT ';' ID GE INT ';' ID '-'
    {
        bool found = false;
        for (const auto &var : variabile) 
        {
            if (var.name == $1) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            string err = "Variable '" + string($1) + "' is not declared!";
            yyerror(err.c_str());
        }
    }
    ;


op : ID 
   | INT 
   | FLOAT 
   | BOOL
   ;

main : BGINMAIN  {
    
     mainTable = new SymTable("main", globalTable);
     globalTable->addChild(mainTable);
     globalTable->addFunction(Function("","main",std::vector<Parameters>()));
     currentTable=mainTable;
     } list ENDMAIN {
     for ( auto &var : global_variabile) 
       if(existsVarMain(var.name))
         mainTable->addVariable(var);
       variabile.clear();
       for (auto &var : global_variabile) 
         globalTable->updateValue(var,var.value);
      }

     ;
     
  

list: list statement ';' 
     | list IF '(' expr ')' { blockTable = new SymTable("block", currentTable);
                                    parentTable=currentTable;
                                     currentTable->addChild(blockTable);
                                     currentTable=blockTable;
     
     } cont
     | list WHILE '(' expression ')' '{' {   blockTable = new SymTable("block", currentTable);
                                       parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     } list '}'  { currentTable=parentTable; 
                 
                   if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                  {
                         yyerror("'while' accepts only boolean expressions");
                }}
     | list FOR '(' expr_for ')' '{' { blockTable = new SymTable("block", currentTable);
                                         parentTable=currentTable;
                                       currentTable->addChild(blockTable);
                                       currentTable=blockTable;
     
     }list '}'  { currentTable=parentTable; }
     |
     ;

cont: '{' list '}' { currentTable=parentTable;

                    if(ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                    {
                         yyerror("'if' accepts only boolean expressions");
                    } }
    |'{' list '}' ELSE '{' list '}' { currentTable=parentTable;
     
                                     if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                    {
                                            yyerror("'if' accepts only boolean expressions");
                                    }}
;
statement: declarations 
         | assignments
         | PRINT statement_print
         | TYPEOF statement_typeof
         |ID '(' list_param_call ')'{
             Function *func = globalTable->getFunction($1); 
            if (func == nullptr) {
                yyerror(("Undefined function: " + std::string($1)).c_str());
            } else {
                if (func->Param.size() != $3->Param.size()) {
                    yyerror(("Incorrect number of arguments for function: " + std::string($1)).c_str());
                } else {
                    for (size_t i = 0; i < func->Param.size(); ++i) {
                        if (func->Param[i].type != $3->Param[i].type) {
                            yyerror(("Argument type mismatch in function " + std::string($1) + " for parameter " + std::to_string(i+1) + ": expected " + func->Param[i].type + ", got " + $3->Param[i].type).c_str());
                        }
                    }
                }
            }
    
}
        
         ;

statement_print: print 
                    {
                        cout << ast.evaluateTree() << endl; ast.printTree(); 
                    }
                    ;
                     
statement_typeof: expression {  
                                cout << "TypeOf value: ";
                                string resultValue = ast.evaluateTree();

                                if (isInteger(resultValue)) {
                                    cout << "Integer" << endl;
                                } else if (isFloat(resultValue)) {
                                    cout << "Float" << endl;
                                } else if (isBoolean(resultValue)) {
                                    cout << "Boolean" << endl;
                                } else {
                                    cout << "Unknown" << endl;
                                }

                               ast.printTree();         
                             }
                             ;


list_param_call: list_param_call  ',' param_call{
                                    $$->Param.push_back(*$3);
                                    }
               | param_call {
                         $$=new Function();
                         $$->Param.push_back(*$1);
                      }
               ;

param_call: INT     { $$=new Parameters("int",""); 
                  }
          | FLOAT  { $$=new Parameters("float",""); 
          }
          | BOOL  { $$=new Parameters("bool",""); 
           }
          | ID      {  bool ok; string type;
                      for (auto &var : global_variabile) 
                          if(var.name==$1)
                            { ok=1; type=var.type; }
                     if(ok==0)
                        {string err="Variable '"+string($1)+"' was not declared!"; yyerror(err.c_str());}
                     else
                        {$$=new Parameters(type,$1); }       
                    }
          ;

declarations:TYPE ID {   
                        if(existsVar($2)==0)   
                            {   
                            if(currentTable==mainTable)
                             { $$=new Variable($2,$1);
                               variabile.push_back(*$$);
                               global_variabile.push_back(*$$); }
                             else
                               currentTable->addVariable(Variable($2,$1));
                            }
                        else {
                              string err="Variable '"+string($2)+"' was already declared ";
                             yyerror(err.c_str());}
                     }                   
            | TYPE ID '[' INT ']' ASSIGN '{' array_list '}' 
                            {
                                char* token = strtok($8, " ");
                                int index = 0;
                                while (token != NULL) 
                                    {
                                        if (token[0] != '\0') 
                                            {
                                             
                                                $$=new Variable((string($2) + "[" + to_string(index) + "]").c_str(),$1);
                                                variabile.push_back(*$$);
                                                global_variabile.push_back(*$$);
                                                index++;
                                                if(index>$4)
                                                    {   
                                                        string err="Array's '"+string($2)+"' max size is: "+to_string($4);
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        token = strtok(NULL, " ");
                                    }
                            }
                            ;

array_list : array_list ',' INT 
                {
                        $$ = (char*)malloc(strlen($1) + strlen(to_string($3).c_str()) + 2); 
                        strcpy($$, $1);
                        strcat($$, to_string($3).c_str());
                        strcat($$, " ");
                }
            | array_list ',' FLOAT 
                {
                        $$ = (char*)malloc(strlen($1) + strlen(to_string($3).c_str()) + 2); 
                        strcpy($$, $1);
                        strcat($$, to_string($3).c_str());
                        strcat($$, " ");
                }
            | INT 
                {
                    $$ = strdup(to_string($1).c_str()); 
                    strcat($$, " ");
                }
            | FLOAT 
                {
                    $$ = strdup(to_string($1).c_str()); 
                    strcat($$, " ");
                }
            ;

assignments : ID ASSIGN '(' expression ')' { 
              
              if(!existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
              else if(TypeOf($1)!=ast.getroot()->type) 
                                    {   
                                        string err="Variables '"+string($1)+"' and '"+ast.getroot()->type+"' have different types";    
                                        yyerror(err.c_str());
                                    }
               else{    
                  for (auto &var : global_variabile) 
                  if(var.name==$1)
                  {
                      $$=new Variable("",$1,ast.evaluateTree().c_str());
                     var.value=$$->value;
                  }
                }

            }
             |ID '[' INT ']' ASSIGN '(' expression ')' { 
               string id=string($1)+"["+to_string($3)+"]";
              if(!existsVar(id.c_str()))
                                    { 
                                        string err="Variable '"+string(id.c_str())+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
              else if(TypeOf(id.c_str())!=ast.getroot()->type) 
                                    {   
                                        string err="Variables '"+string(id.c_str())+"' and '"+ast.getroot()->type+"' have different types";    
                                        yyerror(err.c_str());
                                    }
               else{    
                  for (auto &var : global_variabile) 
                  if(var.name==id)
                  {
                      $$=new Variable("",$1,ast.evaluateTree().c_str());
                     var.value=$$->value;
                  }
                }

            }
             |ID ASSIGN ID
                        {    
                              if(!existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(!existsVar($3))
                                    { 
                                        string err="Variable '"+string($3)+"' was not declared ";   
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf($1)!=TypeOf($3)) 
                                    {   
                                        string err="Variables '"+string($1)+"' and '"+string($3)+"' have different types";    
                                        yyerror(err.c_str());
                                    }
                              else  { 
                                        string val=getValue($3);
                                        
                                        for (auto &var : global_variabile) 
                                            if(var.name==$3)
                                              val=var.value;
                                        for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                            var.value=val;

                                        

                                    }     
                        }
                |ID ASSIGN INT 
                        { 
                              if(!existsVar($1))
                                    {
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf($1)!="int")
                                    {
                                        string err="Cannot assign 'int' to an '"+TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       

                                        for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                            {
                                                  $$=new Variable("",$1,to_string($3).c_str());
                                                  var.value=$$->value;
                                             }
                                        
                                            
                                    }             
                        } 
           |ID ASSIGN FLOAT     
                        { 
                              if(!existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf($1)!="float")
                                    {
                                        string err="Cannot assign 'float' to an '"+TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       
                                        for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                           {
                                              $$=new Variable("",$1,to_string($3).c_str());
                                              var.value=$$->value;
                                           }
                                    }             
                        }
           |ID ASSIGN BOOL 
                        {   
                              if(!existsVar($1))
                                    {
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                             else if(TypeOf($1)!="bool")
                                    {
                                        string err="Cannot assign 'bool' to an'"+TypeOf($1)+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                       
                                       for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                           {   string val=to_string($3).c_str();
                                               if(val=="1")
                                                  val="true";
                                                if(val=="0")
                                                  val="false";
                                                    
                                               $$=new Variable("",$1,val);
                                               var.value=$$->value;
                                            
                                            }
                                    }             
                        }
           |ID ASSIGN CHAR 
                        { 
                              if(!existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf($1)!="char")
                                    {
                                        string err="Cannot assign 'char' to an '"+TypeOf($1)+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        string str(1,$3);
                                         for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                           {
                                              $$=new Variable("",$1,to_string($3).c_str());
                                              var.value=$$->value;
                                           }
                                    }             
                        }
           |ID ASSIGN STRING 
                        {   
                              if(!existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(TypeOf($1)!="string")
                                    {
                                        string err="Cannot assign 'string' to an'"+TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                      
                                        for (auto &var : global_variabile) 
                                          if(var.name==$1)
                                            var.value=$3;
                                    }             
                        }
           |ID '[' INT ']' ASSIGN INT  
                        {
                              string id=string($1)+"["+to_string($3)+"]";
                              if(!existsVar(id.c_str()))
                                    {
                                         string err="Variable '"+ string(id.c_str())+"' was not declared ";
                                         yyerror(err.c_str());
                                    }
                              else if(TypeOf(id.c_str())!="int")
                                    {
                                         string err="Cannot assign 'int' to an '"+TypeOf(id.c_str())+"'";
                                         yyerror(err.c_str());
                                    }
                              else  {
                                        
                                           for (auto &var :global_variabile) 
                                             if(var.name==id)
                                               var.value=to_string($6).c_str();
                                         
                                    }
                        }
           | CONST TYPE ID 
                    { yyerror("Constant must have value assigned at declaration!");}
           | CONST TYPE ID ASSIGN INT 
                                    {   
                                         if(!existsVar($3))   
                                             {        
                                                if(strcmp($2,"int")==0)
                                                    {    string type=$2;
                                                       
                                                         $$=new Variable($3,type,to_string($5).c_str());
                                                         $$->constanta="const";
                                                         variabile.push_back(*$$);
                                                         global_variabile.push_back(*$$);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type int"; 
                                                        yyerror(err.c_str());
                                                    }
                                             }                    
                                         else 
                                             {  
                                                yyerror("variable already declared");
                                             }
                                    }
          | CONST TYPE ID ASSIGN FLOAT 
                                    {   
                                        if(!existsVar($3))   
                                            {   
                                                if(strcmp($2,"float")==0)
                                                    {
                                                       
                                                         string type=string("const ")+$2;
                                                         $$=new Variable($3,type,to_string($5).c_str());
                                                         variabile.push_back(*$$);
                                                          global_variabile.push_back(*$$);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($2) + " has type " + $2 + ", assigned value has type float"; 
                                                        yyerror(err.c_str());
                                                    }
                                            }                    
                                        else 
                                            {  
                                                yyerror("variable already declared");
                                            }    

                                    }
          |CONST TYPE ID ASSIGN BOOL 
                                    { 
                                        if (!existsVar($3)) 
                                            {
                                                if (strcmp($2, "bool") == 0) 
                                                    {
                                                      
                                                         string type=string("const ")+$2;
                                                         $$=new Variable($3,type,to_string($5).c_str());
                                                         variabile.push_back(*$$);
                                                           global_variabile.push_back(*$$);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type bool";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
          |CONST TYPE ID ASSIGN CHAR 
                                    {
                                        if (!existsVar($3)) 
                                            {
                                                if (strcmp($2, "char") == 0) 
                                                    {
                                                        string str(1,$5);
                                                
                                                         string type=string("const ")+$2;
                                                         $$=new Variable($3,type,to_string($5).c_str());
                                                         variabile.push_back(*$$);
                                                        global_variabile.push_back(*$$);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type char";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
          |CONST TYPE ID ASSIGN STRING
                                    {
                                        if (!existsVar($3)) 
                                            {
                                                if (strcmp($2, "string") == 0) 
                                                    {
                                                      
                                                         string type=string("const ")+$2;
                                                   
                                                         $$=new Variable($3,type,$5);
                                                         variabile.push_back(*$$);
                                                        global_variabile.push_back(*$$);
                                                    } 
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type string";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }                                            
                                    }           
                                    ;


print :'(' expression ')'   
        {
           $$ = $2;  
        }
        ;
expression : expression '+' expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' + '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "+",$1->type }; 
                        ast.AddNode("+",$1,$3,$1->type);
                    }
           | expression '-' expression  
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type) 
                            {
                                string err="Operands have different types! '"+$1->type+"' - '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "-",$1->type }; 
                        ast.AddNode("-",$1,$3,$1->type);
                    }
           | expression '*' expression  
                    { 
                        if($1->type=="bool"||$3->type=="bool")  
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' * '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "*",$1->type }; 
                        ast.AddNode("*",$1,$3,$1->type);
                    }
           | expression '/' expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {   
                                string err="Operands have different types! '"+$1->type+"' / '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "/",$1->type }; 
                        ast.AddNode("/",$1,$3,$1->type);}
           | expression '^' expression 
                   { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' ^ '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node{$1, $3, "^",$1->type}; 
                        ast.AddNode("^",$1,$3,$1->type);
                    }
           | expression AND expression
                   {
                        if($1->type=="int"||$1->type=="float"||$3->type=="int"||$3->type=="float")
                            {
                                string err="Operation && only supports bool operands ! '"+$1->type+"' && '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3,"&&",$1->type}; 
                            ast.AddNode("&&",$1,$3,$1->type);
                    }
           | expression OR expression
                   {
                         if($1->type=="int"||$1->type=="float"||$3->type=="int"||$3->type=="float")
                            {
                                string err="Operation || only supports bool operands ! '"+$1->type+"' || '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3,"||",$1->type}; 
                            ast.AddNode("||",$1,$3,$1->type);
                    }
           | NOT expression
                    {
                        if($2->type=="int"||$2->type=="float")
                            {
                                string err="Operation ! only supports bool operand! !'"+$2->type+"''";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$2, NULL,"!",$2->type}; 
                            ast.AddNode("!",$2,NULL,$2->type); }
           | expression LT expression
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            { 
                                string err="Operands have different types! '"+$1->type+"' < '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3, "<","bool"}; 
                            ast.AddNode("<",$1,$3,"bool");}
           | expression LE expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' <= '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3, "<=","bool"}; 
                            ast.AddNode("<=",$1,$3,"bool");}
           | expression GT expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' > '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, ">","bool"}; 
                        ast.AddNode(">",$1,$3,"bool");}
           | expression GE expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' >= '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, ">=","bool"}; 
                        ast.AddNode(">=",$1,$3,"bool");}
           | expression EQ expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' == '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, "==","bool"}; 
                        ast.AddNode("==",$1,$3,"bool");
                    }
           | expression NEQ expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' != '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, "!=","bool"}; 
                        ast.AddNode("!=",$1,$3,"bool");}
           | '(' expression ')'
                        {
                            $$=$2;
                        }
           | INT   
                        { 
                            $$ = new Node{NULL, NULL, to_string($1),"int"}; 
                            ast.AddNode(to_string($1),NULL,NULL,"int");
                        }
           | FLOAT 
                        {
                            $$=new Node{NULL,NULL,to_string($1),"float"};
                            ast.AddNode(to_string($1),NULL,NULL,"float");
                        }
           | BOOL      
                        {
                            $$=new Node{NULL,NULL,$1?"true":"false","bool"};
                            ast.AddNode($1?"true":"false",NULL,NULL,"bool");
                        }
           | STRING    
                        {
                             $$=new Node{NULL,NULL,$1,"string"};
                             ast.AddNode($1,NULL,NULL,"string");
                        }
           | ID
                        {
                        if(!existsVar($1))
                            {
                                string err="Variable '"+string($1)+"' was not declared!";
                                yyerror(err.c_str());
                            }
                        $$=new Node{NULL,NULL,getValue($1),TypeOf($1)}; 
                        ast.AddNode(getValue($1),NULL,NULL,TypeOf($1));
                        }
            
           ;




%%

void yyerror(const char * s)
    {
        printf("error: %s line:%d\n",s,yylineno);
    }  

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
} 