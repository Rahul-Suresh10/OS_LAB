#include<stdio.h>
#include<dirent.h>
#include<string.h>

void main(int argc,char *argv[]){
    if(argc == 1){
        DIR *dir ;
        dir = opendir("./");
        struct dirent *d;
        if(dir == NULL){
            printf("Error Reading Directory");
        }
        else{
            while(d = readdir(dir)){
                printf("%s\n",d->d_name);
            }
        }
    }
    else{
        FILE *f1 = fopen(argv[1],"r");
        if(strcmp(argv[2],"..") == 0){
            printf("PARENT");
            strcat(argv[2],"/");
            strcat(argv[2],argv[1]);
        }
        FILE *f2 = fopen(argv[2],"w");

        if(f1 == NULL || f2 == NULL){
            printf("Error : Invalid files supplied F1: %s , F2 : %s \n",argv[1],argv[2]);
        }
        else{
            char c;
            while((c = fgetc(f1))!= EOF){
                fputc(c,f2);
            }
        }   
    }
}