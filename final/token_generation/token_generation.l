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
print 			{printf("< KEYWORD , print , %d >\n",yylineno);return PRINT;}
while 			{printf("< KEYWORD , while , %d >\n",yylineno);return WHILE;}
for 			{printf("< KEYWORD , for , %d >\n",yylineno);return FOR;}
if 			{printf("< KEYWORD , if , %d >\n",yylineno);return IF;}
else 			{printf("< KEYWORD , else , %d >\n",yylineno);return ELSE;}
in 			{printf("< KEYWORD , in , %d >\n",yylineno);return IN;}
"c(" 			{return COPEN;}
"<=" 			{printf("< RELOP , <= , %d >\n",yylineno); return T_le;}
">=" 			{printf("< RELOP , >= , %d >\n",yylineno); return T_ge;}
"==" 			{printf("< RELOP , == , %d >\n",yylineno); return T_eqeq;}
"!=" 			{printf("< RELOP , != , %d >\n",yylineno); return T_ne;}
"<-" 			{printf("< ASSIGNOP , <- , %d >\n",yylineno); return T_ass;}
"+" 			{printf("< ARITHOP , + , %d >\n",yylineno); return T_pl;}
"-" 			{printf("< ARITHOP , - , %d >\n",yylineno); return T_min;}
"*" 			{printf("< ARITHOP , * , %d >\n",yylineno); return T_mul;}
"/" 			{printf("< ARITHOP , / , %d >\n",yylineno); return T_div;}
"<" 			{printf("< RELOP , < , %d >\n",yylineno); return T_lt;}
">" 			{printf("< RELOP , > , %d >\n",yylineno); return T_gt;}
"=" 			{printf("< ASSIGNOP , = , %d >\n",yylineno); return T_eq;}
"&&" 			{printf("< LOGICALOP , && , %d >\n",yylineno); return T_and;}
"||" 			{printf("< LOGICALOP , || , %d >\n",yylineno); return T_or;}
"{" 			{count=count+1;top=top+1;st[top]=count;return BROPEN;}
"}" 			{top=top-1;return BRCLOSE;}
[0-9]+ 			{yylval = atoi(yytext);return NUMB;}
TRUE 			{ return TRUE1;}
FALSE 			{ return FALSE1;}
\".*\" 			{return STRI;}
\.[a-zA-Z_]([a-zA-Z0-9_.])*|[a-zA-Z]([a-zA-Z0-9_.])* {printf("< ID , %s , %d >\n",yytext,yylineno);return id;}

. {return yytext[0];}


%%
