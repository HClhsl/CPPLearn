//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

void list_del_repeat(SqList_static &s){
    elem_type data;
    for(int i=1;i<s.length;i++){
        for(int t=i+1;t<s.length;t++){
            if(s.data[t]==s.data[i]){
                list_del(s,t,data);
            }
        }
    }
}

int main(){
    SqList_static s1;
    init_list_random(s1,50);
    list_print(s1);
    list_del_repeat(s1);
    list_print(s1);
}