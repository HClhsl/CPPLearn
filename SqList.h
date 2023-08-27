//
// Created by 28580 on 2023/8/27.
//

#ifndef UNTITLED_SQLIST_H
#define UNTITLED_SQLIST_H

#include "cstdlib"
#include "cstdio"
#include "time.h"

#define max_size 50

typedef int elem_type;

typedef struct SqList_static{
    elem_type data[max_size];
    int length;
}SqList_static;

typedef struct SqList_dynamic{
    elem_type *data;
    int max,length;
}SqList_dynamic;

elem_type number_generate(){
    return rand() % 100;
}

bool init_list_random(SqList_static &s,int num){
    if(s.length!=0)
        return false;
    srand(time(nullptr));
    s.length=0;
    for(int i=1;i<=num;i++){
        s.data[i]=number_generate();
        s.length++;
    }
    return true;
}

bool list_print(SqList_static s){
    if(s.length==0)
        return false;
    for(int i=1;i<=s.length;i++){
        printf("%3d",s.data[i]);
    }
    printf("\n");
    return true;
}

bool list_insert(SqList_static &s,int locate,int data){
    if(s.length==max_size||locate<1||locate>s.length+1)
        return false;
    for(int i=s.length;i>=locate;i--){
        s.data[i+1]=s.data[i];
    }
    s.data[locate]=data;
    s.length++;
    return true;
};

bool list_del(SqList_static &s,int locate,elem_type &data){
    if(locate>s.length||locate<1||s.length==0)
        return false;
    data=s.data[locate];
    for(int i=locate;i<s.length;i++){
        s.data[i]=s.data[i+1];
    }
    s.length--;
    return true;
}

#endif //UNTITLED_SQLIST_H
