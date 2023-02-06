%{
#include<stdio.h>
#include"y.tab.h"
%}

%%
while return WHILE;
\( return LPAREN;
\) return RPAREN;
[a-zA-Z0-9]+ return ID;
[<,>,<=,>=,==,!=] return RELOP;
"{" return LBRACE;
"}" return RBRACE;
";" return SC;
"\t" ;
" " ;
"\n" return NL;
. {
    yyerror();
}
%%
int yywrap(){
    return 1;
}

