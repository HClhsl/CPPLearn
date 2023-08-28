//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

void list_reverse(SqList_static &s){
    elem_type temp;
    for(int i=1;i<=s.length/2;i++){
        temp=s.data[i];
        s.data[i]=s.data[s.length-i+1];
        s.data[s.length-i+1]=temp;
    }
}

void list_reverse_range(SqList_static &s,int head,int end){
    elem_type temp;
    int num=0;
    for(int i=head;i<=(head+end)/2;i++){
        temp=s.data[i];
        s.data[i]=s.data[end-num];
        s.data[end-num]=temp;
        num++;
    }
}

void list_inverse(SqList_static &s1,int m,int n){
    list_reverse(s1);
    list_print(s1);
    list_reverse_range(s1,1,n);
    list_reverse_range(s1,n+1,m+n);
}

int main(){
    SqList_static s1;
    init_list_random(s1,20);
    list_print(s1);
    list_inverse(s1,15,5);
    list_print(s1);
}
