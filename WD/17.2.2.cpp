//
// Created by 28580 on 2023/8/27.
//
#include "../SqList.h"

void list_reverse(SqList_static &s){
    elem_type temp;
    for(int i=1;i<=s.length/2;i++){
        temp=s.data[i];
        s.data[i]=s.data[s.length-i+1];
        s.data[s.length-i+1]=temp;
    }
}

int main(){
    SqList_static s1;
    init_list_random(s1,21);
    list_print(s1);
    list_reverse(s1);
    list_print(s1);
}