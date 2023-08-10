//
// Created by 28580 on 2023/8/9.
//
#include "cstdio"
#include "cstdlib"
#include <ctime>

typedef int element_type;

element_type random_num(){
    return rand()%100;
}

typedef struct {
    element_type* data;
    int len;
}STable,*pst;

void STable_init(pst x,int len){
    x->len=len;
    x->data=(element_type*) malloc(sizeof (element_type)*len);
    for(int i=0;i<len;i++){
        x->data[i]=random_num();
    }
}

void STable_print(pst x){
    for(int i=0;i<x->len;i++){
        printf("%d ",x->data[i]);
    }
}

void STable_bubble_sort(pst x){
    int len=x->len-1;
    for(int i=0;i<x->len-1;i++){
        for(len=x->len-1;len-i>0;len--){
            if(x->data[len]<x->data[len-1]){
                int temp=x->data[len];
                x->data[len]=x->data[len-1];
                x->data[len-1]=temp;
            }
        }
    }
}

int main(){
    srand(time(nullptr));
    STable t1;
    STable_init(&t1,30);
    STable_print(&t1);
    printf("\n");
    STable_bubble_sort(&t1);
    STable_print(&t1);
}
