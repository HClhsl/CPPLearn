//
// Created by 28580 on 2023/8/31.
//
#include <unistd.h>
#include "SqList.h"
#include "cmath"

bool is_min(int a,int b,int c){
    if(a<=b&&a<=c)
        return true;
    return false;
}

int min_triple_ele(SqList_static s1,SqList_static s2,SqList_static s3){
    int D_min=0xFFFFFFF,D;
    int i=1,j=1,k=1;
    while(i<s1.length&&j<s2.length&&k<s3.length&&D_min>0){
        D= abs(s1.data[i]-s2.data[j])+abs(s1.data[j]-s2.data[k])+abs(s1.data[k]-s2.data[i]);
        if(D<D_min)
            D_min=D;
        if(is_min(s1.data[i],s2.data[j],s3.data[k]))
            i++;
        else if(is_min(s2.data[j],s3.data[k],s1.data[i]))
            j++;
        else k++;
    }
    return D_min;
}

int main(){
    SqList_static s1,s2,s3;
    init_list_random(s1,20);
    sleep(1);
    init_list_random(s2,20);
    sleep(1);
    init_list_random(s3,20);
    list_print(s1);
    list_print(s2);
    list_print(s3);
    int x= min_triple_ele(s1,s2,s3);
    printf("%d",x);
}