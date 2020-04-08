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
	void display();
%}


%%

#(.)*\n ;
[\n \t] {yylval = strdup(yytext);}
"while" {yylval = strdup(yytext);return WHILE;}
"for" {yylval = strdup(yytext);return FOR;}
"if" {yylval = strdup(yytext);return IF;}
"else" {yylval = strdup(yytext);return ELSE;}
"break" {yylval = strdup(yytext);return BREAK;}
"continue" {yylval = strdup(yytext);return CONTINUE;}
"in" {yylval = strdup(yytext);return IN;}
"print"    {yylval = strdup(yytext);return PRINT;}
"c\(" {yylval = strdup(yytext);return ARRAY;}
"{" { count=count+1;top=top+1;st[top]=count;return T_BROPEN;}
"}" {top=top-1;return T_BRCLOSE;}
[0-9]+    {yylval = strdup(yytext);return NUM;}
[A-Za-z_]([A-Za-z_]|[0-9])* {yylval = strdup(yytext);insertIntoSym(yytext,yylineno,st[top]);return ID;}
\".*\" {yylval = strdup(yytext);return STRING;}
"<" { yylval = strdup(yytext);return T_lt;}
">"     { yylval = strdup(yytext);return T_gt;}
"="     {yylval = strdup(yytext);return T_eq;}
"<-"     {yylval = strdup(yytext);return T_ass;}
"<="    { yylval = strdup(yytext);return T_lteq;}
">="    { yylval = strdup(yytext);return T_gteq;}
"=="    {yylval = strdup(yytext);return T_eqeq;}
"!="    {yylval = strdup(yytext);return T_neq;}
"+"     {yylval = strdup(yytext);return T_pl;}
"-"     {yylval = strdup(yytext);return T_min;}
"*"     {yylval = strdup(yytext);return T_mul;}
"/"     {yylval = strdup(yytext);return T_div;}
"!"     {yylval = strdup(yytext);return T_neq;}
"||"    {yylval = strdup(yytext);return T_or;}
"&&"    {yylval = strdup(yytext);return T_and;}


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

struct var symtab[100];


extern void insertIntoSym(char *text,int nm,int scp)
{
	int present=0;
	for(int i=0;i<=symcount;i++)
	{
		if(strcmp(symtab[i].c,text)==0 && symtab[i].scope==scp)
		{
			char buffer[20];
			sprintf(buffer,"%d",nm);
			present=1;
			strcat(symtab[i].l,",");
			strcat(symtab[i].l,buffer);	
			symtab[i].scope=scp;		
			break;
		}
	}
	if(present==0)
	{
		symcount++;
		char buffer[20];
		sprintf(buffer,"%d",nm);
		int p=symcount;
		symtab[p].d=p;
		strcpy(symtab[p].c,text);
		strcpy(symtab[p].l,"");
		strcat(symtab[p].l,buffer);
		symtab[p].scope=scp;
	}
	
}

extern void display()
{
	printf("\n\nSymbol Table\n");
	for(int i=0;i<=symcount;i++)
	{

			printf("ID:%d \t Symbol:%s \t Scope:%d \Line number: %s\n",symtab[i].d,symtab[i].c,symtab[i].scope,symtab[i].l);
	}	
	
}

int yywrap()
{
return 1;
}
