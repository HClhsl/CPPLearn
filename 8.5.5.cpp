//
// Created by 28580 on 2023/8/5.
//
#include <ctime>
#include "cstdlib"
#include "cstdio"

typedef int element_type;
typedef struct {
    element_type* data;
    int num;
}STable;

void table_init(STable &x,int len){
    x.num=len+1;
    x.data=(element_type*)malloc(sizeof (element_type )*x.num);
    srand(time(nullptr));
    for(int i=1;i<x.num;i++){
        x.data[i]=rand()%100;
    }
}

void table_print(STable x){
    for(int i=1;i<x.num;i++)
        printf("%3d",x.data[i]);
    printf("\n");
}

int search_table(STable x,element_type key){
    int i=x.num-1;
    for(x.data[0]=key;key!=x.data[i];i--);
    return i;
}

int main(){
    STable t1;
    table_init(t1,50);
    table_print(t1);
    int x=search_table(t1,25);
    printf("%d",x);
}