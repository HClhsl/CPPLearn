//
// Created by 28580 on 2023/8/28.
//

#ifndef UNTITLED_SEARCH_H
#define UNTITLED_SEARCH_H
#include "SqList.h"

bool binary_search(SqList_static s,elem_type x,int &locate){
    int head=1,end=s.length;
    while(head<end){
        if(x>s.data[(head+end)/2]) {
            head = (head + end) / 2 + 1;
        }
        else if(x<s.data[(head+end)/2]){
            end=(head+end)/2-1;
        }
        else{
            locate=(head+end)/2;
            return true;
        }
    }
    locate=(head+end)/2;
    return false;

}


#endif //UNTITLED_SEARCH_H
