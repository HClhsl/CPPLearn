//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"

void list_chain_reverse(Sqc s){
    Sqc p,q,r;
    p=s->next;
    q=p->next;
    r=q->next;
    for(;r!= nullptr;){
        p->next=r;
        q->next=s->next;
        s->next=q;
        q=p->next;
        r=r->next;
    }
    p->next= nullptr;
    q->next=s->next;
    s->next=q;
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,20);
    list_print_chain(s1);
    list_chain_reverse(s1);
    list_print_chain(s1);
}