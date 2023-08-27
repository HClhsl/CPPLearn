//
// Created by 28580 on 2023/8/4.
//
#include "cstdlib"
#include "cstdio"
#include "iostream"

using namespace std;

#define MaxSize 200

typedef int element_type;

typedef struct {
    element_type data[MaxSize];
    int top;
}stack;

void stack_init(stack &x){
    x.top=-1;
}

void stack_push(stack &x,element_type a){
    if(x.top==MaxSize-1){
        return;
    }
    x.data[++x.top]=a;
};

element_type stack_pop(stack &x){
    if(x.top==-1)
        return 0;
    return x.data[x.top--];
}

int main(){
    stack s;
    stack_init(s);
    element_type a;
    for(int i=1;i<4;i++){
        scanf("%d",&a);
        stack_push(s,a);
    }
    for(int i=0;i<3;i++){
        cout<<stack_pop(s)<<" ";
    }
}