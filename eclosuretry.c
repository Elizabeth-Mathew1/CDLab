#include<stdio.h>
#include<string.h>
char result[20][3];
void addstate(char state[3],int i)
{
    strcpy(result[i],state);
}
void display(int limit)
{
    printf("Eclosure of %s : {",result[0]);
    for(int i=0;i<limit;i++)
    {
        printf("%s ",result[i]);
    }
    printf("}\n");

}
int main()
{
    int n;
    char state[3],state1[3],state2[3],input[3],temp[20][3],copy[3];
    printf("\n Enter the number of states whose eclosure is to be found:");
    scanf("%d",&n);
    printf("\nEnter the states whose eclosure is to be found:");
    for(int i=0;i<n;i++)
    {
        scanf("%s",temp[i]);

    }
    for(int k=0;k<n;k++)
    {
        int i=0;
        strcpy(state,temp[k]);
        strcpy(copy,temp[k]);
        FILE *INPUT;
        INPUT=fopen("input.txt","r");
        addstate(state,i++);
        while(1)
        {
            int end=fscanf(INPUT,"%s%s%s",state1,input,state2);
            if(end==EOF)
                break;
            if(strcmp(state,state1)==0)
            {
                if(strcmp(input,"e")==0)
                {
                    addstate(state2,i++);
                    strcpy(state,state2);
                   
                }
            }
        }
        display(i);
        rewind(INPUT);
    }
    printf("check");
    return 0;
}