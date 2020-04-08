lex eval.l
yacc -d eval.y
gcc lex.yy.c y.tab.c -ll -w
