//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

void requeue(Sqc s){
    Sqc t=s->next;
    int num=0;
    while(t!= nullptr){
        t=t->next;
        num++;
    }
    //取得链表长度后算出中值，并将指针移到中值处
    if(num%2==0){
        t=s;
        int i=num/2;
        while (i){
            i--;
            t=t->next;
        }
    }else{
        t=s;
        int i=num/2+1;
        while(i){
            i--;
            t=t->next;
        }
    }
    //将链表从中值处拆开，分为两个链表，将第二个链表逆置，之后交替连接
    Sqc b=(Sqc) malloc(sizeof (SqList_chain));
    b->next=t->next;
    t->next= nullptr;
    list_chain_reverse(b);
    t=s->next;
    b=b->next;
    Sqc temp1=t->next,temp2=b->next;
    while(temp1!= nullptr&&temp2!= nullptr){
        t->next=b;
        t=t->next;
        t->next=temp1;
        t=t->next;
        temp1=temp1->next;
        b=temp2;
        temp2=temp2->next;
    }
    //对于奇数以及偶数的具体处理
    if(t->next== nullptr){
        t->next=b;
    }else{
        t->next=b;
        b->next=temp1;
    }
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,27);
    list_print_chain(s1);
    requeue(s1);
    list_print_chain(s1);
}