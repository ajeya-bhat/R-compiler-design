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

#(.)*\n ;
[\n \t] {}
"while" {return WHILE;}
"for" {return FOR;}
"if" {return IF;}
"else" {return ELSE;}
"break" {return BREAK;}
"continue" {return CONTINUE;}
"in" {return IN;}
"print"    {return PRINT;}
"c\(" {return ARRAY;}
"{" { return T_BROPEN;}
"}" { return T_BRCLOSE;}
[0-9]+    {return NUM;}
[A-Za-z_]([A-Za-z_]|[0-9])* {return ID;}
\".*\" {return STRING;}
"<" { return T_lt;}
">"     { return T_gt;}
"="     {return T_eq;}
"<-"     {return T_ass;}
"<="    {return T_lteq;}
">="    {return T_gteq;}
"=="    {return T_eqeq;}
"!="    {return T_neq;}
"+"     {return T_pl;}
"-"     {return T_min;}
"*"     {return T_mul;}
"/"     {return T_div;}
"!"     {return T_neq;}
"||"    {return T_or;}
"&&"    {return T_and;}


.    return yytext[0];


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
