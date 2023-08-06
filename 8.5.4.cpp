//
// Created by 28580 on 2023/8/5.
//
#include "binary_tree_chain.h"

int main(){
    btn t1;
    aq q1;
    bt_init(t1,q1,'a');
    for(char i=98;i<=106;i++){
        bt_insert(t1,q1,i);
    }
    bt_pre_order(&t1);
    printf("\n");
    bt_in_order(&t1);
    printf("\n");
    bt_post_order(&t1);
    printf("\n");
    bt_level_order(&t1);
}