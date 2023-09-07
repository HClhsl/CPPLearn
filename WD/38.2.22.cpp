//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

//双指针法
elem_type find_by_locate(Sqc s,int locate){
    Sqc k,temp;
    k=s->next,temp=s->next;
    while(locate){
        temp=temp->next;
        locate--;
    }
    for(;temp!= nullptr;){
        temp=temp->next;
        k=k->next;
    }
    return k->data;
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,30);
    list_print_chain(s1);
    elem_type x= find_by_locate(s1,7);
    printf("%d",x);
}