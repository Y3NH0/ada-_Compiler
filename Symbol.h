#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*
-------------------------
----- type category -----
-------------------------

1. Special
    ERROR       |   error
    NON		    |	non
-----------------------------------------------
2. Variable
    VAR_INT		|	variable int
    VAR_FLOAT	|	variable float
    VAR_STRING	|	variable string
    VAR_BOOL	|	variable bool
-----------------------------------------------
3. Constant
    CON_INT		|	constant int
    CON_FLOAT	|	constant float
    CON_STRING	|	constant string
    CON_BOOL	|	constant bool
-----------------------------------------------
4. Array
    ARR_INT		|	int array
    ARR_FLOAT	|	float array
    ARR_STRING	|	string array
    ARR_BOOL	|	bool array
-----------------------------------------------
5. Procedure
    PROC_INT	|	int procedure
    PROC_FLOAT	|	float procedure
    PROC_STRING	|	string procedure
    PROC_BOOL	|	bool procedure
    PROC_NON	|	non procedure

*/
class Symbol {
    public:
        Symbol();
        Symbol(string, string);

    // member variable
        string name;
        string type;
        vector<string> argumentType;

    // proj3 Java bytecode
        string loadCode;
        string storeCode;
};

class SymbolTable {
    public:
        SymbolTable();
        SymbolTable(string);
        SymbolTable(string, SymbolTable*);
        Symbol* Lookup_Global(string);
        Symbol* Lookup_Local(string);
        void insert(string, string);
        void dump();

    // member variable
        vector<Symbol*> table;
        SymbolTable *parentTable;
        string name;
        string returnType;

    // for proj3
        int IndexCounter;
};
#endif //SYMBOL_H