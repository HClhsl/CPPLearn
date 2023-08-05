//
// Created by 28580 on 2023/8/4.
//
#include "cstdio"
#include "iostream"
#define MaxSize 5

using namespace std;

typedef int element_type;
typedef struct {
    element_type data[MaxSize];
    int rear,front;
}queue;

void queue_init(queue &x){
    x.rear=0;
    x.front=0;
}

void queue_insert(queue &x,element_type a){
    if((x.rear+1)%MaxSize==x.front){
        printf("false\n");
        return;
    }
    x.data[x.rear]=a;
    x.rear=(x.rear+1)%MaxSize;
}

void queue_delete(queue &x){
    if(x.front==x.rear){
        printf("false\n");
        return;
    }
    cout<<x.data[x.front]<<" ";
    x.front=(x.front+1)%MaxSize;
}

int main(){
    queue q;
    queue_init(q);
    element_type a;
    for(int i=1;i<6;i++){
        scanf("%d",&a);
        queue_insert(q,a);
    }
    for(int i=0;i<4;i++){
        queue_delete(q);
    }

}