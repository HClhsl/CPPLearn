//
// Created by 28580 on 2023/8/31.
//
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

int main(){
    Sqc s1;
    init_list_chain_random(s1,30);
    sort(s1);
    list_print_chain(s1);
}
