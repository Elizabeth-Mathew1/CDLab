%{
/* Definition section */
#include<stdio.h>
int flag=0;
int yylex();
void yyerror(const char *s);
%}

%token CHAR APOS ID CHARLITERAL

%left '='

/* Rule Section */
%%

Statement: S{
    if(flag==0)
        printf("Successful!");
    return 0;
}

S: CHAR ID '=' CHARLITERAL { flag =0;}
    | CHAR ID '=' error { flag = 1; }
    | error { flag = 1; }
;

%%

//driver code
void main()
{
printf("\nEnter Any Expression: ");
yyparse();

}

void yyerror(const char *s)
{
printf("Error: %s\n", s);
flag=1;
}

