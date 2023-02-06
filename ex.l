/* Elizabeth Mary
 CS7A
 26
 Definitions section */
 
%{
#include<stdio.h>
#include<string.h>
%}

%%
(100|001|000)+  { printf("The input follows the regular expression conditions!\n");} 

.* {printf("Not a match!\n");}
%%

int yywrap(void) {
  return 1;
}
  
int main()
{   
    while(1){
    printf("Enter expression: ");
    yylex();
    }
  
    return 0;
}
