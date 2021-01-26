/*Write a C/C++ Program to illustrate the race condition*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static void charactatime(char *);
int main(){
    int pid;
    if((pid=fork())<0){
        printf("Fork error");
    }
    else if (pid==0){
        charactatime("Output from child\n");
    }
    else{
        charactatime("Output from Parent\n");
    }
    _exit(0);
}
static void charactatime(char *str){
    char *ptr;
    int c;
    setbuf(stdout, NULL);
    for(ptr=str;(c=*ptr++)!=0;){
        putc(c,stdout);
    }
}