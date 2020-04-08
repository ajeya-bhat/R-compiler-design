%option yylineno
%{
    #define YYSTYPE char*
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
"{" { count=count+1;top=top+1;st[top]=count;return T_BROPEN;}
"}" { top=top-1;return T_BRCLOSE;}
[0-9]+    {yylval = strdup(yytext);return NUM;}
[A-Za-z_]([A-Za-z_]|[0-9])* {yylval = strdup(yytext);return ID;}
\".*\" {return STRING;}
"<" { return T_lt;}
">"     {return T_gt;}
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
	
	for(int i=0;i<=symcount;i++)
	{

			printf("ID:%d \t Symbol:%s \t Scope:%d \t Line number: %s\n",symtab[i].d,symtab[i].c,symtab[i].scope,symtab[i].l);
	}	
	
}

int yywrap()
{
return 1;
}
