//
// Created by 28580 on 2023/9/5.
//
#include "SqList.h"

void merge(psd &a,psd &b){
    a->prior->next=b;
    a->prior=b->prior;
    b->prior->next=a;
    b->prior=a->prior;
}

int main(){
    psd a,b;
    init_double_chain_random(a,5);
    init_double_chain_random(b,6);
    list_print_double_recycle(a);
    list_print_double_recycle(b);
    merge(a,b);
    list_print_double_recycle(a);
}