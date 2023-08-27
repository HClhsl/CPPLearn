//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

bool list_del_range(SqList_static &s,elem_type small,elem_type big){
    if(s.length==0){
        return false;
    }
    int num=0;
    elem_type data;
    for(int i=1;i<=s.length;i++){
        if(s.data[i]>=small&&s.data[i]<=big){
            list_del(s,i,data);
            num++;
            i--;
        }
    }
    if(num==0){
        return false;
    }
    return true;
}

int main(){
    SqList_static s1;
    init_list_random(s1,50);
    list_print(s1);
    list_del_range(s1,10,99);
    list_print(s1);
}