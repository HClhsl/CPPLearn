//
// Created by 28580 on 2023/8/27.
//
#include "SqList.h"

void del_x(SqList_static &s,elem_type x){
    int num=0;
    for(int i=1;i<=s.length;i++) {
        if (s.data[i] == x) {
            printf("%d\n",i);
            num++;
        }
        s.data[i]=s.data[i+num];
    }
    s.length-=num;
}

int main(){
    SqList_static s1;
    init_list_random(s1,100);
    list_print(s1);
    del_x(s1,9);
    list_print(s1);
}
