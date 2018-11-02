flex lexical.l
bison -d synt.y
gcc lex.yy.c synt.tab.c -lfl -ly -o compilsii

./compilsii <lang.txt
