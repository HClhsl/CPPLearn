//
// Created by 28580 on 2023/8/27.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
#include "SqList.h"

void swamp(elem_type &x,elem_type &y){
    elem_type temp=x;
    x=y;
    y=temp;
}

int partition(SqList_static &s,int L,int R){
    int head=L-1;
    int end=L;
    elem_type key=s.data[R];
    for(;end<R;end++){
        if(s.data[end]<key){
            head++;
            swamp(s.data[head],s.data[end]);
        }
    }
    swamp(s.data[R],s.data[head+1]);
    return head+1;
}

void quick_sort(SqList_static &s,int L,int R){
    if(L<R){
        int q= partition(s,L,R);
        quick_sort(s,L,q-1);
        quick_sort(s,q+1,R);
    }
}


#endif //UNTITLED_QUEUE_H
