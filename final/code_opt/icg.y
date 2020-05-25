%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int valid=1;
int glob=0;
void dispi();
int yylex();	
extern char* yytext;
int yyerror(const char *s);
int tops=-1;
int qno1=0;
void display();
extern int yylineno;
extern char* yytext;
char appendvar[20];
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
void endif();
void endif_start_else();
void start_else();
void start_if();
void end_for();
void mid_for();
void start_for();
void end1_while();
void end_while();
void start_while();
void create_node_for_eq();
void create_node();
void print1();
void icg();
void optimize1();
void optimize2();
void append(char *string);
int label[20];
int ops=0;
char ff[3][10];
int qno = 0;	
char stk[100][100];
char param[10][10];
int paramtop=-1;
int change=0;
int length_arr = 0;
int count1 = 0;
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
	| PRINT '('VEC {print1();}')'  N R
	| BROPEN  N R BRCLOSE N R
	| error N R
	|
	;

WHILEBODY :	WHILE N {start_while();} '(' N COND N')' {end_while();} N BROPEN N R BRCLOSE{end1_while();} N
	;

FORBODY :	FOR N '(' N FIT IN RANGE {start_for();} N ')'{mid_for();} N BROPEN N  R BRCLOSE{end_for();} N
	;

IFBODY :	 IF N '('  N COND N  ')' N {start_if();} N  BROPEN  NIFLADDER  
	;

NIFLADDER :  N R BRCLOSE N{endif();}
	|N R BRCLOSE N E{endif_start_else();}
	;	

E :	 ELSE {start_else();} N BROPEN N R BRCLOSE N;

EXP :	OP1 RELOP OP1 {create_node();} N
	| ID ASSIGNOP OP1 {create_node_for_eq();} N
	| OP1 N
	;

COND :	OP1 RELOP OP1 {create_node();}
	| ID ASSIGNOP OP1 {create_node_for_eq();}
	| OP1 
	;

OP1: OP1 T_pl{strcpy(appendvar,"+");append(appendvar);} OP2 {$$=$1+$3;create_node();}
	| OP1 T_min{strcpy(appendvar,"-");append(appendvar);} OP2 {$$=$1-$3;create_node();}
	| OP2 {$$=$$;}
	;
	
OP2: OP2 T_mul{strcpy(appendvar,"*");append(appendvar);} LIT {$$=$1*$3;create_node();}
	| OP2 T_div{strcpy(appendvar,"/");append(appendvar);} LIT {$$=$1/$3;create_node();}
    | OP2 T_and{strcpy(appendvar,"&&");append(appendvar);} LIT {$$=$1&&$3;create_node();}
	| OP2 T_or{strcpy(appendvar,"||");append(appendvar);} LIT {$$=$1||$3;create_node();}
	| LIT {$$=$$;}
	; 


LIT: ID 
	| NUM {$$=$1;}
	;

RELOP:T_lt{strcpy(appendvar,"<");append(appendvar);}
	|T_gt{strcpy(appendvar,">");append(appendvar);}
	|T_eqeq{strcpy(appendvar,"==");append(appendvar);}
	|T_le{strcpy(appendvar,"<=");append(appendvar);}
	|T_ge{strcpy(appendvar,">=");append(appendvar);}
	|T_ne{strcpy(appendvar,"!=");append(appendvar);}
	;

ASSIGNOP:T_eq{strcpy(appendvar,"=");append(appendvar);}
	|T_ass{strcpy(appendvar,"<-");append(appendvar);}
	; 

LOGICOP: T_and{strcpy(appendvar,"&&");append(appendvar);}
	| T_or{strcpy(appendvar,"||");append(appendvar);}
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



NUMC: NUMB{strcpy(ff[ops++],yytext);if(ops==2){ops=0;}};

NUM: 	NUMB{strcpy(appendvar,yytext);append(appendvar);}
	;

BOOL: 	TRUE1 
	| FALSE1
	;

STR: 	STRI{strcpy(appendvar,yytext);append(appendvar);}
	;

FIT: id{strcpy(ff[2],yytext);strcpy(param[++paramtop],yytext);};

ID: 	id{strcpy(appendvar,yytext);append(appendvar);}
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
		int valid;
	}alls;
alls q1[100];
alls q[100];

typedef struct element{
    int a;
    char s[20];
}ele;

ele e[100];

void display()
{glob=0;
	printf("\n\nQuadruples\n\n");
	printf("\tResult:\t\t Operator:\t Arg1:\t\t Arg2:\t\t \n");
	for(int i=0;i<qno;i++)
	{
		if(q[i].valid)
		{	strcpy(q[glob].op,q[i].op);
    strcpy(q[glob].arg1,q[i].arg1);
    strcpy(q[glob].arg2,q[i].arg2);
	q[glob].valid=q[i].valid;
    strcpy(q[glob++].res,q[i].res);

			printf(" \t%s \t\t %s \t\t %s \t\t %s \t\t\n",q[i].res,q[i].op,q[i].arg1,q[i].arg2);
		}
	}	
	
}

void append(char *string)	{
	
    strcpy(stk[++tops], string);
}

void print1(){
//printf("print(%s)\n",yytext);
printf("param %s\nCall print1, 1\npop param\n",yytext);
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(yytext));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*5);
	q[qno].valid=1;
	strcpy(q[qno].op,"param");
    strcpy(q[qno].arg1,yytext);
    strcpy(q[qno].arg2,"NULL");
    strcpy(q[qno].res,"NULL");
	qno++;
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(yytext));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*5);
	q[qno].valid=1;
	strcpy(q[qno].op,"call");
    strcpy(q[qno].arg1,"print");
    strcpy(q[qno].arg2,"1");
    strcpy(q[qno].res,"NULL");
	qno++;
q[qno].op = (char*)malloc(sizeof(char)*7);
    q[qno].arg1 = (char*)malloc(sizeof(char)*10);
    q[qno].arg2 = (char*)malloc(sizeof(char)*6);
    q[qno].res = (char*)malloc(sizeof(char)*6);
	q[qno].valid=1;
	strcpy(q[qno].op,"pop");
    strcpy(q[qno].arg1,"param");
    strcpy(q[qno].arg2,"NULL");
    strcpy(q[qno].res,"NULL");
	qno++;
}

void create_node()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,stk[tops-2],stk[tops-1],stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*strlen(stk[tops-1]));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,stk[tops-1]);
    strcpy(q[qno].arg1,stk[tops-2]);
    strcpy(q[qno].arg2,stk[tops]);
    strcpy(q[qno].res,temp);
    qno++;
    tops-=2;
    strcpy(stk[tops],temp);

temp_i++;
}
void create_node_for_eq()
{
    printf("%s %s %s\n", stk[tops-2], stk[tops-1],stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(stk[tops-2]));
    q[qno].valid=1;
    strcpy(q[qno].op, stk[tops-1]);
    strcpy(q[qno].arg1, stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, stk[tops-2]);
    qno++;
    	tops -= 2;
}

void start_if()
{
    lnum++;
    strcpy(temp, "T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp, tmp_i);
    printf("%s = not %s\n", temp, stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op, "not");
    strcpy(q[qno].arg1, stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, temp);
    qno++;
    printf("if %s goto L%d\n", temp, lnum);
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op, "if");
    strcpy(q[qno].arg1, temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d", lnum);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
    label[++ltop] = lnum;
	A[++if_top]=lnum;
	lnum++;
}

void start_else()
{
    int x;
    
    x=label[ltop--];
    printf("goto L%d\n",A[if_top]+1);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op, "goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char jug[10];
    sprintf(jug,"%d", A[if_top]+1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,jug));
    qno++;
    printf("L%d: \n",x);
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(x+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");

    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[] = "L";
    strcpy(q[qno].res,strcat(l1,jug1));
    qno++;
    label[++ltop]=lnum;
}

void endif_start_else()
{
    int y;
    y = label[ltop--];
	int tempnum=A[if_top--]+1;
	printf("L%d: \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(y+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    lnum++;
}

void endif()
{
		int res=A[if_top--];
		printf("L%d:\n",res);
		q[qno].op = (char*)malloc(sizeof(char)*6);
    		q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    		q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    		q[qno].res = (char*)malloc(sizeof(char)*(res+2));
                q[qno].valid=1;
    		strcpy(q[qno].op,"Label");
                strcpy(q[qno].arg1, "NULL");
		strcpy(q[qno].arg2, "NULL");

    		char jug1[10];
    		sprintf(jug1,"%d",res);
    		char l1[] = "L";
    		strcpy(q[qno].res,strcat(l1,jug1));
    		qno++;
		}


void start_while()
{
    lnum++;
    printf("L%d: \n",lnum++);
    
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
}



void end_while()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = not %s\n",temp,stk[tops]);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(stk[tops]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,"not");
    strcpy(q[qno].arg1,stk[tops]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res,temp);
    qno++;
    printf("if %s goto L%d\n",temp,lnum);
    W[++while_top]=lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"if");
    strcpy(q[qno].arg1,temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",W[while_top]);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
 }



void end1_while()
{
	int tempnum=W[while_top--]-1;
    printf("goto L%d \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[qno].res,strcat(l1,x1));
    qno++;
}

void start_for()
{
    printf("%s = %s\n", ff[2],ff[0]);
    q[qno].op = (char*)malloc(sizeof(char));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(ff[0]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(ff[2]));
    strcpy(q[qno].op, "=");
    strcpy(q[qno].arg1, ff[0]);
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res, ff[2]);
    q[qno].valid=1;
    qno++;
    lnum++;
    printf("L%d: \n",lnum++);    
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[] = "L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
}

void mid_for()
{

	strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
	temp_i++;
    printf("%s=%s < %s\n", temp,ff[2],ff[1]);
    
    q[qno].op = (char*)malloc(sizeof(char));
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(ff[2]));
    q[qno].arg2 = (char*)malloc(sizeof(char)*strlen(ff[1]));
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op, "<");
    strcpy(q[qno].arg1, ff[2]);
    strcpy(q[qno].arg2, ff[1]);
    
    strcpy(q[qno].res, temp);
    qno++;

    sprintf(tmp_i, "%d", temp_i);
	
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[qno].arg1,temp);
	    strcpy(temp,"T");
    strcat(temp,tmp_i);
    printf("T%d = not T%d\n",temp_i,temp_i-1);
    q[qno].op = (char*)malloc(sizeof(char)*4);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].valid=1;
    strcpy(q[qno].op,"not");
    
    
    strcpy(q[qno].arg2, "NULL");
    strcpy(q[qno].res,temp);
    qno++;
    printf("if %s goto L%d\n",temp,lnum);
    F[++for_top]=lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*3);
    q[qno].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"if");
    strcpy(q[qno].arg1,temp);
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",F[for_top]);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    temp_i++;
 }

void end_for()
{

    	strcpy(temp, "T");
	sprintf(tmp_i, "%d", temp_i);
	strcat(temp, tmp_i);
	printf("\t%s = %s + 1\n",temp,param[paramtop]);
	q[qno].op = (char*)malloc(sizeof(char)*2);
	q[qno].arg1 = (char*)malloc(sizeof(char)*5);
	q[qno].arg2 = (char*)malloc(sizeof(char)*5);
	q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[qno].valid=1;
	strcpy(q[qno].op,"+");
	strcpy(q[qno].arg1,param[paramtop]);
	strcpy(q[qno].arg2,"1");
	strcpy(q[qno].res,temp);
	qno++;
	temp_i++;

	printf("\t%s = %s\n",param[paramtop],temp);
	q[qno].op = (char*)malloc(sizeof(char)*2);
	q[qno].arg1 = (char*)malloc(sizeof(char)*5);
	q[qno].arg2 = (char*)malloc(sizeof(char)*5);
	q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[qno].valid=1;
	strcpy(q[qno].op,"=");
	strcpy(q[qno].arg1,temp);
	
	strcpy(q[qno].arg2,"NULL");
	strcpy(q[qno].res,param[paramtop]);
	qno++;
	paramtop--;
	
    int tempnum=F[for_top--]-1;
    printf("goto L%d \n",tempnum);
    q[qno].op = (char*)malloc(sizeof(char)*5);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(l_while+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"goto");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x[10];
    sprintf(x,"%d",tempnum);
    char l[]="L";
    strcpy(q[qno].res,strcat(l,x));
    qno++;
    printf("L%d: \n",tempnum+1);lnum++;
    q[qno].op = (char*)malloc(sizeof(char)*6);
    q[qno].arg1 = (char*)malloc(sizeof(char)*5);
    q[qno].arg2 = (char*)malloc(sizeof(char)*5);
    q[qno].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[qno].valid=1;
    strcpy(q[qno].op,"Label");
    strcpy(q[qno].arg1, "NULL");
    strcpy(q[qno].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[qno].res,strcat(l1,x1));
    qno++;
}


void dispi(){
int i=0;
for(i=0;i<qno;i++)
		{
			if(q[i].valid)
			{
				if(strcmp(q[i].op,"Label")==0)
				{
					printf("%s:\n",q[i].res);
				}
				else if(strcmp(q[i].op,"goto")==0)
				{	
					printf("\tgoto %s\n",q[i].res);
				}
				else if(strcmp(q[i].op,"not")==0)
				{	
					printf("\t%s = not %s\n",q[i].res,q[i].arg1);
				}
				else if(strcmp(q[i].op,"if")==0)
				{	
					printf("\tif %s goto %s\n",q[i].arg1,q[i].res);
				}
				else if(strcmp(q[i].op,"=")==0)
				{	
					printf("\t%s = %s\n",q[i].res,q[i].arg1);
				}
				else if(strcmp(q[i].op,"param")==0){
					printf("\tparam %s\n\tcall print, 1\n\tpop param\n",q[i].arg1);
				}
				else if (strcmp(q[i].op,"call")==0 || strcmp(q[i].op,"pop")==0){
continue;}
				else
				{
					printf("\t%s = %s %s %s\n",q[i].res,q[i].arg1,q[i].op,q[i].arg2);
				}
					
			}
		}

}

void optimize1()
{
	char *targ1,*targ2,*tres,*topr,*res2;
	printf("\n");
	int i=0;
	for(i=0;i<qno;i++)
	{
          	int a=q[i].arg1[0];
		
		if((!(strcmp(q[i].arg2,"NULL")==0)) && (q[i].valid))
		{
			targ1=(char*)malloc(sizeof(char)*strlen(q[i].arg1));
			targ2=(char*)malloc(sizeof(char)*strlen(q[i].arg2));
			tres=(char*)malloc(sizeof(char)*strlen(q[i].res));
			topr=(char*)malloc(sizeof(char)*strlen(q[i].op));
			strcpy(targ1,q[i].arg1);
                        
			strcpy(targ2,q[i].arg2);
			strcpy(tres,q[i].res);
			strcpy(topr,q[i].op);
			int p=i+1;
			while( p<qno && !((strcmp(q[p].res,tres)==0) || (strcmp(q[p].res,targ1)==0) || (strcmp(q[p].res,targ2)==0))  ) 
			{
				if( (strcmp(q[p].arg1,targ1)==0) && (strcmp(q[p].arg2,targ2)==0) && (strcmp(q[p].op,topr)==0) )
				{
					q[p].valid=0;
					change=1;
					res2=(char*)malloc(sizeof(char)*strlen(q[p].res));
					strcpy(res2,q[p].res);
					int h=p+1;
					while(h<qno && !(strcmp(q[h].res,res2)==0))
					{
						if(strcmp(q[h].arg1,res2)==0)
						{
							//printf("%d arg1\n",h);
							strcpy(q[h].arg1,tres);
						}
						if(strcmp(q[h].arg2,res2)==0)
						{
							//printf("%d arg2\n",h);
							strcpy(q[h].arg2,tres);
						}
						h=h+1;
					}
					if(h!=qno)
					{
						if(strcmp(q[h].arg1,res2)==0)
						{
							strcpy(q[h].arg1,tres);
						}
						if(strcmp(q[h].arg2,res2)==0)
						{
							strcpy(q[h].arg2,tres);
						}		
					}
				}
				p=p+1;
			}
			
		}
	}
printf("After 1st stage:\n");
    
	display();
qno=glob;

for(i=0;i<qno;i++)
{
 strcpy(e[i].s,q[i].res);
 e[i].a = 0;
 count1++;
 length_arr++;
}
    int it=1;
    do{
        for(i=0;i<qno;i++)
        {
                strcpy(e[i].s,q[i].res);
                e[i].a = 0;
        }

        
        int k = 0;
        for(i=0;i<qno;i++)
        {
                if(strcmp(q[i].op,"pop")==0 ||strcmp(q[i].op,"param")==0 ||strcmp(q[i].op,"call")==0 )
                {e[i].a = 1;
                k++;
            }
        }
        count1 = 0;
        
        for(int i=0;i<length_arr;i++){
            char* str = (char*)malloc(sizeof(e[i].s));
            str = e[i].s;
            count1+=1;
            for(int j=0;j<qno;j++){
                char arg1[20],arg2[20];
                strcpy(arg1,q[j].arg1);
                strcpy(arg2,q[j].arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0 || e[i].s[0]=='L')){  
                    e[i].a = 1;  
                    k++;
                    break;
                }
            }
        
            for(int j=0;j<qno1;j++){
                
                char arg1[20],arg2[20];
                strcpy(arg1,q1[j].arg1);
                strcpy(arg2,q1[j].arg2);
                //printf("%s %s %s\n",str,arg1,arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0)){  
                    k++;
                    e[i].a = 1;  
                    break;
                }
            }

        }


        length_arr = k;
        int l = 0;
        int g=0;
        if(length_arr!=count1){
            change=1;
            for(int i=0;i<qno-1;i++){   
            
                if(strcmp(q[i].op,"param")==0 || strcmp(q[i].op,"call")==0 || strcmp(q[i].op,"pop")==0 || e[i].a==1){
                    strcpy(q[l].op,q[i].op);
                    strcpy(q[l].arg1,q[i].arg1);
                    strcpy(q[l].arg2,q[i].arg2);
                    strcpy(q[l++].res,q[i].res);
                }                    
                                
                if(e[i].a==1 && e[i+1].a==0 && strcmp(q[i].arg2,"NULL")!=0 && e[i+1].s[0]!='T'){
                    
                    q1[g].op = (char*)malloc(sizeof(char)*100);
                    q1[g].arg1 = (char*)malloc(sizeof(char)*100);
                    q1[g].arg2 = (char*)malloc(sizeof(char)*100);
                    q1[g].res = (char*)malloc(sizeof(char)*100);
                    strcpy(q1[g].op,q[i].op);
                    strcpy(q1[g].arg1,q[i].arg1);
                    strcpy(q1[g].arg2,q[i].arg2);
                    strcpy(q1[g++].res,q[i].res);
                }
            }

        if(e[qno-1].a==1){
            strcpy(q[l].op,q[qno-1].op);
            strcpy(q[l].arg1,q[qno-1].arg1);
            strcpy(q[l].arg2,q[qno-1].arg2);
            strcpy(q[l++].res,q[qno-1].res);		
        }
            }
        if(length_arr!=count1){
            qno = l;}
            qno1=g;
        length_arr=qno;
            for(int z=0;z<qno;z++){
        strcpy(e[z].s,q[z].res);
                e[z].a = 0;
        }  
	}while(length_arr!=count1);
     
	icg();
}

void icg()
{
	if(change==1)
	{
		printf("Optimized Intermidiate code is:\n\n");
		int i;
		dispi();
		display();
	}
	else
	{
		printf("No optimization can be performed\n\n\n");
		dispi();
		display();
	}
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
	optimize1();
	return 0;
}        


  
