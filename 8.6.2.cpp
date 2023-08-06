//
// Created by 28580 on 2023/8/6.
//
#include "binary_index_tree.h"

int main(){
    bit t1;
    bit_init(t1,10);
    bit_in_order(&t1);
    printf("\n");
    element_type key;
    scanf("%d",&key);
    bool ret;
    bit_search(t1,key,ret);
    if(ret){
        printf("success\n");
    } else {
        printf("fail\n");
    }
    bit_delete(t1,key);
    bit_in_order(&t1);
    return 0;
}