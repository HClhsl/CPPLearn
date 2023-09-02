//
// Created by 28580 on 2023/9/2.
//
#include "SqList.h"

void print_on_sort(Sqc s){
    Sqc pre,t=s->next,x=s->next;
    int min=t->data;
    pre=s;
    for(;t->next!= nullptr;) {
        for (; t->next != nullptr;t=t->next) {
            if (t->next->data <= min) {
                pre = t;
                min = pre->next->data;
            }
        }
        printf("%3d", pre->next->data);
        Sqc temp = pre->next;
        pre->next = temp->next;
        free(temp);
        t = s->next;
        pre=s;
        min = t->data;
    }
    printf("%3d", s->next->data);
}

int main(){
    Sqc s1;
    init_list_chain_random(s1,50);
    print_on_sort(s1);
}