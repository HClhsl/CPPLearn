//
// Created by 28580 on 2023/9/4.
//
#include <unistd.h>
#include "SqList.h"
#include "Sort.h"

void sort(Sqc s){
    Sqc t=s->next;
    for(;t->next!= nullptr;t=t->next){
        Sqc a=t;
        while(a!= nullptr){
            if(a->data<t->data)
                swamp(a->data,t->data);
            a=a->next;
        }
    }
}

Sqc find_public(Sqc a,Sqc b){
    Sqc c,temp;
    c=(Sqc) malloc(sizeof (SqList_chain));
    c->next= nullptr;
    temp=c;
    a=a->next;
    b=b->next;
    for(;a!= nullptr&&b!= nullptr;){
        if(a->data>b->data){
            b=b->next;
        }
        else if(a->data<b->data){
            a=a->next;
        }
        else{
            temp->next=(Sqc) malloc(sizeof (SqList_chain));
            temp=temp->next;
            temp->data=a->data;
            temp->next= nullptr;
            a=a->next;
            b=b->next;
        }
    }
    return c;
}

int main(){
    Sqc a,b;
    init_list_chain_random(a,30);
    sleep(1);
    init_list_chain_random(b,35);
    sort(a);
    sort(b);
    list_print_chain(a);
    list_print_chain(b);
    Sqc c= find_public(a,b);
    list_print_chain(c);
}