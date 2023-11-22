#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
// 6 5 4 3 1 2 6 5 6 7 9 2 3

typedef struct p{
    int id,at,bt,ct,tat,wt,rt,completed,status; //Lower number higher priority
    int empty;
}process;

int front,rear;

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

void enqueue(int *readyQueue,int p,int n){
    if(front == -1){
        front = 0;
    }
    rear = (rear+1)%n;
    readyQueue[rear] = p;
}

int dequeue(int *readyQueue,int n){
    if(front == -1 && rear == -1){
        return -1;
    }
    int p = readyQueue[front];

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%n;
    }
    
    return p;
}

void addNewProcesses(process *p,int *readyQueue,int time ,int n){
    for(int i =0 ; i < n ; i++){
        if(p[i].status == 0 && p[i].at <= time){
            enqueue(readyQueue,i,n);
            p[i].status = 1;
        }
    }
}

void RR(process* p,int n,int quantum){
    int time = 0,totalTAT=0 ,totalWT =0;
    int currentIndex = -1,completed = 0;
    int readyQueue[n];
    front = rear = -1;
    while(completed!=n){
        //Time quantum expires
        addNewProcesses(p,readyQueue,time,n);
        currentIndex = dequeue(readyQueue,n);
        while(currentIndex==-1) {
                time++;
                printf("Loop in %d",time);
                addNewProcesses(p,readyQueue,time,n);
                currentIndex = dequeue(readyQueue,n);
        };
        for(int qexp=0; qexp < quantum; qexp++){
            time++;
            p[currentIndex].rt--;

            addNewProcesses(p,readyQueue,time,n);

            //If rt finish before quantum
            if(p[currentIndex].rt == 0){
                break;
            }
        }
        if(p[currentIndex].rt == 0){
            p[currentIndex].ct = time;
            p[currentIndex].tat = time - p[currentIndex].at;
            totalTAT+= p[currentIndex].tat;

            p[currentIndex].wt = p[currentIndex].tat - p[currentIndex].bt;
            totalWT += p[currentIndex].wt;
            p[currentIndex].completed = 1;
            completed++;
        }
        else{
            enqueue(readyQueue,currentIndex,n);
        }

    }
    printf("\n\nAvg TAT %f\n",(float)totalTAT/(float)n);
    printf("\nAvg WT %f\n",(float)totalWT/(float)n);
}


void main(){
    int n,i,quantum;

    printf("Enter no. of processes: ");
    scanf("%d",&n);

    process p[n];
    process readyQueue[n];

    for(i=0;i<n;i++){
    printf("\nEnter the process ATs: ");
        scanf("%d",&(p[i].at));
        p[i].id= i;
        p[i].empty= 0;
    }

    for(i=0;i<n;i++){
    printf("\nEnter the process BTs: ");
        scanf("%d",&(p[i].bt));
        p[i].rt=p[i].bt;
        p[i].status= 0;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d",&quantum);

    RR(p,n,quantum);

    printResult(p,n);
}