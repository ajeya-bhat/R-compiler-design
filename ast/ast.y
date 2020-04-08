
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

typedef struct Abstract_syntax_tree
{
	char *name;
	struct Abstract_syntax_tree *left;
	struct Abstract_syntax_tree *right;
}node;

extern int yylineno;
extern struct var symtab[100];
extern int symcount;
node* buildTree(char *op,node *left,node *right);
void update (char* token,char* value);
void printTree(node *tree);

extern void insertIntoSym(char *text,int nm,int scp);
%}

%start RR
%token ID NUM T_lt T_gt T_lteq T_gteq T_neq T_eqeq T_pl T_min T_mul T_div T_and T_or T_not T_eq T_ass T_BRCLOSE T_BROPEN  WHILE MAINTOK BREAK CONTINUE IF ELSE PRINT STRING FOR IN ARRAY
%locations
%left T_lt T_gt
%left T_pl T_min
%left T_mul T_div
%%

RR: R {printf("\n");printTree($1);printf("\n");printf("ACCEPTED");} | error "\n" ;

R
      : R statement  {$$ = buildTree("STATEMENTS",$1,$2);}
      | R LOOPS  {$$ = buildTree("STATEMENTS",$1,$2);}
      | statement {$$ = buildTree("STATEMENT",$1,NULL);}
      | LOOPS {$$ = $1;}
      ;

LOOPS
      : WHILE '(' COND ')' LOOPBODY  {$$ = buildTree("WHILE",$3,$5);}
      | FOR '(' LIT IN FIT ')' LOOPBODY {$$ = buildTree("FOR",buildTree("IN",$3,$5),$7);}  
      | IF '(' COND ')' LOOPBODY   {$$ = buildTree("IF",$3,$5);}
      | IF '(' COND ')' LOOPBODY ELSE LOOPBODY  {$$ = buildTree("IF-ELSE",buildTree("IF",$3,$5),buildTree("Else",$7,NULL));}
      ;

FIT
	  : ID {$$ = buildTree((char *)yylval,0,0);}| ARR {$$ = buildTree((char *)yylval,0,0);};

LOOPBODY
  	  : T_BROPEN R T_BRCLOSE {$$ = buildTree("LOOP-BODY",$2,NULL);}
  	  | statement {$$ = $1;}
  	  ;

ARR : ARRAY ARRR ')' ;  

ARRR: ARRR ',' NUM  | NUM  ;

statement
      : ASSIGN_EXPR  {$$ = $1;}
      | ARITH_EXPR  {$$=$1;}
      | TERNARY_EXPR  {$$=$1;}
      | PRNT  {$$=$1;}
      ;




COND
      : LIT RELOP LIT  {$$=buildTree($2,$1,$3);}
      | LIT  {$$=$1;}
      | LIT RELOP LIT bin_boolop LIT RELOP LIT  {
          $$ = buildTree($4,buildTree($2,$1,$3),buildTree($6,$5,$7));
      }
      | un_boolop '(' LIT RELOP LIT ')'  
      | un_boolop LIT RELOP LIT  
      | LIT bin_boolop LIT  {$$ = buildTree($2,$1,$3);}
      | un_boolop '(' LIT ')'  
      | un_boolop LIT  
      ;



ASSIGN_EXPR
      : VAR T_eq ARITH_EXPR  {$$=buildTree("=",$1,$3);}
      	| VAR T_ass ARITH_EXPR  {$$=buildTree($2,$1,$3);};

ARITH_EXPR
      : LIT  {$$=$1;}
      | ARR  
      | LIT T_pl ARITH_EXPR  {$$=atoi($1) + atoi($3);$$=buildTree("+",$1,$3) ;}
	| LIT T_min ARITH_EXPR  {$$=atoi($1) - atoi($3);$$=buildTree("-",$1,$3) ;}
	| LIT T_mul ARITH_EXPR  {$$=atoi($1) * atoi($3);$$=buildTree("*",$1,$3); }
	| LIT T_div ARITH_EXPR  {$$=atoi($1) / atoi($3);$$=buildTree("/",$1,$3); }
      | LIT bin_boolop ARITH_EXPR  {$$=buildTree($2,$1,$3);};
      | un_boolop ARITH_EXPR  
      | LIT un_in LIT  {$$=buildTree($2,$1,$3);}
      ;

VAR : ID    {$$=buildTree((char *)yylval,0,0);};

TERNARY_EXPR
      : '(' COND ')' '?' statement ':' statement  {$$ = buildTree("?",$2,buildTree(":",$5,$7));}
      ;

PRNT :  PRINT '(' PRINTEXPR ')' | PRINT '(' STRING ')' ;

PRINTEXPR : LIT  {$$=$1;};

LIT
      : ID  {$$ = buildTree((char *)yylval,0,0);}
      | NUM  {$$ = buildTree((char *)yylval,0,0);}
      ;

RELOP
      : T_lt   { $$ = "<";}
      | T_gt   { $$ = ">";}
      | T_lteq { $$ = "<=";}
      | T_gteq { $$ = ">=";}  
      | T_neq  { $$ = "!=";} 
      | T_eqeq { $$ = "==";}  
      ;

bin_boolop
      : T_and  { $$ = "&&";}
      | T_or   { $$ = "||";}
      ;

un_boolop
      : T_not   { $$ = "!";}
      ;

un_in
      : IN  { $$ = "in";}
      ;
%%


int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
	display();
  	printf("\n\nLine no: %d \n The error is: %s\n",yylineno,s);
}

node* buildTree(char *op,node *left,node *right)
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(op)+1);
	strcpy(newstr,op);
	new->left=left;
	new->right=right;
	new->name=newstr;
	return (new);
}

void printTree(node *tree)
{
	if(tree->left || tree->right)
		printf("(");
	printf(" %s ",tree->name);
	if(tree->left)
		printTree(tree->left);
	if(tree->right)
		printTree(tree->right);
	if(tree->left || tree->right)
		printf(")");
	
}

int main()
{
	st[0]=0;
	top=0;
	count=0;
	extern FILE *yyin;
        yyin=fopen("a1.r","r");
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
