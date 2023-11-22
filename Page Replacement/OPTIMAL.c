#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <limits.h>

//3 2 1 3 4 1 6 2 4 3 4 2 1 4 5 2 1 3 4
typedef struct pages{
    int val;
    int nextAccess;
} page;

void printFrames(page *frames,int f){
    printf("\n");
    int i;
    for(i=0;i<f;i++){
        printf("%d ",frames[i].val);
    }
}

int findOPT(page *frames,int f){
    int index = 0;
    int clk = INT_MIN,rm;
    for(int i=0;i<f;i++){
        if(frames[i].nextAccess > clk){
            clk = frames[i].nextAccess;
            rm = i;
        }
    }
    return rm;
}

int findNextAccess(page *ref,int clk,page *frames,int n){
    int nextAccess = clk;
    for(int i=clk+1;i<n;i++){
        if(ref[i].val == ref[clk].val){
            nextAccess = i;
            break;
        }
    }
    if(nextAccess != clk){
        return nextAccess;
    }else{
        return INT_MAX;
    }
}


void addPage(int f,page *frames,page* ref,int clk,int n){
    int rm = findOPT(frames,f);
    frames[rm]= ref[clk];
    frames[rm].nextAccess = findNextAccess(ref,clk,frames,n);
    printFrames(frames,f);
}


bool checkPage(page *frames,page *ref,int f,int clk,int n){
    int val = ref[clk].val;
    for(int i=0;i<f;i++){
        if(frames[i].val == val){
            int nextAccess = findNextAccess(ref,clk,frames,n);
            frames[i].nextAccess = nextAccess;
            return true;
        }
    }
    return false;
}

int OPT(page *ref,page *frames,int f, int n){
    int fault=0,clk=0;
    //Empty Frame
    for(int i=0;i<f;i++){
        frames[i].val = -1;
        frames[i].nextAccess = INT_MAX;
    }

    printFrames(frames,f);

    for(clk=0;clk<n;clk++){
        if(!checkPage(frames,ref,f,clk,n)){
            fault++;
            addPage(f,frames,ref,clk,n);
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

    int pageFaults = OPT(ref,frames,f,n);

    printf("\nPage Faults: %d \n",pageFaults);
}