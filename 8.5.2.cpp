//
// Created by 28580 on 2023/8/5.
//
#include "binary_tree_chain.h"

int main(){
    btn t1;
    aq q1;
    bt_init(t1,q1,97);
    char t=98;
    for(int i=0;i<10;i++){
        bt_insert(t1,q1,t);
        t++;
    }
    bt_pre_order(&t1);
    printf("\n");
    bt_in_order(&t1);
    printf("\n");
    bt_post_order(&t1);
    printf("\n");
    bt_level_order(&t1);

}