//
// Created by 28580 on 2023/8/5.
//
#include "binary_tree_chain.h"

int main(){
    btn t1;
    aq q1;
    bt_init(t1,q1,97);
    char t=98;
    for(int i=0;i<7;i++){
        bt_insert(t1,q1,t);
        t++;
    }
    return 0;
}