//
// Created by 28580 on 2023/9/4.
//
#include "SqList.h"
#include "Queue.h"

void list_del_repeat(Sqc s){
    Sqc t=s->next;
    for(;t->next!= nullptr;){
        if(t->next->data==t->data){
            Sqc temp=t->next;
            t->next=temp->next;
            free(temp);
        } else{
            t=t->next;
        }
    }
}

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
    list_del_repeat(s1);
    list_print_chain(s1);
}