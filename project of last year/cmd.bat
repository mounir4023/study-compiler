flex lex.l
bison -d synt.y
gcc lex.yy.c synt.tab.c -ly -o compiler
compiler <code.txt

