//
// Created by 28580 on 2023/8/4.
//栈的初始化，判断栈是否为空，压栈，弹栈，获取栈顶元素
#include "cstdio"
#include "iostream"
using namespace std;
#define Max_size 50
typedef int element_type;
typedef struct{
    element_type data[Max_size];
    int top;
}stack;

void stack_init(stack &s){
    s.top=-1;
}

bool stack_push(stack &s,element_type a){
    if(s.top==Max_size-1){
        return false;
    }
    else {
        s.data[++s.top] = a;
        return true;
    }
}

bool stack_is_empty(stack s){
    if(s.top==-1){
        return true;
    } else
        return false;
}

element_type stack_read_top(stack s){
    if(s.top==-1){
        return NULL;
    }
    return s.data[s.top];
}

element_type stack_pop(stack &s){
    if(s.top==-1){
        return NULL;
    } else{
        return s.data[s.top--];
    }
}

void stack_print(stack s){
    for(;s.top!=-1;s.top--)
        printf("%d ",s.data[s.top]);
    printf("\n");
}

int main(){
    stack s1;
    stack_init(s1);
    for(int i=1;i<10;i++){
        stack_push(s1,i);
    }
    stack_print(s1);
    cout<<stack_pop(s1)<<'\n';
    stack_print(s1);
    cout<<stack_read_top(s1)<<"\n";
    cout<<stack_is_empty(s1);
}
