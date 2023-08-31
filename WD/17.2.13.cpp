//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"
#include "cstring"

//该函数的时间复杂度为O(n),空间复杂度为O(n)
elem_type find_min_x(SqList_static s){
    int a[s.length+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=s.length;i++){
        if(s.data[i]>0&&s.data[i]>s.length&&a[s.data[i]]==0) {
            a[s.data[i]] = 1;
        }
    }
    for(int i=1;i<=s.length+1;i++){
        if(a[i]==0)
            return i;
    }
}


int main(){
    SqList_static s1;
    init_list_random_range(s1,50);
    list_print(s1);
    elem_type x= find_min_x(s1);
    printf("%d",x);
}