#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


void displayContent(DIR *dr,char *drName,int space){
    struct dirent *file;
    DIR *temp;
    readdir(dr);
    readdir(dr);
    int i,pidTemp;
    while(file = readdir(dr)){
        for(i=0;i<space;i++){
            printf("\t");
        }
        char *tempName = (char*) calloc(sizeof(char),100);
        strcpy(tempName,drName);
        strcat(tempName,file->d_name);
        strcat(tempName,"/");
        temp = opendir(tempName);
        for(i=0;i<space+1;i++){
                printf(">");
        }
        printf(" %s\n",file->d_name);
        if(temp != 0){
            pidTemp = fork();
            if(pidTemp == 0){
                for(int i=0;i<space;i++){
                    printf("\t");
                }
                printf(" (Browsing folder PID: %d) \n",getpid());
                // printf("Child process %d",getpid());
                displayContent(temp,tempName,space+1);
            }
            else{
                wait(NULL);
            }
        }
    }
    exit(0);
}

void main(){    
    DIR *dr;
    char drName[]= "./";
    dr = opendir(drName);
    displayContent(dr,drName,0);
}   