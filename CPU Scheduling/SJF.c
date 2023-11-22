#include<stdio.h>
// 5 3 5 0 5 4 4 3 2 1 3

typedef struct p{
    int id,at,bt,ct,tat,wt;
}process;

void sortByID(process* p,int n){
    process temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].id > p[j+1].id){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void printResult(process* p,int n){
    printf("\nID\tAT\tBT\tWT\tTAT\tCT");
    sortByID(p,n);
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",i,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
    }

    printf("\n");
}

void sortByBT(process* p,int n){
    process temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt > p[j+1].bt){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void FCFS(process* p,int n){
    sortByBT(p,n);
    int time = 0,totalTAT=0 ,totalWT =0;
    for(int i=0;i<n;i++){
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = time - p[i].at;
        totalTAT+= p[i].tat;

        p[i].wt = p[i].tat - p[i].bt;
        totalWT += p[i].wt;
    }
    printf("\n\nAvg TAT %f\n",(float)totalTAT/(float)n);
    printf("\nAvg WT %f\n",(float)totalWT/(float)n);
}


void main(){
    int n,i;

    printf("Enter no. of processes: ");
    scanf("%d",&n);

    process p[n];

    printf("\nEnter the process BTs: ");
    for(i=0;i<n;i++){
        p[i].id= i;
        scanf("%d",&(p[i].bt));
        p[i].at= 0;
    }

    FCFS(p,n);

    printResult(p,n);
}