//
// Created by 28580 on 2023/9/2.
//
#include "SqList.h"

void list_reverse(Sqc s){
    Sqc p,q,r;
    p=s->next;
    q=p->next;
    r=q->next;
    for(;r!= nullptr;){
        p->next=r;
        q->next=s->next;
        s->next=q;
        q=r;
        r=r->next;
    }
    p->next= nullptr;
    q->next=s->next;
    s->next=q;
}

Sqc Split(Sqc a){
    Sqc c,b=(Sqc) malloc(sizeof (SqList_chain));
    c=b;
    b->next= nullptr;
    Sqc pre=a;
    a=a->next;
    for(int i=1;a!= nullptr;i++){
        if(i%2==1){
            pre=pre->next;
            a=a->next;
        } else{
            b->next=a;
            pre->next=a->next;
            a=a->next;
            b=b->next;
            b->next= nullptr;
        }
    }
    list_reverse(c);
    return c;
}

int main(){
    Sqc a;
    init_list_chain_random(a,30);
    list_print_chain(a);
    Sqc b=Split(a);
    list_print_chain(a);
    list_print_chain(b);
}