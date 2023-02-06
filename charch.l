%{
/* Definition section */
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
extern int flag;
%}

/* Rule Section */
%%
"char" {printf("hi");
    return CHAR;}

[\t] ;

[\n] return 0;
[a-zA-Z] {printf("hi");
    return ID;}

'\''[a-zA-Z]+'\'' {printf("hi");
   return CHARLITERAL;}



. {
	yyerror();
}

%%

int yywrap()
{
return 1;
}

