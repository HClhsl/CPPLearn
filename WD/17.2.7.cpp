//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

SqList_static list_merge(SqList_static s1,SqList_static s2){
    if((s1.length+s2.length)>max_size) {
        printf("Storage Error!!!");
        SqList_static s0;
        return s0;
    }
    SqList_static s3;
    for(int i=1;i<=s1.length;i++){
        s3.data[i]=s1.data[i];
    }
    for(int i=1;i<=s2.length;i++){
        s3.data[i+s1.length]=s2.data[i];
    }
    s3.length=s1.length+s2.length;
    return s3;
}

int main(){
    SqList_static s1,s2,s3;
    init_list_random(s1,20);
    init_list_random(s2,25);
    s3=list_merge(s1,s2);
    list_print(s1);
    list_print(s2);
    list_print(s3);
}