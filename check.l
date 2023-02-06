%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *yytext;
%}

%start input

%token CHAR
%token ID
%token STRING

%%

input:
    | input statement
    ;

statement:
    CHAR ID '=' STRING ';'
    {
        printf("Declared character variable '%s' with value '%s'\n", yytext, yylval);
    }
    ;

CHAR:
    'char'
    ;

ID:
    [a-zA-Z][a-zA-Z0-9_]*
    ;

STRING:
    '\'' [a-zA-Z0-9_]* '\''
    ;

%%

int yywrap(void) {
    return 1;
}

int main(void) {
    yyparse();
    return 0;
}
