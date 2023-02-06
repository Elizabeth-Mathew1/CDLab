#include <stdio.h>
#include <string.h>
struct dfastates
{
    char state[10];
    int check;
};

struct dfastates st[20];
int i = 0, j = 0;
char delim[] = ",";

int notin(char state[], struct dfastates st[], int limit)
{
    for (int i = 0; i < limit; i++)
    {
        if (strcmp(st[i].state, state) == 0)
            return 0;
    }
    return 1;
}
int checkdup(char state[], char st[10][10], int limit)
{
    for (int i = 0; i < limit; i++)
    {
        if (strcmp(st[i], state) == 0)
            return 1;
    }
    return 0;
}
int main()
{
    char state[10], input0[10], input1[10];
    FILE *INPUT;
    printf("STATE\t\tINPUT0\t\tINPUT1\n----------------------------------------\n");
    INPUT = fopen("nfa.txt", "r");
    int end = fscanf(INPUT, "%s %s %s", state, input0, input1);

    strcpy(st[i].state, state);
    st[i].check = 1;
    i++;
    j++;

    if (strcmp("-", input0) != 0 && notin(input0, st, i))
    {
        strcpy(st[i].state, input0);
        st[i].check = 0;
        i++;
    }

    if (strcmp("-", input1) != 0 && notin(input1, st, i))
    {
        strcpy(st[i].state, input1);
        st[i].check = 0;
        i++;
    }

    printf("%s\t\t%s\t\t%s\n", state, input0, input1);

    // ****************************************** //

    while (j < i)
    {
        if (!st[j].check)
        {
            char copy[10], result0[10], result1[10];
            int res0 = 0, res1 = 0;

            printf("%s\t\t", st[j].state);
            strcpy(copy, st[j].state);
            char *ptr = strtok(copy, delim);
            while (ptr != NULL)
            {
                rewind(INPUT);
                int end1 = fscanf(INPUT, "%s %s %s", state, input0, input1);
                while (end1 != EOF)
                {
                    if (strcmp(state, ptr) == 0)
                    {
                        if (res0 == 0 && strcmp(input0, "-") != 0)
                        {
                            res0++;
                            strcpy(result0, input0);
                        }
                        else if (strcmp(input0, "-") != 0)
                        {
                            strcat(result0,",");
                            strcat(result0, input0);
                        }
                        if (res1 == 0 && strcmp(input1, "-") != 0)
                        {
                            res1++;
                            strcpy(result1, input1);
                        }
                        else if (strcmp(input1, "-") != 0)
                        {
                            strcat(result1,",");
                            strcat(result1, input1);
                        }
                    }
                    end1 = fscanf(INPUT, "%s %s %s", state, input0, input1);
                }
                ptr = strtok(NULL, delim);
            }
            st[j].check = 1;
            j++;

            //*******************************************//

            // removing duplicates frm result0

            char copy0[10][10];
            int count=0;
            char *ptr0=strtok(result0,delim);
            while(ptr0!=NULL)
            {
                if(!checkdup(ptr0,copy0,count))
                {
                    
                    strcpy(copy0[count],ptr0);
                    count++;
                }
                ptr0=strtok(NULL,delim);
            }

            // adding commas back

            char fres0[10];
            strcpy(fres0,copy0[0]);
            for(int i=1;i<count;i++)
            {
                strcat(fres0,",");
                strcat(fres0,copy0[i]);
            }
            printf("%s\t\t", fres0);
            // adding newly generated stae to dfa states

            if(notin(fres0,st,i))
            {
                strcpy(st[i].state,fres0);
                i++;
            }

            char copy1[10][10];
            count=0;
            char *ptr1=strtok(result1,delim);
            while(ptr1!=NULL)
            {
                if(!checkdup(ptr1,copy1,count))
                {
                    
                    strcpy(copy1[count],ptr1);
                    count++;
                }
                ptr1=strtok(NULL,delim);
            }

            // adding commas back

            char fres1[10];
            strcpy(fres1,copy1[0]);
            for(int i=1;i<count;i++)
            {
                strcat(fres1,",");
                strcat(fres1,copy1[i]);
            }
            printf("%s\n", fres1);
            
            // adding newly generated stae to dfa states

            if(notin(fres1,st,i))
            {
                strcpy(st[i].state,fres1);
                i++;
            }
            
        }
      
    }
   
    return 0;
}