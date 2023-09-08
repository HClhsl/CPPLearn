//
// Created by 28580 on 2023/8/28.
//
#include "SqList.h"
#include "Sort.h"

elem_type find_mid(SqList_static s1,SqList_static s2){
    int mid_a=s1.data[s1.length/2],mid_b=s2.data[s2.length/2];

}


int main(){
    SqList_static s1,s2;
    init_list_random(s1,20);
    init_list_random(s2,20);
    list_del_repeat(s1);
    list_del_repeat(s2);
    quick_sort(s1,1,s1.length);
    quick_sort(s2,1,s2.length);

}