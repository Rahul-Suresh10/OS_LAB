#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc,char *argv[]){
    if(argc == 1){
        printf("Supply All Parameters");
    }
    else{
        FILE *f1 = fopen(argv[2],"r");

        if(f1 == NULL){
            printf("Error : Invalid files supplied F1: %s",argv[2]);
        }
        else{
            char *str = (char*) malloc(200 * sizeof(char));
            while(fgets(str,200,f1)){
               if(strstr(str,argv[1]) != NULL){
                    printf("%s",str);
               }
            }
        }   
    }
}