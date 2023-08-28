//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

int main(){
    SqList_static s1;
    init_list_random(s1,50);
    list_print(s1);
    list_del_repeat(s1);
    list_print(s1);
}