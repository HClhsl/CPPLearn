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

void list_merge(Sqc a,Sqc b){
    Sqc t,temp;
    t=a;
    temp=a;
    a=a->next;
    b=b->next;
    for(;a!= nullptr&&b!= nullptr;){
        if(a->data>=b->data){
            temp->next=b;
            b=b->next;
        } else{
            temp->next=a;
            a=a->next;
        }
        temp=temp->next;
    }
    if(a== nullptr){
        temp->next=b;
    } else{
        temp->next=a;
    }
}

int main(){
    Sqc a,b;
    init_list_chain_random(a,30);
    sleep(1);
    init_list_chain_random(b,25);
    sort(a);
    sort(b);
    list_print_chain(a);
    list_print_chain(b);
    list_merge(a,b);
    list_print_chain(a);
}