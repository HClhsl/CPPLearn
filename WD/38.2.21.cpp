//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

bool is_loop(Sqc s1) {
    Sqc slow,fast;
    slow=s1->next;
    fast=s1->next->next;
    for(;fast!=slow;fast=fast->next->next){
        if(fast->next== nullptr||fast->next->next== nullptr){
            return false;
        }
        else{
            slow=slow->next;
        }
    }
    return true;
}

int main(){
    srand(time(nullptr));
    Sqc s1;
    init_list_chain_random(s1,20);
    Sqc temp=s1->next;
    Sqc  loop_start;
    for(int i=number_generate()%10;temp->next!= nullptr;temp=temp->next){
        if(i==0){
            loop_start=temp;
        }
        i--;
    }
    temp->next=loop_start;
    bool x=is_loop(s1);
    if(x){
        printf("loop");
    } else
    {
        printf("no_loop");
    }
}
