//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"
#include "Sort.h"
#include "Search.h"

int main(){
    SqList_static s1;
    init_list_random(s1,30);
    list_del_repeat(s1);
    list_print(s1);
    quick_sort(s1,1,s1.length);
    list_print(s1);
    int locate;
    bool flag= binary_search(s1,25,locate);
    if(flag){
        swamp(s1.data[locate],s1.data[locate+1]);
    } else{
        list_insert(s1,locate,25);
    }
    list_print(s1);
}