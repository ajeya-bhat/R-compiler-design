lex symbol_table.l
yacc -d symbol_table.y 2>/dev/null
gcc lex.yy.c y.tab.c -ll -w

