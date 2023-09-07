//
// Created by 28580 on 2023/9/4.
//
#include <unistd.h>
#include "SqList.h"
#include "Queue.h"

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

void find_intersection(Sqc a,Sqc b){
    Sqc x,y;
    x=a;
    a=a->next;
    b=b->next;
    for(;a!= nullptr&&b!= nullptr;){
        if(a->data==b->data){
            x=x->next;
            a=a->next;
            b=b->next;
        }
        else if(a->data<b->data){
            x->next=a->next;
            free(a);
            a=x->next;
        }
        else{
            b=b->next;
        }
    }
    if(b== nullptr){
        x->next= nullptr;
    }
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
    find_intersection(a,b);
    list_print_chain(a);
}