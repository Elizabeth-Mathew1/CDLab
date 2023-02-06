%{
  #include<stdio.h>
  #include "y.tab.h"
%}
%%
"while" return W;
[=] return EQ;
">=" return REL;
"<=" return REL;
[>,<] return REL;
[-,+,*,/] return OP;
[a-zA-Z][a-zA-Z0-9]* return ID;
[0-9]+ return NUM;
[\t] ;
. return yytext[0];
\n return 0;
%%
int yywrap()
{
    return 1;
}