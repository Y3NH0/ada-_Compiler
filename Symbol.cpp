#include "Symbol.h"

/*--- Symbol ---*/
Symbol::Symbol() {
    this->name = "";
    this->type = "NON";
    this->argumentType.clear();
    this->loadCode = "";
    this->storeCode = "";
}

Symbol::Symbol(string name, string type) {
    this->name = name;
    this->type = type;
    this->argumentType.clear();
    this->loadCode = "";
    this->storeCode = "";
}



/*--- SymbolTable ---*/

SymbolTable::SymbolTable() {
    this->name = "";
    this->table.clear();
	this->parentTable = NULL;
    this->returnType = "NON";
    this->IndexCounter = 0;
}

SymbolTable::SymbolTable(string name) {
    this->name = name;
    this->table.clear();
	this->parentTable = NULL;
    this->returnType = "NON";
    this->IndexCounter = 0;
}

SymbolTable::SymbolTable(string name, SymbolTable *parentTable) {
    this->name = name;
    this->table.clear();
	this->parentTable = parentTable;
    this->returnType = "NON";
    this->IndexCounter = 0;
}

/*--- Lookup_Global ---*/
// search all SymbolTable
// if currentTable not found 
//    => let currentTable = its parent
// until found => return Symbol
// or not found => return NULL
Symbol* SymbolTable::Lookup_Global(string name) {
    SymbolTable *currentTable = this;
    if(currentTable == NULL) return NULL;
    while(currentTable != NULL) {
        // search this scope
        for(int i = 0; i < currentTable->table.size(); i++) {
            if(currentTable->table.at(i)->name == name) {
                return currentTable->table.at(i);
            }
        }
        // search next scope
        currentTable = currentTable->parentTable; 
    }
    return NULL;
}


/*--- Lookup_Local ---*/
// only search "this" SymbolTable
// until found => return Symbol
// or not found => return NULL
Symbol* SymbolTable::Lookup_Local(string name) {
    SymbolTable *currentTable = this;
    if(currentTable == NULL) return NULL;
    for(int i=0;i<currentTable->table.size();++i) {
        if(currentTable->table.at(i)->name == name) {
            return currentTable->table.at(i);
        }
    }
    return NULL;
}

/*--- Insert ---*/
// insert a symbol to this SymbolTable
void SymbolTable::insert(string name, string type) {
    this->table.push_back(new Symbol(name, type));
}

/*--- Dump ---*/
void SymbolTable::dump(){
    cout << "scope:\t" << this->name << endl;
	for (int i = 0; i < this->table.size(); i++) {
		cout << "num:\t" << i << "\t" << this->table.at(i)->name << "\t" << this->table.at(i)->type << endl;
	}
}
