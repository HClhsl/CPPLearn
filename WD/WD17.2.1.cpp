//
// Created by 28580 on 2023/8/27.
//
#include "../SqList.h"

bool del_min(SqList_static &s){
    int min=s.data[1];
    int min_locate=1;
    for(int i=2;i<=s.length;i++){
        if(s.data[i]<min){
            min=s.data[i];
            min_locate=i;
        }
    }
    s.data[min_locate]=s.data[s.length];
    return true;
}

int main(){
    SqList_static s1;
    init_list_random(s1,20);
    list_print(s1);
    //list_insert(s1,3,21);
    //list_print(s1);
    //elem_type data;
    //list_del(s1,5,data);
    //list_print(s1);
    //printf("%d",data);
    del_min(s1);
    list_print(s1);
}