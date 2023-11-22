#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//82 170 43 140 24 16 190

int findSST(int *req,int head,int n){
    int minSeekIndex = 0;
    for(int i=0;i<n;i++){
        if(abs(head - req[i]) < abs(head - req[minSeekIndex])){
            minSeekIndex = i;
        }
    }
    return minSeekIndex;
}
int printSeekSequence(int *seek,int n){
    printf("\nSeek Sequence ");
    for(int i=0;i<n;i++){
        printf("->%d",seek[i]);
    }
}

int SSTF(int *req,int n,int head){
    int seek = 0,minSeekIndex,seekSequence[n],z=0;
    minSeekIndex = findSST(req,head,n);
    while(req[minSeekIndex] != INT_MAX){
        seek+= abs(head-req[minSeekIndex]);
        head = req[minSeekIndex];
        seekSequence[z] = head;
        z++;
        req[minSeekIndex] = INT_MAX;
        minSeekIndex = findSST(req,head,n);
    }

    printSeekSequence(seekSequence,n);
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

    int totalseek = SSTF(req,n,h);

    printf("\nTOTAL SEEKTIME = %d \n",totalseek);
}