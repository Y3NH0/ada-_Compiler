%{
/*---------------------------------------*/
/*--------------- Parser ----------------*/
/*---------------------------------------*/
#include "lex.yy.c"
#include <fstream>
#include <stack>
#define Trace(t) cout << t << endl

using namespace std;

void yyerror(string t);


// e.g.
// T = "VAR_INT", VorC = "CON"
// return "CON_INT"
string changeVarCon(string T,string VorC){
    if(VorC.length()!=3){
        cout << "changeVarCon error" << endl;
        return T;
    }
    string temp(T);
    temp[0] = VorC[0];
    temp[1] = VorC[1];
    temp[2] = VorC[2];
    return temp;
}

SymbolTable *scope;
Symbol *symbol;

// for syntax
bool flag;
vector<string> parameter;


// for branch (e.g. goto L1 goto L2)
int branchIndex; 
stack<int> branchStack;
bool elseBranch = false;

// for file
string fileName = "";
string jasmName = "";
ofstream fout;

void fileWrite(ofstream &f, string s){
    f << s << endl;
}


// for store val 
int int_value = 0; 
float float_value = 0.0; 
string string_value = "";  
bool bool_value = false;

void clear_val() {     
    int_value = 0; 
    float_value = 0.0; 
    string_value = "";  
    bool_value = false;
}

%}

/*--- tokens ---*/
%token COM COL PER SEM PAR_L PAR_R SBRA_L SBRA_R LOOPDOT
%token ADD SUB MUL DIV REM ASS AND OR NOT
%token LE LEEQ GREQ GR EQ NEQ
%token BEGIN_TOKEN BOOLEAN BREAK CHARACTER CASE CONTINUE CONSTANT DECLARE DO ELSE END EXIT FLOAT FOR IF IN INTEGER LOOP PRINT PRINTLN PROCEDURE PROGRAM RETURN STRING WHILE THEN READ TRUE FALSE

%union {
    int intVal;
    float floatVal;
    char* stringVal;
    bool boolVal;
}

%token <intVal> INT_VAL
%token <floatVal> FLOAT_VAL
%token <stringVal> STRING_VAL
%token <boolVal> BOOL_VAL
%type <boolVal> bool_val
%token <stringVal> ID

%type <stringVal> type constant_expression expression array_reference function_invocation


%left OR
%left AND
%left NOT
%left LE LEEQ GR GREQ EQ NEQ
%left ADD SUB
%left MUL DIV REM
%nonassoc UMINUS

%start ada


%%

EMPTY: ;

type: 
        INTEGER { $$ = (char*)"VAR_INT"; }
    |   STRING  { $$ = (char*)"VAR_STRING";}
    |   BOOLEAN { $$ = (char*)"VAR_BOOL";} 
    |   FLOAT   { $$ = (char*)"VAR_FLOAT";}
    ;

opt_SEM: 
        EMPTY
    |   SEM
    ;
ada:    
    PROGRAM ID  
    { 
        /* new a SymbolTable and its scope name is string($2) */
        scope = new SymbolTable(string($2)); 

    // java
        fileWrite(fout,"class " + string($2));
        fileWrite(fout,"{");

        
    } 
    var_d_block
    proc_d_blocks
    main_block
    END ID opt_SEM
    {
        if(strcmp($2, $8)!=0){
            yyerror("Program ID not the same.");
        }

        SymbolTable *trash = scope;
        scope = scope->parentTable;
        delete trash;
    
    // java
        fileWrite(fout,"}");
    }
    ;

//-- variable declaration block
var_d_block:
                EMPTY
            |   DECLARE var_d_stats
            ;

var_d_stats:
            var_d_stat
        |   var_d_stat var_d_stats
        ;

var_d_stat:
            var_d 
        |   const_d
        |   array_d
        ;

var_d:
        ID COL type SEM 
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1), string($3));
            }
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string($1));
            if(symbol == NULL){
                yyerror("error: " + string($1) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    if (symbol->type == "VAR_BOOL") {
                    // be used
                        symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                        symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                    // declare
                        fileWrite(fout, "field static int " + symbol->name);
                    }
                    else if(symbol->type == "VAR_INT") {
                        symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                        symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                        fileWrite(fout, "field static int " + symbol->name);
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                }
                else{
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            // true -> 1, false -> 0
		            		fileWrite(fout,"iconst_1");
		            	}
		            	else {
		            		fileWrite(fout,"iconst_0");
		            	}
		            	fileWrite(fout,symbol->storeCode);
		            	clear_val();
		            }
		            else if (symbol->type == "VAR_INT") {
                        // local push to local array
		            	fileWrite(fout, "sipush " + to_string(int_value));
			            fileWrite(fout,symbol->storeCode);
		            	clear_val();
	            	}
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                }
        // java end
            }
        }
    |   ID ASS constant_expression SEM
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1), string($3));
            } 
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string($1));
            if(symbol == NULL){
                yyerror("error: " + string($1) + " not found.");
            }
            else {
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "field static int " + symbol->name + " = 1");
                        } 
                        else {
                            fileWrite(fout, "field static int " + symbol->name + " = 0");
                        }
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "field static int " + symbol->name + " = " + to_string(int_value));
                        clear_val();
                    }
                    else{
                        // type not int or bool
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                    
                }
                else {
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                    
                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "iconst_1");
                        } 
                        else {
                            fileWrite(fout, "iconst_0");
                        }
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "sipush " + to_string(int_value));
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }

                }
            }
        // java end
        }
    |   ID COL type ASS constant_expression SEM
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1), string($3));
                if (string($3) != string($5)) {
                    yyerror("type error: not the same.");
                }
            } 
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }

        // Java 
            symbol = scope->Lookup_Local(string($1));
            if(symbol == NULL){
                yyerror("error: " + string($1) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;

                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "field static int " + symbol->name + " = 1");
                        } 
                        else {
                            fileWrite(fout, "field static int " + symbol->name + " = 0");
                        }
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "field static int " + symbol->name + " = " + to_string(int_value));
                        clear_val();
                    }
                    else{
                        // type not int or bool
                        yyerror("error: only integer and boolean variable in proj3.");
                    }
                    
                }
                else {
                    // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                    
                    if (symbol->type == "VAR_BOOL") {
                        if (bool_value) {
                            fileWrite(fout, "iconst_1");
                        } 
                        else {
                            fileWrite(fout, "iconst_0");
                        }
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    } 
                    else if (symbol->type == "VAR_INT") {
                        fileWrite(fout, "sipush " + to_string(int_value));
                        fileWrite(fout, symbol->storeCode);
                        clear_val();
                    }
                    else {
                        yyerror("error: only integer and boolean variable in proj3.");
                    }

                }
            }
        // java end
        }
    |   ID SEM
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1),"NON");
            } 
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string($1));
            if(symbol == NULL){
                yyerror("error: " + string($1) + " not found.");
            }
            else{
                if(scope->parentTable == NULL){
                // global scope
                    symbol->loadCode = "getstatic int " + scope->name + "." + symbol->name;
                    symbol->storeCode = "putstatic int " + scope->name + "." + symbol->name;
                    fileWrite(fout, "field static int " + symbol->name);
                }
                else{
                // local scope
                    symbol->loadCode = "iload " + to_string(scope->IndexCounter);
                    symbol->storeCode = "istore " + to_string(scope->IndexCounter);
                    scope->IndexCounter++;
                }
            }
        }
    ;

const_d:
        ID COL CONSTANT COL type ASS constant_expression SEM
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1), changeVarCon(string($5),"CON"));
                if (string($5) != string($7)) {
                // if type != CON_expr.type
                    yyerror("type error: not the same.");
                }
            } 
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }

        // java
            symbol = scope->Lookup_Local(string($1));
            if (symbol == NULL) {
                yyerror("error: " + string($1) + " not found.");
            }
            else {
                if (symbol->type == "CON_BOOL") {
                    if (bool_value) {
                        symbol->loadCode = "iconst_1";
                    } 
                    else {
                        symbol->loadCode = "iconst_0";
                    }
                    clear_val();
                } 
                else if (symbol->type == "CON_INT") {
                    symbol->loadCode = "sipush " + to_string(int_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_FLOAT") {
                    symbol->loadCode = "sipush " + to_string(float_value);
                    clear_val();
                }
                else if (symbol->type == "CON_STRING") {
                    symbol->loadCode = "ldc \"" + string_value + "\"";
                    clear_val();
                } 
                else {
                    yyerror("type error: should be CON_*.");
                }
            }
        // java end
        }
    |   ID COL CONSTANT ASS constant_expression SEM
        {
            if (scope->Lookup_Local(string($1)) == NULL) {
                scope->insert(string($1),changeVarCon(string($5),"CON"));
            } 
            else {
                yyerror("\'" + string(string($1)) + "\' had been declared.");
            }
        // java
            symbol = scope->Lookup_Local(string($1));
            if (symbol == NULL) {
                yyerror("error: " + string($1) + " not found.");
            }
            else {
                if (symbol->type == "CON_BOOL") {
                    if (bool_value) {
                        symbol->loadCode = "iconst_1";
                    } 
                    else {
                        symbol->loadCode = "iconst_0";
                    }
                    clear_val();
                } 
                else if (symbol->type == "CON_INT") {
                    symbol->loadCode = "sipush " + to_string(int_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_FLOAT") {
                    symbol->loadCode = "sipush " + to_string(float_value);
                    clear_val();
                } 
                else if (symbol->type == "CON_STRING") {
                    symbol->loadCode = "ldc \"" + string_value + "\"";
                    clear_val();
                } 
                else {
                    yyerror("type error: should be CON_*.");
                }
            }
        // java end
        }
    ;
array_d:
        ID COL type SBRA_L INT_VAL SBRA_R SEM
        { yyerror("no array in proj3."); }
        ;

constant_expression:
        INT_VAL     { $$ = (char*)"VAR_INT"; int_value = $1;}
    |   STRING_VAL  { $$ = (char*)"VAR_STRING"; string_value = $1;}
    |   bool_val    { $$ = (char*)"VAR_BOOL"; bool_value = $1;}
    |   FLOAT_VAL   { $$ = (char*)"VAR_STRING"; float_value = $1;}
    ;

//-- procedure block
proc_d_blocks:
        EMPTY
    |   proc_d_block proc_d_blocks
    ;

proc_d_block:
        PROCEDURE ID 
        {
            if (scope->Lookup_Local(string($2)) == NULL) {
                flag = true;
                scope->insert(string($2), "PROC_NON");
                symbol = scope->Lookup_Local(string($2));
                SymbolTable *child = new SymbolTable(string($2), scope);
                scope = child;
                
            } 
            else {
                flag = false;
                yyerror("\'" + string(string($2)) + "\' had been declared.");
            }

        }
        formal_arguments
        return_type
        {
        // java
            // procedure -> method
            string str_temp("method public static ");
            string str_temp2("invokestatic ");
            char c_temp = scope->returnType[5];
            
            if(c_temp == 'N'){
                str_temp += "void ";
                str_temp2 += "void";
            }
            else if(c_temp == 'I'){
                str_temp += "int ";
                str_temp2 += "int ";
            }
            else if(c_temp == 'F'){
                str_temp += "float ";
                str_temp2 += "float ";
            }
            else if(c_temp == 'S'){
                str_temp += "string ";
                str_temp2 += "string ";
            }
            else if(c_temp == 'B'){
                str_temp += "bool ";
                str_temp2 += "bool ";
            }

            str_temp += string($2);
            str_temp += "(";

            str_temp2 += scope->parentTable->name;
            str_temp2 += ".";
            str_temp2 += string($2);
            str_temp2 += "(";
            
            for(int i=0;i<symbol->argumentType.size();i++){
                //cout << symbol->argumentType[i]<<endl;
                if(i>=1) {
                    str_temp+=", ";
                    str_temp2+=", ";    
                }
                if(symbol->argumentType[i][4] == 'I'){
                    str_temp+="int";
                    str_temp2+="int";
                }
                else if(symbol->argumentType[i][4] == 'B'){
                    str_temp+="bool";
                    str_temp2+="bool";
                }
                else if(symbol->argumentType[i][4] == 'S'){
                    str_temp+="string";
                    str_temp2+="string";
                }
                else if(symbol->argumentType[i][4] == 'C'){
                    str_temp+="char";
                    str_temp2+="char";
                }
            }
            str_temp+=")";
            str_temp2+=")";
            
            symbol->loadCode = str_temp2;
            fileWrite(fout,str_temp);
            fileWrite(fout,"max_stack 15");
            fileWrite(fout,"max_locals 15");
            fileWrite(fout,"{");
            str_temp = "";
            str_temp2 = "";
        // java end
        }
        block_in_proc
        END ID opt_SEM
        {   
            if(scope->returnType == "PROC_NON") fileWrite(fout,"return");
            fileWrite(fout,"}");
            if(strcmp($2,$9)!=0){
                yyerror("procedure ID not the same");
            }
            { 
                SymbolTable *trash = scope;
                scope = scope->parentTable;
                delete trash;  
            }
        }
    ;

formal_arguments: 
        EMPTY
    |   PAR_L arguments PAR_R
    ;
arguments:
        argument
    |   argument SEM arguments
    ;
argument:
        ID COL type
        {
            if(flag){
                symbol->argumentType.push_back(string($3));
            }
            scope->insert(string($1),string($3));

        // java
	        if (scope->Lookup_Global(string($1)) != NULL) {
		        scope->Lookup_Global(string($1))->loadCode = "iload " + to_string(scope->IndexCounter);
		        scope->Lookup_Global(string($1))->storeCode = "istore " + to_string(scope->IndexCounter);
		        scope->IndexCounter++;
	        }
            else {
                yyerror( string($1) + " not found.");
            }
        // java end
        }
    ;

return_type:
        EMPTY 
        { scope->returnType = "PROC_NON"; }
    |   RETURN type
        {
            /* if procedure successfully declared flag is true */
            if(flag){
                if(string($2) == "VAR_INT"){
                    symbol->type = "PROC_INT";
                    scope->returnType = "PROC_INT";
                }
                else if(string($2) == "VAR_FLOAT"){
                    symbol->type = "PROC_FLOAT";
                    scope->returnType = "PROC_FLOAT";
                }
                else if(string($2) == "VAR_STRING"){
                    symbol->type = "PROC_STRING";
                    scope->returnType = "PROC_STRING";
                }
                else if(string($2) == "VAR_BOOL"){
                    symbol->type = "PROC_BOOL";
                    scope->returnType = "PROC_BOOL";
                }
            }
            
        }   
    ;

block_in_proc:
        var_d_block
        BEGIN_TOKEN
        statements
        END SEM
        ;

// main_block in Ada Program
main_block:
        BEGIN_TOKEN
        {
            fileWrite(fout,"method public static void main(java.lang.String[])");
            fileWrite(fout,"max_stack 15");
            fileWrite(fout,"max_locals 15");
            fileWrite(fout,"{");
        }
        statements
        END SEM
        {
            fileWrite(fout,"return");
            fileWrite(fout,"}");
        }
        ;

//-- statements
statements:
        EMPTY
    |   statement statements
    ;
statement:
        simple_stmt
    |   conditional_stmt
    |   procedure_invocation
    |   while_loop
    |   for_loop
    ;

simple_stmt:
        ID ASS expression SEM
        {
            symbol = scope->Lookup_Global(string($1));
            /*if ID found*/
            if (symbol != NULL) {
                if (symbol->type == "NON") {
                    symbol->type = string($3);
                //Java
                    fileWrite(fout, symbol->storeCode);
                //Java end
                } 
                else if (symbol->type == "VAR_INT" ||  symbol->type == "VAR_FLOAT"  
                    || symbol->type == "VAR_STRING" ||  symbol->type == "VAR_BOOL" ) {
                    if(symbol->type != string($3)){
                        yyerror("type error: not the same.");   
                    }
                //Java
                    fileWrite(fout, symbol->storeCode);
                //Java end
                }
                else{
                    yyerror(string($1) + "not variable.");   
                }
            }
            else {
            /*ID not found*/
                yyerror("\'" + string($1) + "\' not declared.");
            }
        }
    |   ID SBRA_L integer_expression SBRA_R ASS expression SEM
        {
            yyerror("no array in proj3.");
        }
    |   PRINT { /* java */ fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
        PAR_L expression PAR_R SEM
        {
            if (string($4) == "ERROR" || string($4) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string($4) == "VAR_INT" || string($4) == "CON_INT" || string($4) == "PROC_INT"
            || string($4) == "VAR_BOOL" || string($4) == "CON_BOOL" || string($4) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string($4) == "VAR_STRING" || string($4) == "CON_STRING" || string($4) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }
        }
    |   PRINT { /* java */ fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
        expression SEM
        {
            if (string($3) == "ERROR" || string($3) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string($3) == "VAR_INT" || string($3) == "CON_INT" || string($3) == "PROC_INT"
            || string($3) == "VAR_BOOL" || string($3) == "CON_BOOL" || string($3) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string($3) == "VAR_STRING" || string($3) == "CON_STRING" || string($3) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }                                                              
        }
    |   PRINTLN { fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
        PAR_L expression PAR_R SEM
        {
            if (string($4) == "ERROR" || string($4) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string($4) == "VAR_INT" || string($4) == "CON_INT" || string($4) == "PROC_INT"
            || string($4) == "VAR_BOOL" || string($4) == "CON_BOOL" || string($4) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string($4) == "VAR_STRING" || string($4) == "CON_STRING" || string($4) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            }
        }
    |   PRINTLN { fileWrite(fout, "getstatic java.io.PrintStream java.lang.System.out"); }
        expression SEM
        {
            if (string($3) == "ERROR" || string($3) == "NON") {
                yyerror("type error: can not print this type.");
            }
            else if(string($3) == "VAR_INT" || string($3) == "CON_INT" || string($3) == "PROC_INT"
            || string($3) == "VAR_BOOL" || string($3) == "CON_BOOL" || string($3) == "PROC_BOOL") {
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(int)");        
            // java end
            }
            else if(string($3) == "VAR_STRING" || string($3) == "CON_STRING" || string($3) == "PROC_STRING"){
            // java
                fileWrite(fout, "invokevirtual void java.io.PrintStream.print(java.lang.String)");
            // java end
            } 
        }
    |   READ ID SEM
        {
            yyerror("no READ in proj3.");
        }
    |   RETURN SEM
        {
            fileWrite(fout,"return");

            SymbolTable *temp = scope;
            while(temp->returnType == "NON") {
                if (temp->parentTable == NULL) {
                    break;
                }
                temp = temp->parentTable;
            }
            

            if(temp->returnType != "PROC_NON") {
            /* => it need to return something*/
                if(temp->returnType == "PROC_INT"
                || temp->returnType == "PROC_FLOAT"
                || temp->returnType == "PROC_STRING"
                || temp->returnType == "PROC_BOOL") {
                    yyerror(temp->name + " need return value.");
                } 
                else {
                    yyerror("syntax error: return in this scope is illegal.");
                }
            }
        }
    |   RETURN expression SEM
        {
            fileWrite(fout, "ireturn");

            SymbolTable *temp = scope;
            while(temp->returnType == "NON") {
                if (temp->parentTable == NULL) {
                    break;
                }
                temp = temp->parentTable;
            }

            if(temp->returnType != "PROC_NON") {
                if(temp->returnType == "PROC_INT"
                || temp->returnType == "PROC_FLOAT"
                || temp->returnType == "PROC_STRING"
                || temp->returnType == "PROC_BOOL") {
                    if(temp->returnType == "PROC_INT"){
                        if(string($2) != "VAR_INT"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_FLOAT"){
                        if(string($2) != "VAR_FLOAT"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_STRING"){
                        if(string($2) != "VAR_STRING"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                    else if(temp->returnType == "PROC_BOOL"){
                        if(string($2) != "VAR_BOOL"){
                            yyerror("type error: procedure return type and the expression are not the same.");
                        }
                    }
                } 
                else {
                    if(temp->returnType == "PROC_NON") {
                        yyerror("syntax error: it doesnt need to return.");
                    } 
                    else {
                        yyerror("syntax error: return in this scope is illegal.");
                    }
                }
            }
        }
    ;

function_invocation:
        ID PAR_L { parameter.clear(); } comma_separated_expressions PAR_R
        {
            symbol=scope->Lookup_Global(string($1));
            if(symbol == NULL){
                $$ = (char*)"ERROR";
                yyerror(string(string($1)) + " not declared.");
            }
            else{
            // java
                fileWrite(fout,symbol->loadCode);

                if(symbol->type == "PROC_INT" 
                || symbol->type == "PROC_FLOAT" 
                || symbol->type == "PROC_STRING" 
                || symbol->type == "PROC_BOOL"){ 
                    if(symbol->type == "PROC_INT"){
                        $$ = (char*)"VAR_INT";
                    }
                    else if(symbol->type == "PROC_FLOAT"){
                        $$ = (char*)"VAR_FLOAT";
                    }
                    else if(symbol->type == "PROC_STRING"){
                        $$ = (char*)"VAR_STRING";
                    }
                    else if(symbol->type == "PROC_BOOL"){
                        $$ = (char*)"VAR_BOOL";
                    }
                    if(symbol->argumentType.size() == parameter.size()){     
                       bool typeFlag=true; 
                       for(int i = 0; i < symbol->argumentType.size(); i++){
                            if(symbol->argumentType[i] == "VAR_INT"){
                                if(parameter[i] != "VAR_INT"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_FLOAT"){
                                if(parameter[i] != "VAR_FLOAT"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_STRING"){
                                if(parameter[i] != "VAR_STRING"){
                                    typeFlag=false;
                                }
                            }
                            else if(symbol->argumentType[i] == "VAR_BOOL"){
                                if(parameter[i] != "VAR_BOOL"){
                                    typeFlag=false;
                                }
                            }
                       }
                       if(!typeFlag){
                                    $$ = (char*)"ERROR";
                                    yyerror(string(string($1)) + " 's arguments is not match.");
                       }
                    }
                    else{                                                   
                        $$ = (char*)"ERROR";
                        yyerror(string(string($1)) + " arguments size is not match.");
                    }
                }
                else {
                    $$ = (char*)"ERROR";
                    yyerror(string(string($1)) + " no return.");   
                }
            }
        }
    ;
procedure_invocation:
        ID    
        {
            symbol = scope->Lookup_Global(string($1));
            if (symbol == NULL) {
                yyerror("\'" + string(string($1)) + "\' not declared.");
            } 
            else {
            // java
                fileWrite(fout, symbol->loadCode);
            // java end
                if (symbol->type != "PROC_NON") {
                yyerror("\'" + string(string($1)) + "\' is not non-return procedure.");
                }
                if (symbol->argumentType.size() != 0) {
                    yyerror("\'" + string(string($1)) + "\' need arguments.");
                } 
            }
        }
    |   ID PAR_L comma_separated_expressions PAR_R SEM
        {
            symbol = scope->Lookup_Global(string($1));
            if (symbol == NULL) {
                yyerror("\'" + string(string($1)) + "\' not declared.");
            } 
            else {
            // Java 
                fileWrite(fout, symbol->loadCode);

                if (symbol->type != "PROC_NON") {
                    yyerror("\'" + string(string($1)) + "\' is not non-return procedure.");
                }
                if (symbol->argumentType.size() == parameter.size()) {
                    bool typeFlag = true;
                    for (int i = 0; i < symbol->argumentType.size(); i++) {
                        if(symbol->argumentType[i]== "PROC_INT"){
                            if(parameter[i] != "VAR_INT"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_FLOAT"){
                            if(parameter[i] != "VAR_FLOAT"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_STRING"){
                            if(parameter[i] != "VAR_STRING"){
                                typeFlag=false;
                            }
                        }
                        else if(symbol->argumentType[i] == "PROC_BOOL"){
                            if(parameter[i] != "VAR_BOOL"){
                                typeFlag=false;
                            }
                        }
                    }
                    if (!typeFlag) {
                        yyerror("type error: \'" + string(string($1)) + "\' parameter type is not match.");
                    }
                } 
                else {
                    yyerror("syntax error: \'" + string(string($1)) + "\' parameter amounts is not match.");
                }
            }
            
        }
    ;
comma_separated_expressions:
        expression                                     
        {
            parameter.push_back(string($1));
        }
    |   expression 
        {
            parameter.push_back(string($1));
        } 
        COM 
        comma_separated_expressions
    ;
conditional_stmt:
        IF boolean_expression THEN 
        {
        // java
            elseBranch = false;
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();
        }
            block_simple_stmt
        opt_else
        {
        // java
            if (elseBranch) {
                fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            }
            branchStack.pop();
        }
        END IF opt_SEM
        
    ;

opt_else:
        EMPTY
        {
        // java
            branchStack.pop();
            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        }
    |   ELSE         
        {
        // java
            elseBranch = true;

            int gotoIndex = branchStack.top();
            branchStack.pop();
            int labelIndex = branchStack.top();
            branchStack.pop();

            fileWrite(fout, "goto L" + to_string(gotoIndex));
            fileWrite(fout, "L" + to_string(labelIndex) + ":");
        } 
        block_simple_stmt
    ;

block_simple_stmt:
        {
            SymbolTable* child = new SymbolTable("TEMP",scope);
            scope = child;
        }
        block_in_proc
        { 
            // exit this scope
            SymbolTable *trash = scope;
            scope = scope->parentTable;
            delete trash;
        }
    |   statement
    ;

while_loop:
        WHILE 
        {
        // java
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        }
        boolean_expression LOOP
        {
            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();
        }
        block_simple_stmt
        {
            int gotoIndex = branchStack.top();
            branchStack.pop();
            int labelIndex = branchStack.top();
            branchStack.pop();

            fileWrite(fout, "goto L" + to_string(gotoIndex));
            fileWrite(fout, "L" + to_string(labelIndex) + ":");
        }
        END LOOP opt_SEM
    ;
for_loop: 
        FOR PAR_L ID IN INT_VAL LOOPDOT INT_VAL PAR_R LOOP 
        {
            symbol = scope->Lookup_Global(string($3));
            if (symbol == NULL) {
                yyerror("\'" + string(string($3)) + "\' not declared.");
            } 
            else if (symbol->type != "VAR_INT") {
                yyerror("type error: \'" + string(string($3)) + "\' not integer.");
            }
        //java
            fileWrite(fout, "sipush " + to_string($5));
            fileWrite(fout, symbol->storeCode);

            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchStack.push(branchIndex + 1);
            branchStack.push(branchIndex);
            branchIndex += 2;

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        // java end
        }
        block_simple_stmt
        {
        // java
            fileWrite(fout, "sipush " + to_string($7));
            symbol = scope->Lookup_Global($3);
            if (symbol != NULL) {
                fileWrite(fout, symbol->loadCode);
            }

            fileWrite(fout, "isub");
            fileWrite(fout, "ifeq L" + to_string(branchStack.top()));
            branchStack.pop();

            fileWrite(fout, "iconst_1");
            if (symbol != NULL) {
                fileWrite(fout, symbol->loadCode);
            }

            fileWrite(fout, "iadd");
            if (symbol != NULL) {
                fileWrite(fout, symbol->storeCode);
            }

            fileWrite(fout, "goto L" + to_string(branchStack.top()));
            branchStack.pop();

            fileWrite(fout, "L" + to_string(branchStack.top()) + ":");
            branchStack.pop();
        // java end
        }
        END LOOP opt_SEM
         
    ;

integer_expression: 
        expression  
        {
            if (string($1) != "VAR_INT") {
                yyerror("type error: The type is not integer.");
            }
        }
    ;

boolean_expression: 
        expression  
        {
            if (string($1) != "VAR_BOOL") {
                yyerror("type error: The type is not boolean.");
            }
        }
    ;

expression: 
        expression ADD expression   
        {
            if(string(string($1)) == string(string($3))){
                if( string(string($1)) == "VAR_INT" ||  string($1) == "VAR_FLOAT" 
                ||  string($1) == "VAR_STRING" || string($1) == "VAR_CHAR"){
                    $$ = (char*)($1);  
                }
                else{
                    $$ = (char*)"ERROR";
                    yyerror("type error: this type can not ADD.");  
                }
            }
            else{        
                $$ = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"iadd");
        }
    |   expression SUB expression   
        {
            if(string($1) == string($3)){
                if( string($1) == "VAR_INT" ||  string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR"){
                    $$ = (char*)($1);  
                }
                else{
                    $$ = (char*)"ERROR";
                    yyerror("type error: this type can not SUB.");  
                }
            }
            else{        
                $$ = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"isub");
        }
    |   expression MUL expression   
        {
            if(string($1) == string($3)){
                if( string($1) == "VAR_INT" ||  string($1) == "VAR_FLOAT"){
                    $$ = (char*)($1);  
                }
                else{
                    $$ = (char*)"ERROR";
                    yyerror("type error: this type can not MUL.");  
                }
            }
            else{        
                $$ = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout,"imul");
        }
    |   expression DIV expression   
        {
            if(string($1) == string($3)){
                if( string($1) == "VAR_INT" ||  string($1) == "VAR_FLOAT"){
                    $$ = (char*)($1);  
                }
                else{
                    $$ = (char*)"ERROR";
                    yyerror("type error: this type can not DIV.");  
                }
            }
            else{        
                $$ = (char*)"ERROR";
                yyerror("type error: not the same.");
            }
        // java
            fileWrite(fout, "idiv");
        }
    |   expression REM expression
        {
            yyerror("no % operation in proj3.");
        }
    |   SUB expression %prec UMINUS 
        {
            if (string($2) == "VAR_INT" || string($2) == "VAR_FLOAT") {
                $$ = (char*)($2);
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("This types can not UMINUS.");
            }
        // java
            fileWrite(fout, "ineg");
        }
    |   expression LE expression    
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not LE.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "iflt L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
    |   expression LEEQ expression  
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not LEEQ.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifle L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
    |   expression GR expression    
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not GR.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifgt L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
    |   expression GREQ expression  
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not GREQ.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifge L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end   
        }
    |   expression EQ expression    
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not EQ.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifeq L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
    |   expression NEQ expression   
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_INT" || string($1) == "VAR_FLOAT" || string($1) == "VAR_CHAR") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not NEQ.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same");
            }

        // java
            fileWrite(fout, "isub");
            fileWrite(fout, "ifne L" + to_string(branchIndex));
            fileWrite(fout, "iconst_0");
            fileWrite(fout, "goto L" + to_string(branchIndex + 1));
            fileWrite(fout, "L" + to_string(branchIndex) + ":");
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "L" + to_string(branchIndex + 1) + ":");
            branchIndex += 2;
        // java end
        }
    |   expression AND expression   
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_BOOL") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not use AND.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same!");
            }
        // java
            fileWrite(fout,"iand");
        }
    |   expression OR expression    
        {
            if (string($1) == string($3)) {
                if (string($1) == "VAR_BOOL") {
                    $$ = (char*)"VAR_BOOL";
                } 
                else {
                    $$ = (char*)"ERROR";
                    yyerror("syntax error: can not use OR.");
                }
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("type error: not the same!");
            }
        // java
            fileWrite(fout,"ior");
        }
    |   NOT expression              
        {
            if (string($2) == "VAR_BOOL") {
                $$ = (char*)"VAR_BOOL";
            } 
            else {
                $$ = (char*)"ERROR";
                yyerror("syntax error: can not use NOT.");
            }

        // A xor 1 = not A
            fileWrite(fout, "iconst_1");
            fileWrite(fout, "ixor");
        }
    |   PAR_L expression PAR_R      
        { $$ = (char*)($2); }
    |   bool_val                    
        { 
            $$ = (char*)"VAR_BOOL"; 
            // Java 
            // true -> 1, false -> 0
            if ($1) {
                fileWrite(fout, "iconst_1");
            } 
            else {
                fileWrite(fout, "iconst_0");
            }
        }
    |   INT_VAL                     
        { 
            $$ = (char*)"VAR_INT"; 
            fileWrite(fout, "sipush " + to_string($1));
        }
    |   FLOAT_VAL                   
        { $$ = (char*)"VAR_FLOAT"; }
    |   STRING_VAL                  
        { 
            $$ = (char*)"VAR_STRING"; 
            fileWrite(fout, "ldc \"" + string($1) + "\"");
        }
    |   array_reference             
        { $$ = (char*)($1); }
    |   function_invocation         
        { $$ = (char*)($1); }
    |   ID                          
        {
            symbol = scope->Lookup_Global(string($1));
            if(symbol != NULL){       
            // java  
                fileWrite(fout, symbol->loadCode);

                if(symbol->type == "VAR_INT"
                || symbol->type == "VAR_FLOAT" 
                || symbol->type == "VAR_CHAR" 
                || symbol->type == "VAR_BOOL" ){
                    $$ = &symbol->type[0];
                }
                else if(symbol->type == "CON_INT"
                || symbol->type == "CON_FLOAT" 
                || symbol->type == "CON_CHAR" 
                || symbol->type == "CON_BOOL"){
                    string temp(symbol->type);
                    temp[0] = 'V';
                    temp[1] = 'A';
                    temp[2] = 'R';
                    $$ = &temp[0];
                }
                else if(symbol->type == "VAR_STRING" || symbol->type == "CON_STRING"){
                    $$ = (char*)"VAR_STRING";
                }
                else{
                    $$ = (char*)"ERROR";
                    yyerror("\'" + string(string($1)) + "\' is not constant or variable.");
                }
            }
            else{                                   
                $$ = (char*)"ERROR";
                yyerror("\'" + string(string($1)) + "\' not declared.");
            }
        }
    ;
bool_val: 
        TRUE  { $$ = true; }
    |   FALSE { $$ = false; }
    ;
array_reference: 
        ID SBRA_L integer_expression SBRA_R    
        {
            yyerror("no array in proj3.");
        }
    ;
%%

void yyerror(string t) {
    cout << "LINE " << linecount << " | " << t<<endl;
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Input Filename Plz.\n");
        exit(1);
    }
    fileName = string(argv[1]);
    jasmName = fileName.substr(0, fileName.find_last_of('.'));

    yyin = fopen(argv[1], "r");
    fout.open(jasmName + ".jasm");
    yyparse();
    return 0;
}
