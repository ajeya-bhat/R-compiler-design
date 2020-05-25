
%{
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define YYSTYPE char*
int valid=1;
int yylex();
int yyerror(const char *s);
extern int st[100];
extern int top;
extern int count;
extern void display();
extern struct var
{
	int d;
	char c[20];
	char l[100];
	int scope;
	char *value;
	int y;
};

extern int yylineno;
extern struct var symtab[100];
extern int symcount;

extern void insertIntoSym(char *text,int nm,int scp);
%}

%start RR
%define parse.error verbose
%token ID NUM T_lt T_gt T_lteq T_gteq T_neq T_eqeq T_pl T_min T_mul T_div T_and T_or T_not T_eq T_ass T_BRCLOSE T_BROPEN  WHILE MAINTOK BREAK CONTINUE IF ELSE PRINT STRING FOR IN ARRAY
%locations
%left T_lt T_gt
%left T_pl T_min
%left T_mul T_div
%%

RR: R | error"\n" ;

R
      : R statement  
      | R LOOPS  
      | statement 
      | LOOPS
      ;

LOOPS
      : WHILE '(' COND ')' LOOPBODY  
      | FOR '(' ID IN FIT ')' LOOPBODY  
      | IF '(' COND ')' LOOPBODY   
      | IF '(' COND ')' LOOPBODY ELSE LOOPBODY  
      ;

FIT
	  : ID | ARR 
          ;

LOOPBODY
  	  : T_BROPEN R T_BRCLOSE 
  	  | statement
  	  ;

ARR : ARRAY ARRR ')'   

ARRR: ARRR ',' NUM  | NUM  ;

statement
      : ASSIGN_EXPR  
      | T 
      | TERNARY_EXPR  
      | PRNT  
      ;


COND
      : LIT RELOP LIT  
      | LIT  
      | LIT RELOP LIT bin_boolop LIT RELOP LIT  
      | un_boolop '(' LIT RELOP LIT ')'  
      | un_boolop LIT RELOP LIT  
      | LIT bin_boolop LIT  
      | un_boolop '(' LIT ')'  
      | un_boolop LIT  
      ;

ASSIGN_EXPR
      : ID  T_eq T
      | ID T_ass T 	
      ;
T:
T T_pl T { $$ = atoi($1) + atoi($3); } 
| T '-' T { $$ = atoi($1) + atoi($3); } 
| T '*' T { $$ = atoi($1) + atoi($3); } 
| T '/' T { $$ = atoi($1) + atoi($3); }  
| '(' T ')' { $$ = $2; } 
| NUM { $$ = atoi($1); } 
| ID 


ARITH_EXPR

      : LIT  {$$=$1;}
      | ARR  
      | LIT T_pl ARITH_EXPR  {$$=atoi($1) + atoi($3); }
	| LIT T_min ARITH_EXPR  {$$=atoi($1) - atoi($3); }
	| LIT T_mul ARITH_EXPR  {$$=atoi($1) * atoi($3); }
	| LIT T_div ARITH_EXPR  {$$=atoi($1) / atoi($3); }
      | LIT T_or ARITH_EXPR {$$=atoi($1) + atoi($3);}
      | LIT T_and ARITH_EXPR {$$=atoi($1) + atoi($3);} 
      | un_boolop ARITH_EXPR  
      | LIT un_in LIT  
      ;



TERNARY_EXPR
      : '(' COND ')' '?' statement ':' statement  
      ;

PRNT :  PRINT '(' PRINTEXPR ')' | PRINT '(' STRING ')' ;

PRINTEXPR : LIT  ;

LIT
      : ID  
      | NUM  {sprintf($$, "%d", atoi($1));printf("%d\n", $$);}
      ;

RELOP
      : T_lt   
      | T_gt   
      | T_lteq  
      | T_gteq   
      | T_neq   
      | T_eqeq   
      ;

bin_boolop
      : T_and  
      | T_or   
      ;

un_boolop
      : T_not   
      ;

un_in
      : IN  
      ;
%%


int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
	display();
  	printf("\n\nLine no: %d \n The error is: %s\n",yylineno,s);
}

int main()
{
	st[0]=0;
	top=0;
	count=0;
	extern FILE *yyin;
        yyin=fopen("a.r","r");
	yyparse();
	if(valid)
	{
  		printf("\n\nParsing successful\n\n");
		display();
	}
	else
	{
  		printf("\n\nParsing unsuccessful\n\n");
	}
	
	return 0;
} 
