//
// Created by 28580 on 2023/7/31.
//
#include "stdio.h"
#include "stdlib.h"

void copy_str(char *&p){
    p=(char*)malloc(30);
    fgets(p,100,stdin);
}

int main(){
    char *p;
    copy_str(p);
    fputs(p,stdout);
}