lex validation.l
yacc -d validation.y 2>/dev/null
gcc lex.yy.c y.tab.c -ll
