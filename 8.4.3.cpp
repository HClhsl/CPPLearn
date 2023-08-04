//
// Created by 28580 on 2023/8/4.
//
#include "cstdio"
#include "iostream"
#define max_size 8
using namespace std;

typedef int element_type;
typedef struct {
    element_type data[max_size];
    int front,rear;
}Queue;

bool queue_is_empty(Queue x){
    if(x.rear==x.front)
        return true;
    else
        return false;
}

void queue_init(Queue &x){
    x.front=0;
    x.rear=0;
}

void queue_insert(Queue &x,element_type a){
    if((x.rear+1)%max_size==x.front) {
        cout<<"space error\n";
        return;
    }
    x.data[x.rear]=a;
    x.rear=(x.rear+1)%max_size;
}

void queue_delete(Queue &x){
    if(queue_is_empty(x)) {
        cout<<"the queue is empty\n";
        return;
    }
    x.front=(x.front+1)%max_size;
}

int main(){
    Queue q1;
    queue_init(q1);
    cout<<queue_is_empty(q1)<<"\n";
    for(int i=0;i<9;i++) {
        queue_insert(q1,2*i);
    }
    for(int i=0;i<9;i++) {
        queue_delete(q1);
    }
}