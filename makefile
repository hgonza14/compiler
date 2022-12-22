output: lex.yy.o parser.tab.o
	gcc -o output lex.yy.o parser.tab.o

parser.tab.o parser.tab.h: parser.y IRcode.h AST.h symbolTable.h
	bison -d parser.y
	gcc -c parser.tab.c

lex.yy.o: lexer.l parser.tab.h
	flex lexer.l
	gcc -c lex.yy.c

clean:
	rm -f output parser.output *.o parser.tab.* lex.yy.c