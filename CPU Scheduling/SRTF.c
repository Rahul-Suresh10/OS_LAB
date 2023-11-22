#include<stdio.h>
#include<limits.h>
// 5 3 5 0 5 4 4 3 2 1 3

typedef struct p{
    int id,at,bt,ct,tat,wt,rt,completed;
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

int getCurrentShortest(process *p,int n,int time){
    process shortest;
    shortest.rt = INT_MAX;
    int shortIndex = -1;
    for(int i=0;i<n;i++){
        if(p[i].completed == 0 && p[i].rt < shortest.rt && p[i].at <= time){
            shortest = p[i];
            shortIndex = i;
        }
    }

    return shortIndex;
}

void SRTF(process* p,int n){
    int time = 0,totalTAT=0 ,totalWT =0;
    int shortIndex = -1,completed = 0;
    while(completed!=n){
        shortIndex = getCurrentShortest(p,n,time);
        while(shortIndex==-1) {
            time++;
            shortIndex = getCurrentShortest(p,n,time);
        };
        time++;
        p[shortIndex].rt--;
        if(p[shortIndex].rt == 0){
            p[shortIndex].ct = time;
            p[shortIndex].tat = time - p[shortIndex].at;
            totalTAT+= p[shortIndex].tat;

            p[shortIndex].wt = p[shortIndex].tat - p[shortIndex].bt;
            totalWT += p[shortIndex].wt;
            p[shortIndex].completed = 1;
            completed++;
        }

    }
    printf("\n\nAvg TAT %f\n",(float)totalTAT/(float)n);
    printf("\nAvg WT %f\n",(float)totalWT/(float)n);
}


void main(){
    int n,i;

    printf("Enter no. of processes: ");
    scanf("%d",&n);

    process p[n];

    printf("\nEnter the process ATs: ");
    for(i=0;i<n;i++){
        scanf("%d",&(p[i].at));
        p[i].id= i;
    }

    printf("\nEnter the process BTs: ");
    for(i=0;i<n;i++){
        scanf("%d",&(p[i].bt));
        p[i].rt=p[i].bt;
        p[i].completed= 0;
    }

    SRTF(p,n);

    printResult(p,n);
}