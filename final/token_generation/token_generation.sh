lex token_generation.l
yacc -d token_generation.y 2>/dev/null
gcc lex.yy.c y.tab.c -ll 
