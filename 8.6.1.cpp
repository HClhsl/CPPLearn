//
// Created by 28580 on 2023/8/6.
//二分查找
#include "cstdio"
#include "time.h"
#include "cstdlib"

typedef int element_type;

typedef struct {
    element_type *data;
    int len;
}node;

void init(node &x,int num){
    x.len=num;
    x.data=(element_type*)malloc(sizeof (element_type )*x.len);
    srand(time(nullptr));
    for(int i=0;i<x.len;i++) {
        x.data[i] = rand() % 100;
    }
}

void node_print(node &x){
    for(int i=0;i<x.len;i++){
        printf("%3d",x.data[i]);
    }
    printf("\n");
}

int compare(const void* left,const void* right){
    return *(int*)left-*(int*)right;
}

int binary_index(node x,int key){
    int high=x.len-1;
    int low=0;
    int mid=(high+low)/2;
    while(high>=low){
        if(key==x.data[mid]){
            return mid;
        } else if (key<x.data[mid]){
            high=mid-1;
            mid=(high+low)/2;
        }
        else if(key>x.data[mid]){
            low=mid+1;
            mid=(high+low)/2;
        }
    }
    return -1;
}

int main(){
    node n1;
    init(n1,50);
    node_print(n1);
    qsort(n1.data,n1.len,sizeof (element_type), compare);
    node_print(n1);
    element_type t;
    scanf("%d",&t);
    int pos= binary_index(n1,t);
    printf("\n%d",pos);
}

