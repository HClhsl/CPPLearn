//
// Created by 28580 on 2023/8/5.
//
#include "binary_tree_array.h"

int main(){
    btn t1;
    aq q1;
    bt_init(t1,q1,'a');
    char data=98;
    for(int i=0;i<5;i++){
        bt_insert(t1,q1,data);
        data++;
    }
    return 0;
}