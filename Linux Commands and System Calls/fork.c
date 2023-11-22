#include<stdio.h>
#include<unistd.h>

void main(){
    pid_t pid = fork();

    if(pid < 0){
        printf("\nProcess creation Failed");
    }
    else if(pid == 0){
        printf("\nInside child process with id : %d\n",getpid());
    }
    else{
        printf("\nParent process , Created child with id : %d\n", pid);
    }
}   