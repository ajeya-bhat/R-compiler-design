%option yylineno
%{
    #include<string.h>
    #include<stdio.h>
    #include "y.tab.h"
    	int st[100];
	int top;
	int count;
	int symcount=-1;
%}


%%

#(.)*\n ;
[\n \t] {}
"while" {printf("< KEYWORD , while , %d >\n",yylineno);return WHILE;}
"for" {printf("< KEYWORD , for , %d >\n",yylineno);return FOR;}
"if" {printf("< KEYWORD , if , %d >\n",yylineno);return IF;}
"else" {printf("< KEYWORD , else , %d >\n",yylineno);return ELSE;}
"break" {printf("< KEYWORD , break , %d >\n",yylineno);return BREAK;}
"continue" {printf("< KEYWORD , continue , %d >\n",yylineno);return CONTINUE;}
"in" {printf("< KEYWORD , in , %d >\n",yylineno);return IN;}
"print"    {printf("< KEYWORD , print , %d >\n",yylineno);return PRINT;}
"c\(" {return ARRAY;}
"{" {printf("< BRACES , { , %d >\n",yylineno); count=count+1;top=top+1;st[top]=count;return T_BROPEN;}
"}" {printf("< BRACES , } , %d >\n",yylineno); top=top-1;return T_BRCLOSE;}
[0-9]+    {return NUM;}
[A-Za-z_]([A-Za-z_]|[0-9])* {printf("< ID , %s , %d >\n",yytext,yylineno);return ID;}
\".*\" {return STRING;}
"<" {printf("< RELOP , < , %d >\n",yylineno); return T_lt;}
">"     {printf("< RELOP , > , %d >\n",yylineno); return T_gt;}
"="     {printf("< ASSIGNOP , = , %d >\n",yylineno);return T_eq;}
"<-"     {printf("< ASSIGNOP , <- , %d >\n",yylineno);return T_ass;}
"<="    {printf("< RELOP , <= , %d >\n",yylineno); return T_lteq;}
">="    {printf("< RELOP , >= , %d >\n",yylineno); return T_gteq;}
"=="    {printf("< RELOP , == , %d >\n",yylineno); return T_eqeq;}
"!="    {printf("< RELOP , != , %d >\n",yylineno); return T_neq;}
"+"     {printf("< ARITHOP , + , %d >\n",yylineno);return T_pl;}
"-"     {printf("< ARITHOP , - , %d >\n",yylineno);return T_min;}
"*"     {printf("< ARITHOP , * , %d >\n",yylineno);return T_mul;}
"/"     {printf("< ARITHOP , / , %d >\n",yylineno);return T_div;}
"!"     {printf("< LOGICALOP , ! , %d >\n",yylineno);return T_neq;}
"||"    {printf("< LOGICALOP , || , %d >\n",yylineno);return T_or;}
"&&"    {printf("< LOGICALOP , && , %d >\n",yylineno);return T_and;}


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
