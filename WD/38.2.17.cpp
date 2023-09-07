//
// Created by 28580 on 2023/9/4.
//
#include "SqList.h"

bool is_sym(psd l){
    psd head=l,end=l->prior;
    while(head->next!=end&&head->next!=end->prior) {
        if (head->data == end->data) {
            head=head->next;
            end=end->prior;
        } else{
            return false;
        }
    }
    return true;
}

int main(){
    psd s1;
    elem_type a[10]={1,2,3,4,5,5,4,3,2,1};
    init_double_chain(s1,a);
    list_print_double_recycle(s1);
    bool x= is_sym(s1);
    if(x){
        printf("Symmetrical");
    } else{
        printf("Not symmetrical");
    }
}