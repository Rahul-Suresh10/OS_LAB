#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//82 170 43 140 24 16 190

typedef struct req{
    int val;
    int visited;
}request;


int checkRequest(request *req,int head,int n){
    int temp;
    for(int i =0 ; i< n ; i++){
        if(req[i].val == head && req[i].visited != 1){
            return i;
        }
    }
    return -1;
}

int CSCAN(request *req,int n,int head,int track){
    int serviced = 0,seekSequence[n],seekSequenceIndex=0,seek=0;
    int dir = 1,h = head;
    while(serviced != n){
        if(h == 199){
            seek+= 199;
            h = 0;
        }
        int check = checkRequest(req,h,n);
        if(check != -1){
            req[check].visited = 1;
            serviced++;
        }
        h++;
        seek++;
    }

    seek--; //To reduce extra seek at last;

    return seek;
}

void main(){
    int n,i,h,t;
    printf("Enter no. of requests : ");
    scanf("%d",&n);
    printf("\nEnter the sequence of requests: ");
    request req[n];
    for(i=0;i<n;i++){
        scanf("%d",&((req+i)->val));
        req[i].visited = 0;
    }

    printf("Enter position of head: ");
    scanf("%d",&h);

    printf("Enter no. of tracks: ");
    scanf("%d",&t);

    int totalseek = CSCAN(req,n,h,t);

    printf("\n TOTAL SEEKTIME = %d \n",totalseek);
}