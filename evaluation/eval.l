%{ 
    /* Definition section*/
    #include "y.tab.h" 
    extern yylval; 
 
%} 
  
%% 
[0-9]+ {yylval=atoi(yytext);return NUMBER;} 
[a-zA-Z]+ {yylval = strdup(yytext);return ID;} 
"=" {return T_eq;}
[\t]+ ; 
\n {return NL;} 
. {return yytext[0];} 
  
%%  
