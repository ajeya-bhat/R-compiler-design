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

`#(.*)\n+  
[ \t] ; 
(\n)+			{yylval = strdup(yytext);return NL;}
print 			{yylval = strdup(yytext);return PRINT;}
while 			{yylval = strdup(yytext);return WHILE;}
for 			{yylval = strdup(yytext);return FOR;}
if 			{yylval = strdup(yytext);return IF;}
else 			{yylval = strdup(yytext);return ELSE;}
in 			{yylval = strdup(yytext);return IN;}
"c(" 			{yylval = strdup(yytext);return COPEN;}
"<=" 			{yylval = strdup(yytext);return T_le;}
">=" 			{yylval = strdup(yytext);return T_ge;}
"==" 			{yylval = strdup(yytext);return T_eqeq;}
"!=" 			{yylval = strdup(yytext);return T_ne;}
"<-" 			{yylval = strdup(yytext);return T_ass;}
"+" 			{yylval = strdup(yytext);return T_pl;}
"-" 			{yylval = strdup(yytext);return T_min;}
"*" 			{yylval = strdup(yytext);return T_mul;}
"/" 			{yylval = strdup(yytext);return T_div;}
"<" 			{yylval = strdup(yytext);return T_lt;}
">" 			{yylval = strdup(yytext);return T_gt;}
"=" 			{yylval = strdup(yytext);return T_eq;}
"&&" 			{yylval = strdup(yytext);return T_and;}
"||" 			{yylval = strdup(yytext);return T_or;}
"{" 			{count=count+1;top=top+1;st[top]=count;yylval = strdup(yytext);return BROPEN;}
"}" 			{top=top-1;yylval = strdup(yytext);return BRCLOSE;}
[0-9]+ 			{yylval = atoi(yytext);return NUMB;}
TRUE 			{yylval = strdup(yytext); return TRUE1;}
FALSE 			{yylval = strdup(yytext); return FALSE1;}
\".*\" 			{yylval = strdup(yytext);return STRI;}
\.[a-zA-Z_]([a-zA-Z0-9_.])*|[a-zA-Z]([a-zA-Z0-9_.])* {yylval = strdup(yytext);insertIntoSym(yytext,yylineno,st[top]);return id;}

. {yylval = strdup(yytext);return yytext[0];}


%%
struct var
{
	int d;
	char c[20];
	char l[100];
	int scope;
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

			printf("ID:%d \t Symbol:%s \t Scope:%d	\t \Line number: %s\n",symtab[i].d,symtab[i].c,symtab[i].scope,symtab[i].l);
	}	
	
}

int yywrap()
{
return 1;
}
