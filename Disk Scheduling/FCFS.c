#include<stdio.h>
#include<stdlib.h>
//82 170 43 140 24 16 190

int FCFS(int *req,int n,int head){
    int seek = 0;
    for(int i=0;i<n;i++){
        seek+= abs(head - req[i]);
        head = req[i];
    }

    return seek;
}

void main(){
    int n,i,h;
    printf("Enter no. of requests : ");
    scanf("%d",&n);
    printf("\nEnter the sequence of requests: ");
    int req[n];
    for(i=0;i<n;i++){
        scanf("%d",(req+i));
    }

    printf("Enter position of head: ");
    scanf("%d",&h);

    int totalseek = FCFS(req,n,h);

    printf("\n TOTAL SEEKTIME = %d \n",totalseek);
}