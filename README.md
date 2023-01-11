# ada-_Compiler
* NTUST_1092_Compiler_Design_Project

# Usage

## make file

* to generate the parser(compiler): `make`
* clean the files besides lex.l, yacc.y, Symbol.h, Sumbol.cpp: `make clean`
* compile all the .ada in `test_ada` to `.jasm` file: `make test`

## cmd

1. generate .jasm file: `./parser.exe filename.ada`
2. generate .class file: `javaa/javaa filename.jasm`
3. execute: `java filename`
