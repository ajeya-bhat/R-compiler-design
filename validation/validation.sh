lex validation.l
yacc -d validation.y
gcc lex.yy.c y.tab.c -ll
