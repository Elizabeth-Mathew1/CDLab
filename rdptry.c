#include<stdio.h>
#include<string.h>

int E(),Edash(),T(),Tdash(),F();

char *ip,str[50];

int main()
{
    printf("\nEnter the string: ");
    scanf("%s",str);
    ip=str;
    printf("\nINPUT\t\tACTION\n---------------------\n");
    if(E() && *ip=='\0')
        printf("String is successfully parsed!");
    else
        printf("Error in parsing!!");
    return 0;
}
int E()
{
    printf("%s\tE->TE' \n",ip);
    if(T())
    {
        if(Edash())
            return 1;
        else    
            return 0;
    }
    else
        return 0;
}
int Edash()
{
    if(*ip=='+')
    {
        
        printf("%s\tE'->+TE' \n",ip);
        ip++;
        if(T())
        {
            if(Edash())
                return 1;
            else
                return 0;
        }
        else
            return 0;
        
    }
    else
    {
        printf("%s\tE'->^ \n",ip);
        return 1;
    }

}
int T()
{
    printf("%s\tT->FT' \n",ip);
    if(F())
    {
        if(Tdash())
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int Tdash()
{
    if(*ip=='*')
    {
        printf("%s\tT'->*FT' \n",ip);
        ip++;
        if(F())
        {
            if(Tdash())
                return 1;
            else    
                return 0;
        }
        else
            return 0;
    }
        else
        {
            printf("%s\tT'->^\n",ip);
            return 1;
        }
    
}
int F()
{
    if(*ip=='(')
    {
        printf("%s\tF->(E)\n",ip);
        ip++;
        if(E())
        {
            if(*ip==')')
            {
                printf("%s\tF->(E)\n",ip);
                ip++;
                return 1;
            }
            else 
                return 0;
        }
        else
            return 0;
    }
    else if(*ip=='i')
    {
        printf("%s\tF->i\n",ip);
        ip++;
        return 1;
    }
}