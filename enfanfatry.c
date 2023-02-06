#include<stdio.h>
#include<string.h>
int ind=0;
char result[10][10];
int notin(char state[10], char arraytrans[10][10], int limit) 
{ 
    for(int i = 0;i<limit;i++) 
    { 
        if(strcmp(arraytrans[i],state)==0) 
        return 0; 
    } 
    return 1; 
} 
int main()
{
    int n,nalp;
    FILE *INPUT1,*INPUT2,*INPUT3;
    char states[10][10],alphabets[10][10],state1[10],input[10],state2[10];
    INPUT1=fopen("input_enfa.txt","r");
    INPUT2=fopen("eclosure.txt","r");
    INPUT3=fopen("eclosure.txt","r");
    printf("Enter the number of states: \n");
    scanf("%d",&n);
    printf("\nEnter the states: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",states[i]);
    }
    printf("Enter the number of alphabets: \n");
    scanf("%d",&nalp);
    printf("\nEnter the alphabets: \n");
    for(int i=0;i<nalp;i++)
    {
        scanf("%s",alphabets[i]);
    }
   
    printf("\nSTATE\t\tINPUT\t\tSTATES\n");
    // taking one state at a time, and finding transitions
    for(int i=0;i<n;i++)
    {
        char epclosure[10][10],transition[10][10];
        int q=0;
        int end= fscanf(INPUT2,"%s %s %s %s",epclosure[0],epclosure[1],epclosure[2],epclosure[3]);
        if(end==EOF)
        break;
        for(int j=0;j<nalp;j++)
        {
            printf("%s\t\t%s\t\t",states[i],alphabets[j]);
            for(int k=0;k<n;k++)
            {
                if(strcmp(epclosure[k],"_")!=0)
                {
                    while(1)
                    {
                        int end1=fscanf(INPUT1,"%s %s %s",state1,input,state2);
                        if(end1==EOF)
                            break;
                        if(strcmp(state1,epclosure[k]) ==0&& strcmp(input,alphabets[j])==0 && notin(state2,transition,q))
                        {
                            strcpy(transition[q],state2);
                            q++;
                        }
                    }
                    rewind(INPUT1);
                }
            }
            
            for(int p=0;p<q;p++)
            {
                char fclosure[10][10];
                while(1)
                {
                    int end= fscanf(INPUT3,"%s %s %s %s",fclosure[0],fclosure[1],fclosure[2],fclosure[3]);
                    if(end==EOF)
                    break;
                    if(strcmp(transition[p],fclosure[0])==0)
                    {
                        for(int a=0;a<n;a++)
                        {
                            if(strcmp(fclosure[a],"-")!=0 && notin(fclosure[a],result,ind)!=0)
                            {
                                strcpy(result[ind],fclosure[a]);
                                ind++;
                                printf("%s ",fclosure[a]);
                            }
                        }
                    }
                }
                rewind(INPUT3);
            }
            if(ind == 0) 
                printf("empty set"); 
            printf("\n"); 
            for(int j=0;j<ind;j++) 
                strcpy(result[j], " "); 
            ind = 0; 
        }
    }
     printf("Check");
    return 0;
}

