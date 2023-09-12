//
// Created by 28580 on 2023/9/8.
//
#include "string"
#define max_size 50

typedef char elem_type;

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

int main(){
    char a[50]="(Merry) {[(Christmas)]}";
    stack s1;
    int i=0;
    while(a[i]!='\0'){
        if(a[i]=='['||a[i]=='('||a[i]=='{'){
            push(s1,a[i]);
        }
        if(a[i]==']'||a[i]==')'||a[i]=='}'){
            if(pop(s1)!=a[i]){
                printf("Not Match!!!");
                break;
            }
        }
        i++;
    }
}