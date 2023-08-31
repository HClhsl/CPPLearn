//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"

void del_min(Sqc s){
    elem_type min =s->next->data;
    s=s->next->next;
    Sqc t=s->next;
    while(s->next!= nullptr){
        if(s->next->data<=min){
            min=s->next->data;
            t=s;
        }
        s=s->next;
    }
    Sqc temp=t->next;
    t->next=temp->next;
    free(temp);
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,20);
    list_print_chain(s1);
    del_min(s1);
    list_print_chain(s1);
}