//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"

void del_x(Sqc s,elem_type x){
    while(s->next!= nullptr){
        if(s->next->data==x){
            Sqc t;
            t=s->next;
            s->next=t->next;
            free(t);
        }
        s=s->next;
    }
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,30);
    list_print_chain(s1);
    del_x(s1,7);
    list_print_chain(s1);
}