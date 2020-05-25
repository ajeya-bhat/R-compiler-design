#!/bin/bash

lex phase2.l
yacc phase2_1.y -d 2>/dev/null
gcc lex.yy.c y.tab.c -ll -lfl -w
./a.out
