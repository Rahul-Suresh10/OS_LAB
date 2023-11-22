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
            // printf("Checking process %d\n",i);
            // printf("Need for %d is : ",i);
            // for (j = 0; j < m; j++)
            // {
            //     printf("%d ",need[i][j]); 
            // }
            // printf("\n");
            // printf("Current Work for is : ",i);
            // for (j = 0; j < m; j++)
            // {
            //     printf("%d",work[j]); 
            // }
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

int request(int allocation[][m],int need[][m],int req[][m],int *available,int pid){
    for (int j = 0; j < m; j++)
    {
            if(req[pid][j] > need[pid][j]){
                printf("Request is higher than need , Terminating");
                return 0;
            }
            else if(req[pid][j] > available[j]){
                printf("Request is higher than Available");
                return 0;
            }
    }

    for (int j = 0; j < m; j++)
    {
            available[j]-=req[pid][j];
            allocation[pid][j]+=req[pid][i];
            need[pid][j]-=req[pid][i];
    }
    if(safety(allocation,need,available) == 1){
        return 1;
    }
    else{
        for (int j = 0; j < m; j++)
        {
                available[j]+=req[pid][j];
                allocation[pid][j]-=req[pid][i];
                need[pid][j]+=req[pid][i];
        }
        return 0;
    }
}

void main(){
    printf("Initial state\n");
    printf("Enter no. of process : ");
    scanf("%d",&n);

    printf("Enter no. of resources : ");
    scanf("%d",&m);

    int allocation[n][m],need[n][m],available[m],max[n][m],optn,pid,req[n][m];

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

    // if(safety(allocation,need,available) == 1){
    //     printf(" Safe\n");
    // }
    // else{
    //     printf("Not safe");
    // }

    do{
        printf("\nEnter option to continue: ");
        scanf("%d",&optn);
        switch (optn)
        {
            case 1:
                printf("Enter process to request: ");
                scanf("%d",&pid);
                printf("\nEnter request for %d process in order: ",m);
                for (int i = 0; i < m; i++)
                {
                        scanf("%d",&req[pid][i]);
                }
                request(allocation,need,req,available,pid);
                break;
            case 2:
                break;
        }
    }while(optn!=2);
}