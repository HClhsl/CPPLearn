//
// Created by 28580 on 2023/9/2.
//
#include "SqList.h"

void del_range(Sqc s,elem_type a,elem_type b){
    for(;s->next!= nullptr;){
        if(s->next->data>=a&&s->next->data<=b){
            Sqc temp=s->next;
            s->next=temp->next;
            free(temp);
        } else
            s=s->next;
    }
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,50);
    del_range(s1,10,90);
    list_print_chain(s1);
}