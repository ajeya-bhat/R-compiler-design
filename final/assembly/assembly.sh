reset
lex assembly.l
yacc -d assembly.y 2>/dev/null
gcc lex.yy.c y.tab.c -ll
./a.out > output.txt
python3 scrape.py > optimized2.txt
python3 assembly.py
