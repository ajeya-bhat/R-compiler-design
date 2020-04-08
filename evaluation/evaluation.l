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
"while" {printf("< KEYWORD , while , %d >\n",yylineno);yylval = strdup(yytext);return WHILE;}
"for" {printf("< KEYWORD , for , %d >\n",yylineno);yylval = strdup(yytext);return FOR;}
"if" {printf("< KEYWORD , if , %d >\n",yylineno);yylval = strdup(yytext);return IF;}
"else" {printf("< KEYWORD , else , %d >\n",yylineno);yylval = strdup(yytext);return ELSE;}
"break" {printf("< KEYWORD , break , %d >\n",yylineno);yylval = strdup(yytext);return BREAK;}
"continue" {printf("< KEYWORD , continue , %d >\n",yylineno);yylval = strdup(yytext);return CONTINUE;}
"in" {printf("< KEYWORD , in , %d >\n",yylineno);yylval = strdup(yytext);return IN;}
"print"    {printf("< KEYWORD , print , %d >\n",yylineno);yylval = strdup(yytext);return PRINT;}
"c\(" {yylval = strdup(yytext);return ARRAY;}
"{" {printf("< BRACES , { , %d >\n",yylineno); count=count+1;top=top+1;st[top]=count;return T_BROPEN;}
"}" {printf("< BRACES , } , %d >\n",yylineno); top=top-1;return T_BRCLOSE;}
[0-9]+    {yylval = strdup(yytext);return NUM;}
[A-Za-z_]([A-Za-z_]|[0-9])* {yylval = strdup(yytext);insertIntoSym(yytext,yylineno,st[top]);return ID;}
\".*\" {yylval = strdup(yytext);return STRING;}
"<" {printf("< RELOP , < , %d >\n",yylineno); yylval = strdup(yytext);return T_lt;}
">"     {printf("< RELOP , > , %d >\n",yylineno); yylval = strdup(yytext);return T_gt;}
"="     {printf("< ASSIGNOP , = , %d >\n",yylineno);yylval = strdup(yytext);return T_eq;}
"<-"     {printf("< ASSIGNOP , <- , %d >\n",yylineno);yylval = strdup(yytext);return T_ass;}
"<="    {printf("< RELOP , <= , %d >\n",yylineno); yylval = strdup(yytext);return T_lteq;}
">="    {printf("< RELOP , >= , %d >\n",yylineno); yylval = strdup(yytext);return T_gteq;}
"=="    {printf("< RELOP , == , %d >\n",yylineno); yylval = strdup(yytext);return T_eqeq;}
"!="    {printf("< RELOP , != , %d >\n",yylineno); yylval = strdup(yytext);return T_neq;}
"+"     {printf("< ARITHOP , + , %d >\n",yylineno);yylval = strdup(yytext);return T_pl;}
"-"     {printf("< ARITHOP , - , %d >\n",yylineno);yylval = strdup(yytext);return T_min;}
"*"     {printf("< ARITHOP , * , %d >\n",yylineno);yylval = strdup(yytext);return T_mul;}
"/"     {printf("< ARITHOP , / , %d >\n",yylineno);yylval = strdup(yytext);return T_div;}
"!"     {printf("< LOGICALOP , ! , %d >\n",yylineno);yylval = strdup(yytext);return T_neq;}
"||"    {printf("< LOGICALOP , || , %d >\n",yylineno);yylval = strdup(yytext);return T_or;}
"&&"    {printf("< LOGICALOP , && , %d >\n",yylineno);yylval = strdup(yytext);return T_and;}


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
