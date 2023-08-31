//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"
#include "cstring"

//该函数的时间复杂度为O(n),空间复杂度为O(1)
elem_type find_main(SqList_static s){
    int c=s.data[0];
    int num=1;
    for(int i=1;i<=s.length;i++){
        if(c==s.data[i]){
            num++;
        } else{
            if(num>0){
                num--;
            } else
                c=s.data[i];
        }
    }
    num=0;
    for(int i=1;i<=s.length;i++){
        if(c==s.data[i])
            num++;
    }
    if(num>s.length/2)
        return c;
    else
        return -1;
}

int main(){
    SqList_static s1;
    init_list_random_range(s1,10);
    list_print(s1);
    elem_type x= find_main(s1);
    printf("%d",x);
}
//该函数的时间复杂度为O(n),空间复杂度为O(n)
//elem_type find_main(SqList_static s){
//    elem_type a[s.length];
//    memset(a,0,sizeof(a));
//    for(int i=1;i<=s.length;i++){
//        a[s.data[i]]++;
//    }
//    elem_type x=0;
//    for(int i=1;i<s.length;i++){
//        if(a[i]>s.length/2){
//            if(a[i]>a[x]){
//                x=i;
//            }
//        }
//    }
//    if(x==0&&a[0]<s.length/2)
//        return -1;
//    else
//        return x;
//}