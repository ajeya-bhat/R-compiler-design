%option yylineno
%{
    #include<string.h>
    #include<stdio.h>
    #include "y.tab.h"
    	int st[100];
	int top;
	int count;
	int symcount=-1;
	void insertIntoSym(char *text,int nm,int scp);
%}


%%
#(.*)\n+  
[ \t] ; 
(\n)+			{return NL;}
print 			{return PRINT;}
while 			{return WHILE;}
for 			{return FOR;}
if 			{return IF;}
else 			{return ELSE;}
in 			{return IN;}
"c(" 			{return COPEN;}
"<=" 			{return T_le;}
">=" 			{return T_ge;}
"==" 			{return T_eqeq;}
"!=" 			{return T_ne;}
"<-" 			{return T_ass;}
"+" 			{return T_pl;}
"-" 			{return T_min;}
"*" 			{return T_mul;}
"/" 			{return T_div;}
"<" 			{return T_lt;}
">" 			{return T_gt;}
"=" 			{return T_eq;}
"&&" 			{return T_and;}
"||" 			{return T_or;}
"{" 			{return BROPEN;}
"}" 			{return BRCLOSE;}
[0-9]+ 			{yylval = atoi(yytext);return NUMB;}
TRUE 			{ return TRUE1;}
FALSE 			{ return FALSE1;}
\".*\" 			{return STRI;}
\.[a-zA-Z_]([a-zA-Z0-9_.])*|[a-zA-Z]([a-zA-Z0-9_.])* {return id;}

. {return yytext[0];}



%%
struct var
{
	int d;
	char c[20];
	char l[100];
	int scope;
	char value[100];
	int y;
};



int yywrap()
{
return 1;
}
