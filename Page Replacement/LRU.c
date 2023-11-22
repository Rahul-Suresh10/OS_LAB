#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <limits.h>

typedef struct pages{
    int val;
    int lastAccess;
} page;

void printFrames(page *frames,int f){
    printf("\n");
    int i;
    for(i=0;i<f;i++){
        printf("%d ",frames[i].val);
    }
}

int findLRU(page *frames,int f){
    int index = 0;
    int clk = INT_MAX,rm;
    for(int i=0;i<f;i++){
        if(frames[i].lastAccess < clk){
            clk = frames[i].lastAccess;
            rm = i;
        }
    }
    return rm;
}


void addPage(int f,page *frames,page Incomingpage,int clk){
    int rm = findLRU(frames,f);
    frames[rm]= Incomingpage;
    frames[rm].lastAccess = clk;
    printFrames(frames,f);
}


bool checkPage(page *frames,int f,int val,int clk){
    for(int i=0;i<f;i++){
        if(frames[i].val == val){
            frames[i].lastAccess = clk;
            return true;
        }
    }
    return false;
}

int LRU(page *ref,page *frames,int f, int n){
    int fault=0,clk=0;
    //Empty Frame
    for(int i=0;i<f;i++){
        frames[i].val = -1;
        frames[i].lastAccess = -1;
    }

    printFrames(frames,f);

    for(clk=0;clk<n;clk++){
        if(!checkPage(frames,f,ref[clk].val,clk)){
            fault++;
            addPage(f,frames,ref[clk],clk);
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

    int pageFaults = LRU(ref,frames,f,n);

    printf("\nPage Faults: %d \n",pageFaults);
}