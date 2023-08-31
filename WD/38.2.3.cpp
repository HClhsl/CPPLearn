//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"

void reverse_print(Sqc s){
    if(s->next!= nullptr) {
        reverse_print(s->next);
    }
    printf("%3d",s->data);
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,20);
    list_print_chain(s1);
    reverse_print(s1->next);
}