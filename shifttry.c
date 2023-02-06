#include<stdio.h>
#include<string.h>
int z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
int main()
{

      puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
      puts("enter input string ");
      gets(a);
      c=strlen(a);
      puts("stack \t input \t action");
      
      for(i=0,j=0;j<c;i++)
      {
        if(a[j]=='i' && a[j+1]=='d')
        {
            strcpy(act,"SHIFT ->");
            stk[i]='i';
            stk[i+1]='d';
            stk[i+2]='\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n%s\t%s\t%s id",stk,a,act);
            check();
        }
        else
        {
            strcpy(act,"SHIFT ->");
            stk[i]=a[j];
            stk[i+1]='\0';
            char c=a[j];
            a[j]=' ';
            j++;
            printf("\n%s\t%s\t%s %c",stk,a,act,c);
            check();
        }
      }
      return 0;
}

void check()
{
    
    for(z=0;z<c;z++)
    {
        if(stk[z]=='i' && stk[z+1]=='d')
        {
            strcpy(act,"E -> id");
            stk[z]='E';
            stk[z+1]='\0';
            j+=2;
            printf("\n%s\t%s\t%s",stk,a,act);
        }
    }

    for(z=0;z<c;z++)
    {
        if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
        {
            strcpy(act,"E -> E+E");
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            i-=2;
            printf("\n%s\t%s\t%s",stk,a,act);
        }
    }

}