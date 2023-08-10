//
// Created by 28580 on 2023/8/8.
//
#include "binary_index_tree.h"

int binary_search(element_type* x,int len,element_type key){
    int head=0,rear=len-1;
    int mid=(len-1)/2;
    while(head!=rear) {
        if (x[mid] > key) {
            rear = mid;
            mid = (head + rear) / 2;
        } else if(x[mid] < key){
            head = mid;
            mid = (head + rear) / 2;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    bit x;
    int num=0;
    element_type a[10];
    bit_init_input(x,10);
    bit_in_order(&x,a,num);
    printf("\n");
    for(int i : a){
        printf("%d ",i);
    }
    printf("\n");
    int locate= binary_search(a,10,21);
    if (locate!=-1){
        printf("The number %d located at %d",21,locate+1);
    } else{
        printf("false");
    }

}