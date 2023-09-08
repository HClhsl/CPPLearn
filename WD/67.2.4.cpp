//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

void is_symmetry(Sqc s){
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
    while(t!= nullptr&&b!= nullptr){
        if(t->data==b->data){
            t=t->next;
            b=b->next;
        }
        else{
            printf("Not symmetry!");
            return;
        }
    }
    printf("Is symmetry!");
}