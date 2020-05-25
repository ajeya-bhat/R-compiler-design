lex icg.l
yacc -d icg.y 2>/dev/null
gcc lex.yy.c y.tab.c -ll
