//
// Created by 28580 on 2023/9/8.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
#include "cstdio"
#include "cstdlib"
#include "ctime"

#define max_size 25

typedef int elem_type;
typedef struct recycle_queue{
    elem_type data[max_size]={0};
    int front=0,rear=0,tag=0;
}rq;

typedef struct queue_chain_node{
    elem_type data;
    queue_chain_node *next;
}qcn,*pqcn;

typedef struct queue_chain{
    pqcn front,rear,h;
}qc;


elem_type number_generate(){
    return rand()%100;
}

elem_type de_queue(rq &q){
    if(q.rear==q.front&&q.tag==0){
        printf("Empty Queue!\n");
        return -1;
    }
    else{
        elem_type data=q.data[q.front];
        printf("%3d",q.data[q.front]);
        q.front=(q.front+1)%max_size;
        q.tag=0;
        return data;
    }
}

void en_queue(rq &q,elem_type data){
    if(q.rear==q.front&&q.tag==1){
        printf("Full Queue!\n");
        return;
    }else{
        q.data[q.rear]=data;
        q.rear=(q.rear+1)%max_size;
        q.tag=1;
    }
}

void clear_queue(rq &q){
    if(q.rear==q.front&&q.tag==0){
        printf("Empty Queue!\n");
        return;
    }
    if(q.rear==q.front&&q.tag==1){
        printf("%3d",q.data[q.front]);
        q.front=(q.front+1)%max_size;
    }
    for(;q.rear!=q.front;){
        printf("%3d",q.data[q.front]);
        q.front=(q.front+1)%max_size;
    }
    printf("\n");
    q.tag=0;
}

void print_queue(rq q){
    if(q.rear==q.front&&q.tag==0){
        printf("Empty Queue!\n");
        return;
    }
    if(q.rear==q.front&&q.tag==1){
        printf("%3d",q.data[q.front]);
        q.front=(q.front+1)%max_size;
    }
    for(;q.rear!=q.front;){
        printf("%3d",q.data[q.front]);
        q.front=(q.front+1)%max_size;
    }
    printf("\n");
    q.tag=0;
}

void init_queue_chain(qc &q, int num){
    srand(time(nullptr));
    q.h=(pqcn) malloc(sizeof (qcn));  //头节点的声明
    pqcn temp=q.h;
    while(num){
        temp->next=(pqcn) malloc(sizeof (qcn));
        temp=temp->next;
        temp->data=number_generate();
        num--;
    }
    temp->next= (pqcn)malloc(sizeof (qcn));
    q.rear=temp->next;
    temp->next->next=q.h->next;
    q.front=q.h->next;
}

bool queue_is_full_chain(qc q){
    return q.rear->next==q.front;
}

void print_queue_chain(qc q){
    while(q.front!=q.rear){
        printf("%3d",q.front->data);
        q.front=q.front->next;
    }
    printf("\n");
}

void en_queue_chain(qc &q,elem_type data){
    if(queue_is_full_chain(q)){
        pqcn temp=q.rear->next;
        q.rear->next=(pqcn) malloc(sizeof (qcn));
        q.rear->data=data;
        q.rear=q.rear->next;
        q.rear->next=temp;
    }else{
        q.rear->data=data;
        q.rear=q.rear->next;
    }
}

void de_queue_chain(qc &q){
    if(q.rear==q.front){
        printf("Empty Queue!\n");
    }
    else{
        printf("%3d",q.front->data);
        q.front=q.front->next;
    }
}

#endif //UNTITLED_QUEUE_H
