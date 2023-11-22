#include<stdio.h>
int n,i,m;


int safety(int allocation[][m],int need[][m],int *available){
    int finish[n];
    int work[m],flag,notFound=1,i,j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    for (int j = 0; j < m; j++)
    {
        work[j] = available[j]; 
    }
    i=0;
    do
    {
        if(finish[i] == 0){
            flag = 1;
            for (j = 0; j < m; j++)
            {
                if(need[i][j] > work[j]){
                    flag = 0;
                }  
            }
            if(flag == 1 ){
                printf("P%d ",i);
                notFound = 0;
                finish[i] = 1;
                for (j = 0; j < m; j++)
                {
                    work[j] += allocation[i][j];
                }
            }
        }
        i = (i+1)%n;

        if(i == 0 && notFound == 1){
            break;
        }
        else if( i == 0 ){
            notFound = 1;
        }
    }while(1);

    flag = 0;
    for (i = 0; i < n; i++)
    {
        if(finish[i] == 0){
            flag = 1 ;
        }
    }

    if(flag == 0){
        return 1;
    }
    else{
        return 0;
    }
    
}

void main(){
    printf("Initial state\n");
    printf("Enter no. of process : ");
    scanf("%d",&n);

    printf("Enter no. of resources : ");
    scanf("%d",&m);

    int allocation[n][m],need[n][m],available[m],max[n][m];

    printf("Enter Allocation matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }


    printf("Enter Max matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&max[i][j]);
        }
    }


    printf("Enter Available vector: \n");

    for (int i = 0; i < m; i++)
    {
            scanf("%d",&available[i]);
    }

 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    if(safety(allocation,need,available) == 1){
        printf(" Safe\n");
    }
    else{
        printf("Not safe");
    }
}


/*
Output

Enter no. of process : 5 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 3 3 2
Enter no. of resources : Enter Allocation matrix: 
Enter Max matrix: 
Enter Available vector: 
P1 P3 P4 P0 P2  Safe
*/