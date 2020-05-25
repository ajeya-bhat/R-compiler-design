
%{
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include<string.h>
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

%define parse.error verbose
%start RR
%token NL PRINT WHILE FOR IF IN ELSE TRUE1 FALSE1 NUMB STRI id COPEN BROPEN BRCLOSE T_pl T_min T_mul T_div T_lt T_gt T_eq T_and T_or T_ass  T_eqeq
%left '<' '>' T_le T_ge T_eqeq T_ne 
%right T_eq T_ass
%%


RR:	R
	;

N:	NL
	|
	;

R: 	WHILEBODY R 
	| IFBODY R 
	| FORBODY R 
	| EXP R 
	| PRINT '('VEC ')'  N R
	| BROPEN  N R BRCLOSE N R
	| error N R
	|
	;

WHILEBODY :	WHILE N  '(' N COND N')' N BROPEN N R BRCLOSE N
	;

FORBODY :	FOR N '(' N FIT IN RANGE  N ')' N BROPEN N  R BRCLOSE N
	;

IFBODY :	 IF N '('  N COND N  ')' N  N  BROPEN  NIFLADDER  
	;

NIFLADDER :  N R BRCLOSE N
	|N R BRCLOSE N E
	;	

E :	 ELSE  N BROPEN N R BRCLOSE N;

EXP :	OP1 RELOP OP1  N
	| ID ASSIGNOP OP1  N
	| OP1 N
	;

COND :	OP1 RELOP OP1 
	| ID ASSIGNOP OP1 
	| OP1 LOGICOP OP1 
	| OP1 
	;

OP1: OP1 T_pl OP2 {$$=$1+$3;}
	| OP1 T_min OP2 {$$=$1-$3;}
	| OP2 {$$=$$;}
	;
	
OP2: OP2 T_mul LIT {$$=$1*$3;}
	| OP2 T_div LIT {$$=$1/$3;}
	| LIT {$$=$$;}
	; 


LIT: ID 
	| NUM {$$=$1;}
	;

RELOP:T_lt
	|T_gt
	|T_eqeq
	|T_le
	|T_ge
	|T_ne
	;

ASSIGNOP:T_eq
	|T_ass
	; 

LOGICOP: T_and
	| T_or
	;

RANGE:	NUMC':'NUMC
	| COPEN VECTOR')'
	|ID
	;



VECTOR:	VEC ',' VECTOR 
	| VEC
    | 
	;
	
VEC: 	NUM 
	| BOOL 
	| STR 
	| ID
	;

NUMC: NUMB;

NUM: 	NUMB
	;

BOOL: 	TRUE1 
	| FALSE1
	;

STR: 	STRI
	;

FIT: id;

ID: 	id
	;

%%


int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
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
	
		display();
	
	
	return 0;
} 
