%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int valid=1;
int yylex();	
extern char* yytext;
int yyerror(const char *s);
int tops=-1;
void display();
extern int yylineno;
extern char* yytext;
char pushvar[20];
int lnum=0;
char temp[2] = "t";
char temp2[4]="t";
int temp_i = 0;
char tmp_i[3];
int W[10000];
int F[10000];
int A[10000];
int if_top=-1;
int while_top=-1;
int for_top=-1;
int l_while = 0;
int ltop = 0;	
void ifelse4();
void ifelse3();
void ifelse2();
void ifelse1();
void for3();
void for2();
void for1();
void while3();
void while2();
void while1();
void codegen_assign();
void codegen();
void push(char *string);
int label[20];
int ops=0;
char ff[3][10];
int quadnum = 0;	
char stk[100][100];
%}
%define parse.error verbose
%start RR
%token NL PRINT WHILE FOR IF IN ELSE TRUE1 FALSE1 NUMB STRI id COPEN BROPEN BRCLOSE T_pl T_min T_mul T_div T_lt T_gt T_eq T_and T_or T_ass  T_eqeq
%left '<' '>' T_le T_ge T_eqeq T_ne 
%right T_eq T_ass
%%
RR:	{printf("\n\nIntermediate code is:\n\n");}R
	;

N:	NL
	|
	;

R: 	WHILEBODY R 
	| IFBODY R 
	| FORBODY R 
	| EXP R 
	| PRINT '('VEC')' NL R
	| BROPEN  N R BRCLOSE NL R
	| error NL R
	|
	;

WHILEBODY :	WHILE N {while1();} '(' N COND N')' {while2();} N BROPEN N R BRCLOSE{while3();} N
	;

FORBODY :	FOR N '(' N FIT IN RANGE {for1();} N ')'{for2();} N BROPEN N  R BRCLOSE{for3();} N
	;

IFBODY :	 IF N '('  N COND N  ')' {ifelse1();} N  BROPEN  NIFLADDER  
	;

NIFLADDER :  N R BRCLOSE NL{ifelse4();}
	|N R BRCLOSE NL E{ifelse3();}
	;	

E :	 ELSE {ifelse2();} N BROPEN N R BRCLOSE NL;

EXP :	OP1 RELOP OP1 {codegen();} NL
	| ID ASSIGNOP OP1 {codegen_assign();} NL
	| OP1 NL
	;

COND :	OP1 RELOP OP1 {codegen();}
	| ID ASSIGNOP OP1 {codegen_assign();}
	| OP1 LOGICOP OP1 {codegen();}
	| OP1 
	;

OP1: OP1 T_pl{strcpy(pushvar,"+");push(pushvar);} OP2 {$$=$1+$3;codegen();}
	| OP1 T_min{strcpy(pushvar,"-");push(pushvar);} OP2 {$$=$1-$3;codegen();}
	| OP2 {$$=$$;}
	;
	
OP2: OP2 T_mul{strcpy(pushvar,"*");push(pushvar);} LIT {$$=$1*$3;codegen();}
	| OP2 T_div{strcpy(pushvar,"/");push(pushvar);} LIT {$$=$1/$3;codegen();}
	| LIT {$$=$$;}
	;


LIT: ID 
	| NUM {$$=$1;}
	;

RELOP:T_lt{strcpy(pushvar,"<");push(pushvar);}
	|T_gt{strcpy(pushvar,">");push(pushvar);}
	|T_eqeq{strcpy(pushvar,"==");push(pushvar);}
	|T_le{strcpy(pushvar,"<=");push(pushvar);}
	|T_ge{strcpy(pushvar,">=");push(pushvar);}
	|T_ne{strcpy(pushvar,"!=");push(pushvar);}
	;

ASSIGNOP:T_eq{strcpy(pushvar,"=");push(pushvar);}
	|T_ass{strcpy(pushvar,"<-");push(pushvar);}
	; 

LOGICOP: T_and{strcpy(pushvar,"&&");push(pushvar);}
	| T_or{strcpy(pushvar,"||");push(pushvar);}
	;

RANGE:	NUMC':'NUMC
	| COPEN VECTOR')'
	|ID
	;



VECTOR:	VEC ',' VECTOR 
	| VEC
	;
	
VEC: 	NUM 
	| BOOL 
	| STR 
	| ID
	;



NUMC: NUMB{strcpy(ff[ops++],yytext);if(ops==2){ops=0;}};

NUM: 	NUMB{strcpy(pushvar,yytext);push(pushvar);}
	;

BOOL: 	TRUE1 
	| FALSE1
	;

STR: 	STRI
	;

FIT: id{strcpy(ff[2],yytext);};

ID: 	id{strcpy(pushvar,yytext);push(pushvar);}
	;

%%

#include <ctype.h>
int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
  	printf("\nLine no: %d \n The error is: %s\n\n",yylineno-1,s);
}

typedef struct quadruples{
		char *op;
		char *arg1;
		char *arg2;
		char *res;
	}alls;

alls q[100];


void display()
{
	printf("\n\nQuadruples\n\n");
	printf("\tResult:\t\t Operator:\t Arg1:\t\t Arg2:\t\t \n");
	for(int i=0;i<quadnum;i++)
	{
			printf("\t%s \t\t %s \t\t %s \t\t %s \t\t \n",q[i].res,q[i].op,q[i].arg1,q[i].arg2);
	}	
	
}

void push(char *string)	{
	
    strcpy(stk[++tops], string);
}

void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,stk[tops-2],stk[tops-1],stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*strlen(stk[tops-1]));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,stk[tops-1]);
    strcpy(q[quadnum].arg1,stk[tops-2]);
    strcpy(q[quadnum].arg2,stk[tops]);
    strcpy(q[quadnum].res,temp);
    quadnum++;
    tops-=2;
    strcpy(stk[tops],temp);

temp_i++;
}
void codegen_assign()
{
    printf("%s %s %s\n", stk[tops-2], stk[tops-1],stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    strcpy(q[quadnum].op, stk[tops-1]);
    strcpy(q[quadnum].arg1, stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, stk[tops-2]);
    quadnum++;
    	tops -= 2;
}

void ifelse1()
{
    lnum++;
    strcpy(temp, "T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp, tmp_i);
    printf("%s = not %s\n", temp, stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op, "not");
    strcpy(q[quadnum].arg1, stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, temp);
    quadnum++;
    printf("if %s goto L%d\n", temp, lnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op, "if");
    strcpy(q[quadnum].arg1, temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d", lnum);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
    label[++ltop] = lnum;
	A[++if_top]=lnum;
	lnum++;
}

void ifelse2()
{
    int x;
    
    x=label[ltop--];
    printf("goto L%d\n",A[if_top]+1);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op, "goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char jug[10];
    sprintf(jug,"%d", A[if_top]+1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,jug));
    quadnum++;
    printf("L%d: \n",x);
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[] = "L";
    strcpy(q[quadnum].res,strcat(l1,jug1));
    quadnum++;
    label[++ltop]=lnum;
}

void ifelse3()
{
    int y;
    y = label[ltop--];
	int tempnum=A[if_top--]+1;
	printf("L%d: \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(y+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    lnum++;
}

void ifelse4()
{
		int res=A[if_top--];
		printf("L%d:\n",res);
		q[quadnum].op = (char*)malloc(sizeof(char)*6);
    		q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    		q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    		q[quadnum].res = (char*)malloc(sizeof(char)*(res+2));
    		strcpy(q[quadnum].op,"Label");
                strcpy(q[quadnum].arg1, "NULL");
		strcpy(q[quadnum].arg2, "NULL");

    		char jug1[10];
    		sprintf(jug1,"%d",res);
    		char l1[] = "L";
    		strcpy(q[quadnum].res,strcat(l1,jug1));
    		quadnum++;
		}


void while1()
{
    lnum++;
    printf("L%d: \n",lnum++);
    
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
}



void while2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,stk[tops]);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,"not");
    strcpy(q[quadnum].arg1,stk[tops]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res,temp);
    quadnum++;
    printf("if %s goto L%d\n",temp,lnum);
    W[++while_top]=lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"if");
    strcpy(q[quadnum].arg1,temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",W[while_top]);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
 }



void while3()
{
	int tempnum=W[while_top--]-1;
    printf("goto L%d \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadnum].op,"goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[quadnum].res,strcat(l1,x1));
    quadnum++;
}

void for1()
{
    printf("%s = %s\n", ff[2],ff[0]);
    q[quadnum].op = (char*)malloc(sizeof(char));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(ff[0]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(ff[2]));
    strcpy(q[quadnum].op, "=");
    strcpy(q[quadnum].arg1, ff[0]);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res, ff[2]);
    quadnum++;
    lnum++;
    printf("L%d: \n",lnum++);    
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
}

void for2()
{

	strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
	temp_i++;
    printf("%s=%s < %s\n", temp,ff[2],ff[1]);
    q[quadnum].op = (char*)malloc(sizeof(char));
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(ff[2]));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*strlen(ff[1]));
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op, "<");
    strcpy(q[quadnum].arg1, ff[2]);
    strcpy(q[quadnum].arg2, ff[1]);
    strcpy(q[quadnum].res, temp);
    strcpy(temp2,temp);
    quadnum++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("T%d = not T%d\n",temp_i,temp_i-1);
    q[quadnum].op = (char*)malloc(sizeof(char)*4);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp2));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadnum].op,"not");
    strcpy(q[quadnum].arg1,temp2);
    strcpy(q[quadnum].arg2, "NULL");
    strcpy(q[quadnum].res,temp);
    quadnum++;
    printf("if %s goto L%d\n",temp,lnum);
    F[++for_top]=lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*3);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"if");
    strcpy(q[quadnum].arg1,temp);
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",F[for_top]);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    temp_i++;
 }

void for3()
{
	
	int tempnum=F[for_top--]-1;
    printf("goto L%d \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
    strcpy(q[quadnum].op,"goto");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[quadnum].res,strcat(l,x));
    quadnum++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[quadnum].res,strcat(l1,x1));
    quadnum++;
}

int main()
{
	extern FILE *yyin;
    yyin=fopen("a.r","r");yyparse();
	if(valid)
	{
  		printf("\n\nParsing successful\n\n");
		
	}
	else
	{
  		printf("\n\nParsing unsuccessful\n\n");
		
	}
	display();
	return 0;
}        


  
