%{ 
int count=1;
#include "stdio.h"
%} 
  
%token NUMBER ID T_eq NL
%left '+' '-'
%left '*' '/'
%start R 
%% 
R: R E NL | E NL ;
E : ID T_eq T 
  {  
   printf("Result of expr %d = %d\n",count++, $3);
  } 
  
T : T '+' T { $$ = $1 + $3;  } 
| T '-' T { $$ = $1 - $3; } 
| T '*' T { $$ = $1 * $3; } 
| T '/' T { $$ = $1 / $3; } 
| '-' NUMBER { $$ = -$2; } 
| '-' ID { $$ = -$2; } 
| '(' T ')' { $$ = $2; } 
| NUMBER { $$ = $1; } 
| ID { $$ = $1; }; 
%% 
  
    int main() 
 { 
    extern FILE *yyin;
        yyin=fopen("a.r","r");
	yyparse(); 
 } 
int yyerror(char* s) 
 { 
    printf("\nExpression is invalid\n"); 
 } 
