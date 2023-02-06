%{
  #include<stdio.h>
  #include<stdlib.h>
  int flag=0;
%}
%token W REL ID NUM OP EQ
%%
start: W C B {printf("\nValid while block\n");}
     ;
C: '('E')'
    ;
E: ID REL ID
  | ID REL NUM
  ;
B: '{' S ';' '}' 
  ;
S: ID EQ ID OP ID
  | ID EQ ID OP NUM
  | ID
  ;
%%
void main()
{
    printf("\nEnter the while block\n");
    yyparse();
}
int yyerror(const char* s)
{
    flag=1;
    printf("\n Invalid expression\n");
    return 1;
}