#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[50];
int i, error, ip;

void E()
{
    if (input[0] == 'c' && input[1] == 'h' && input[2] == 'a' && input[3] == 'r' && input[4] == ' ')
    {
        ip = 5;
        A();
    }
    else
    {
        error++;
    }
}

void A()
{
    while (isalpha(input[ip]))
    {
        ip++;
        
    }
    if (input[ip] == '=')
    {
        ip++;
        T();
    }
    else if (input[ip] == '[')
    {
        ip++;
        F();
    }
    else if(input[ip] == ';'){
        return;
    }
}
void T()
{
    if (input[ip] == '\'')
    {
        while (isalnum(input[ip]))
        {
            ip++;
        }
    }
    if (input[ip] == '\'')
    {
        ip++;
    }
    else
    {
        error++;
    }
    if (input[ip] == ';')
    {
        if (error ==0 ){
            printf("Accepted");
            exit(0);
        }
        return;
    }
    else if (input[ip] == ',')
    {
        ip++;
        A();
    }
}

void F()
{
    if (isdigit(input[ip]))
        ip++;
    if (input[ip] == ']')
    {
        ip++;
        if (input[ip] == '=')
        {
            ip++;
            if (input[ip] == '{')
            {
                ip++;
                while (1)
                {
                    if (input[ip] == '\'' || isalnum(input[ip]) || input[ip] == ',')
                        ip++;
                    else
                        break;
                }
                if (input[ip] == '}')
                {
                    ip++;
                    if (input[ip] == ';')
                    {
                        if (error == 0) {
                            printf("Accepted\n");
                            exit(0);
                        }
                    }
                    else if (input[ip] == ',')
                    {
                        A();
                    }
                }
            }
            else
            {
                error++;
            }
        }
    }
}

void main()
{
    i = 0;
    error = 0;
    printf("Enter the declaration : ");
    fgets(input, 50, stdin);
    E();
    if (error == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");
}
