%{
    #include<stdio.h>
%}

%token WHILE LPAREN RPAREN ID RELOP
%token SC NL RBRACE LBRACE

%%
    start: WHILE LPAREN ID RELOP ID RPAREN code NL {printf("Valid");
                                                    return 0;}
    code: line SC|LBRACE block RBRACE
    block: NL block line SC NL| NL line SC NL
    line: line ID | ID


%%
int yyerror(const char* s){printf("\nError");
                            return 1;}
main(){
    yyparse();
}