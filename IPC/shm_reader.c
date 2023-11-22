#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main(){
    int key = ftok("shm",2);
    int shm_id = shmget(key,1024,0666 | IPC_CREAT);
    char *shmaddr = shmat(shm_id,NULL,0);
    printf("Data stored in shared segment: ");
    puts(shmaddr);
}