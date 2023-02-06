%{
#include<stdio.h>
%}
%token TYPE IF ELSE COMMA SC ID RELOP OP LIT NL OPL OPB
%token LPAREN RPAREN
%token LBRACE RBRACE
%%
start: IF LPAREN ID RELOP ID RPAREN code ile{printf("Valid");}
ile: ELSE code NL| NL
code: line SC| LBRACE block RBRACE
line: line ID | ID;
block: block line SC NL| line SC NL;
%%
int yyerror(char *s){printf("\nError");
                    return 1;}
main(){
    yyparse();
}