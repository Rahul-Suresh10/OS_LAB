#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void printFrames(int *frames,int f){
    printf("\n");
    int i;
    for(i=0;i<f;i++){
        printf("%d ",*(frames+i));
    }
}


void addPage(int f,int *frames,int val,int *rear){
    *rear = (*rear+1)%f;
    frames[*rear] = val;

    printFrames(frames,f);
}

bool checkPage(int *frames,int f,int val){
    for(int i=0;i<f;i++){
        if(frames[i] == val){
            return true;
        }
    }

    return false;
}

int FIFO(int *ref,int *frames,int f, int n){
    int i,fault=0;
    //Empty Frame
    for(i=0;i<f;i++){
        frames[i] = -1;
    }

    printFrames(frames,f);

    int rear=-1;
    for(i=0;i<n;i++){
        if(!checkPage(frames,f,ref[i])){
            fault++;
            addPage(f,frames,ref[i],&rear);
        }
    }

    return fault;
}


void main(){
    int i,n,f;
    printf("Enter Reference String Length: \n");
    scanf("%d",&n);
    int* ref = (int*) calloc(n,sizeof(int));
    printf("Enter Reference String : ");
    for(i=0;i<n;i++){
        scanf("%d",ref+i);
    }

    printf("Enter no. of frames : ");
    scanf("%d",&f);
    int frames[f];

    int pageFaults = FIFO(ref,frames,f,n);

    printf("\nPage Faults: %d \n",pageFaults);
}