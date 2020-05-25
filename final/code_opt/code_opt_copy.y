%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int valid=1;
int yylex();	
extern char* yytext;
int yyerror(const char *s);
int tops=-1;
int quadnum1=0;
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
void print1();
void icg();
void optimize();
void push(char *string);
int label[20];
int ops=0;
char ff[3][10];
int quadnum = 0;	
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
    | 
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

FIT: id{strcpy(ff[2],yytext);strcpy(param[++paramtop],yytext);};

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
{
	printf("\n\nQuadruples\n\n");
	printf("\tResult:\t\t Operator:\t Arg1:\t\t Arg2:\t\t \n");
	for(int i=0;i<quadnum;i++)
	{
		if(q[i].valid)
		{
			printf("%d\t%s \t\t %s \t\t %s \t\t %s \t\t\n",i,q[i].res,q[i].op,q[i].arg1,q[i].arg2);
		}
	}	
	
}

void push(char *string)	{
	
    strcpy(stk[++tops], string);
}

void print1(){
printf("print(%s)\n",yytext);
q[quadnum].op = (char*)malloc(sizeof(char)*7);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*strlen(yytext));
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*5);
	q[quadnum].valid=1;
	strcpy(q[quadnum].op,"print");
    strcpy(q[quadnum].arg1,yytext);
    strcpy(q[quadnum].arg2,"NULL");
    strcpy(q[quadnum].res,"NULL");
	quadnum++;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
                q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
    quadnum++;
    lnum++;
    printf("L%d: \n",lnum++);    
    q[quadnum].op = (char*)malloc(sizeof(char)*6);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(lnum+2));
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
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

    	strcpy(temp, "T");
	sprintf(tmp_i, "%d", temp_i);
	strcat(temp, tmp_i);
	printf("\t%s = %s + 1\n",temp,param[paramtop]);
	q[quadnum].op = (char*)malloc(sizeof(char)*2);
	q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
	q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
	q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[quadnum].valid=1;
	strcpy(q[quadnum].op,"+");
	strcpy(q[quadnum].arg1,param[paramtop]);
	strcpy(q[quadnum].arg2,"1");
	strcpy(q[quadnum].res,temp);
	quadnum++;
	temp_i++;

	printf("\t%s = %s\n",param[paramtop],temp);
	q[quadnum].op = (char*)malloc(sizeof(char)*2);
	q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
	q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
	q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
	q[quadnum].valid=1;
	strcpy(q[quadnum].op,"=");
	strcpy(q[quadnum].arg1,temp);
	strcpy(q[quadnum].arg2,"NULL");
	strcpy(q[quadnum].res,param[paramtop]);
	quadnum++;
	paramtop--;
	
    int tempnum=F[for_top--]-1;
    printf("goto L%d \n",tempnum);
    q[quadnum].op = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg1 = (char*)malloc(sizeof(char)*5);
    q[quadnum].arg2 = (char*)malloc(sizeof(char)*5);
    q[quadnum].res = (char*)malloc(sizeof(char)*(l_while+2));
    q[quadnum].valid=1;
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
    q[quadnum].valid=1;
    strcpy(q[quadnum].op,"Label");
    strcpy(q[quadnum].arg1, "NULL");
    strcpy(q[quadnum].arg2, "NULL");
    char x1[10];
    sprintf(x1,"%d",tempnum+1);
    char l1[]="L";
    strcpy(q[quadnum].res,strcat(l1,x1));
    quadnum++;
}

void optimize()
{
	char *targ1,*targ2,*tres,*topr,*res2;
	printf("\n\n");
	int i=0;
	for(i=0;i<quadnum;i++)
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
			while( p<quadnum && !((strcmp(q[p].res,tres)==0) || (strcmp(q[p].res,targ1)==0) || (strcmp(q[p].res,targ2)==0))  ) 
			{
				if( (strcmp(q[p].arg1,targ1)==0) && (strcmp(q[p].arg2,targ2)==0) && (strcmp(q[p].op,topr)==0) )
				{
					q[p].valid=0;
					change=1;
					res2=(char*)malloc(sizeof(char)*strlen(q[p].res));
					strcpy(res2,q[p].res);
					int h=p+1;
					while(h<quadnum && !(strcmp(q[h].res,res2)==0))
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
					if(h!=quadnum)
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
        for(i=0;i<quadnum;i++)
	    {
             strcpy(e[i].s,q[i].res);
             e[i].a = 0;
             if(e[i].s[0]=='L'){
		e[i].a = 1;
	     }
             count1++;
             length_arr++;
        }
        int it=1;
        do{
        for(i=0;i<quadnum;i++)
	    {

             strcpy(e[i].s,q[i].res);
             //printf("%s",e[i].s);
             e[i].a = 0;
        }
		count1 = 0;
        int k = 0;
        //printf("%d\n\n",length_arr);
        for(int i=0;i<length_arr;i++){
            char* str = (char*)malloc(sizeof(e[i].s));
            str = e[i].s;count1+=1;
            
            for(int j=0;j<quadnum;j++){
                
                char arg1[20],arg2[20];
                strcpy(arg1,q[j].arg1);
                strcpy(arg2,q[j].arg2);
                //printf("%s %s %s\n",str,arg1,arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0)){  
                    e[i].a = 1;  
		k++;
                    break;
                }
            }

			for(int j=0;j<quadnum1;j++){
                
                char arg1[20],arg2[20];
                strcpy(arg1,q1[j].arg1);
                strcpy(arg2,q1[j].arg2);
                printf("%s %s %s\n",str,arg1,arg2);
                if(e[i].a==0 && (strcmp(str,arg1)==0 || strcmp(str,arg2)==0)){  
                    k++;
                    e[i].a = 1;  
                    break;
                }
            }printf("\n");
			
        }    
            length_arr = k;
            //printf("%d\n\n",quadnum);
            int l = 0;
			int g=0;
            if(length_arr!=count1){
                change=1;
				
                for(int i=0;i<quadnum-1;i++){
                    
                    if(e[i].a==1 && e[i+1].a==1){
                        strcpy(q[l].op,q[i].op);
                        strcpy(q[l].arg1,q[i].arg1);
                        strcpy(q[l].arg2,q[i].arg2);
                        strcpy(q[l++].res,q[i].res);
                    }
             
					if(e[i].a==1 && e[i+1].a==0){

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
	//printf("e[quad]:%d\n",e[quadnum-1].a);
				if(e[quadnum-1].a==1){
					strcpy(q[l].op,q[quadnum-1].op);
                        strcpy(q[l].arg1,q[quadnum-1].arg1);
                        strcpy(q[l].arg2,q[quadnum-1].arg2);
                        strcpy(q[l++].res,q[quadnum-1].res);		
				}
            }
		if(length_arr!=count1){
            quadnum = l;}
			//printf("%d quadnum here\n",quadnum);
			quadnum1=g;
		length_arr=quadnum;
            for(int z=0;z<quadnum;z++){
		strcpy(e[z].s,q[z].res);
                e[z].a = 0;
	    }
            //printf("\nEnd it %d\n",it++);
	}while(length_arr!=count1);
        
        
	printf("\n\n");
	icg();
}

void icg()
{
	if(change==1)
	{
		printf("Optimized Intermidiate code is:\n\n");
		int i;
		for(i=0;i<quadnum;i++)
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
				else if(strcmp(q[i].op,"print")==0){
					printf("\t%s(%s)\n",q[i].op,q[i].arg1);
				}
				else
				{
					printf("\t%s = %s %s %s\n",q[i].res,q[i].arg1,q[i].op,q[i].arg2);
				}
					
			}
		}
		display();
	}
	else
	{
		printf("No optimization can be performed\n\n\n");
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
	optimize();
	return 0;
}        


  
