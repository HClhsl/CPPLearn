//
// Created by 28580 on 2023/8/4.
//
#include "cstdio"
#include "cstdlib"

typedef int element_type;

typedef struct link_node{
    element_type data;
    link_node* next;
}link;

typedef struct {
    link* front,*rear;
}QNode;

void queue_print(QNode x){
    for(;x.rear!=x.front;){
        printf("%d ",x.front->data);
        x.front=x.front->next;
    }
    printf("\n");
}

void queue_init(QNode &x){
    x.front=(link*) malloc(sizeof (link_node));
    x.rear=x.front;
    x.rear->next=x.front;
}

void queue_insert(QNode &x,element_type a){
    if(x.rear->next==x.front) {
        x.rear->data = a;
        x.rear->next = (link *) malloc(sizeof(link_node));
        x.rear = x.rear->next;
        x.rear->next=x.front;
    } else{
        x.rear->data=a;
        x.rear=x.rear->next;
    }
}

void queue_delete(QNode &x) {
    if (x.rear == x.front){
        printf("空队列");
        return;
    }
    x.front=x.front->next;
}

int main(){
    QNode q1;
    queue_init(q1);
    for(int i=0;i<20;i++)
        queue_insert(q1,2*i);
    queue_print(q1);
    queue_delete(q1);
    queue_delete(q1);
    queue_delete(q1);
    queue_print(q1);
}