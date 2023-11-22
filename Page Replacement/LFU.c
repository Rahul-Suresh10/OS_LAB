#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <limits.h>

typedef struct pages{
    int val;
    int noAccess;
} page;

void printFrames(page *frames,int f){
    printf("\n");
    int i;
    for(i=0;i<f;i++){
        printf("%d ",frames[i].val);
    }
}

void findLFU(page *frames,int f){
    int index = 0;
    int freq = INT_MAX,rm;
    for(int i=0;i<f;i++){
        if(frames[i].noAccess < freq){
            freq = frames[i].noAccess;
            rm = i;
        }
    }

    //For FIFO
    for(int i=rm;i<f-1;i++){
        frames[i] = frames[i+1];
    }
}


void addPage(int f,page *frames,page Incomingpage){
    findLFU(frames,f); //Removes LFU Page and makes vacancy at end
    frames[f-1]= Incomingpage;
    frames[f-1].noAccess = 1; 
    printFrames(frames,f);
}


bool checkPage(page *frames,int f,int val){
    for(int i=0;i<f;i++){
        if(frames[i].val == val){
            frames[i].noAccess++;
            return true;
        }
    }
    return false;
}

int LFU(page *ref,page *frames,int f, int n){
    int fault=0;
    //Empty Frame
    for(int i=0;i<f;i++){
        frames[i].val = -1;
        frames[i].noAccess = 0;
    }

    printFrames(frames,f);
    for(int i=0;i<n;i++){
        if(!checkPage(frames,f,ref[i].val)){
            fault++;
            addPage(f,frames,ref[i]);
        }
    }

    return fault;
}


void main(){
    int i,n,f;
    printf("Enter Reference String Length: \n");
    scanf("%d",&n);
    page* ref = (page*) calloc(n,sizeof(page));
    printf("Enter Reference String : ");
    for(i=0;i<n;i++){
        scanf("%d",&((ref+i)->val));
    }

    printf("Enter no. of frames : ");
    scanf("%d",&f);
    page* frames = (page*) calloc(f,sizeof(page));

    int pageFaults = LFU(ref,frames,f,n);

    printf("\nPage Faults: %d \n",pageFaults);
}