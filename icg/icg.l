%option yylineno
%{

    	#include "y.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
    	

	
%}
	

%%
#(.*)\n ; 
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


int yywrap()
{
return 1;
}
