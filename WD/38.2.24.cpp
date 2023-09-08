//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

void del_repeat(Sqc s){
    elem_type x[31]={0};
    Sqc pre=s;
    s=s->next;
    for(;s!= nullptr;){
        x[s->data]++;
        if(x[s->data]>1){
            pre->next=s->next;
            free(s);
            s=pre->next;
        } else{
            s=s->next;
            pre=pre->next;
        }
    }
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,30);
    list_print_chain(s1);
    del_repeat(s1);
    list_print_chain(s1);
}