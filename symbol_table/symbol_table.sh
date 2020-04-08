lex symbol_table.l
yacc -d symbol_table.y 
gcc lex.yy.c y.tab.c -ll -w
