%{
    #include<stdio.h>
    int flag=0;
%}

%token NUMBER

%left '+' '-'

%left '*' '/' '%'

%left '(' ')'

%%
ArithmeticExpression: E{
    printf("Result is %d",$$);
    return 0;
};
E:E'+'E { $$ = $1+$3;} 
|E'-'E { $$ = $1-$3;} 
|E'*'E { $$ = $1*$3;} 
|E'/'E { $$ = $1/$3;} 
| NUMBER {$$=$1;} 
;

%%
void main()
{
    yyparse();
}
int yyerror(const char* s)
{printf("\nError");
return 1;}