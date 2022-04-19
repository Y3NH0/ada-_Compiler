# B10615048_proj3

## makefile說明:

- make
  - 產出parser
- make clean
 	- 除了測試的檔案
    刪到剩下lex.l, yacc.y, Symbol.h, Symbol.cpp
- make test
 	- 將test_ada資料夾裡面的所有檔案餵給parser
 	  產出 \*.jasm

## 測試說明:

1. 產出filename.jasm
  ./parser.exe filename.ada

2. 產出filename.class
  javaa/javaa filename.jasm

3. 執行
  java filename
