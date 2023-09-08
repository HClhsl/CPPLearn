//
// Created by 28580 on 2023/9/7.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "Queue.h"

typedef struct stack{
    elem_type data[max_size];
    int top=0;
}stack;

elem_type pop(stack &s){
    if(s.top==0){
        printf("Empty Stack!");
        return -1;
    }
    //printf("%3d",s.data[--s.top]);
    return s.data[--s.top];
}

void push(stack &s,elem_type data){
    if(s.top==max_size){
        printf("Full Stack!");
        return;
    }
    s.data[s.top++]=data;
}

void clear_stack(stack &s){
    while(s.top){
        printf("%3d",s.data[--s.top]);
    }
    printf("\n");
}

#endif //UNTITLED_STACK_H
