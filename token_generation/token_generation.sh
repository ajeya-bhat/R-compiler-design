lex token_generation.l
yacc -d token_generation.y
gcc lex.yy.c y.tab.c -ll 
