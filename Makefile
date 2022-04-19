all: parser

parser: lex.l yacc.y Symbol.h Symbol.cpp
	lex lex.l
	yacc -d yacc.y
	g++ -o parser y.tab.c Symbol.cpp -std=c++11

.PHONY: clean
clean:
	rm lex.yy.c y.tab.* parser
	
.PHONY: test
test:
	./parser.exe test_ada/example.ada
	./parser.exe test_ada/fib.ada
	./parser.exe test_ada/HelloWorld.ada
	./parser.exe test_ada/sigma.ada
