#include<stdio.h>
#include<pthread.h>

int n = 5;
int chopstick[5];

void wait(int *s){
    while (*s<=0);
   --(*s);
}

void signal(int *s){
    ++(*s);
}


void* eat(void* Philid){
    int id = *((int *) Philid);


    printf("\nPhilosopher %d is requesting chopstick %d \n", id,id);
    wait(&chopstick[id]);
    printf("\nPhilosopher %d picked up chopstick %d \n", id,id);


    printf("\nPhilosopher %d is requesting chopstick %d \n", id,(id+1)%n);
    wait(&chopstick[(id+1)%n]);
    printf("\nPhilosopher %d picked up chopstick %d \n", id,(id+1)%n);

    printf("\nPhilosopher %d is eating \n", id);

    signal(&chopstick[(id+1)%n]);
    printf("\nPhilosopher %d released chopstick %d \n", id,(id+1)%n);

    signal(&chopstick[id]);
    printf("\nPhilosopher %d released chopstick %d \n", id,id);
} 


void main(){
    int philos[5];
    pthread_t pids[5];
    for(int i=0;i<n;i++){
        philos[i] = i;
        chopstick[i] = 1;
        pthread_create(&pids[i],NULL,&eat,(void *) &philos[i]);
    }
    for(int i=0;i<n;i++){
        pthread_join(pids[i],NULL);
    }
}