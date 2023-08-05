//
// Created by 28580 on 2023/8/5.
//

#ifndef UNTITLED_BINARY_TREE_CHAIN_H
#define UNTITLED_BINARY_TREE_CHAIN_H

#include "cstdio"
#include "cstdlib"

typedef char element_type;
typedef struct binary_tree_node{
    element_type data;
    binary_tree_node* left_child;
    binary_tree_node* right_child;
}btn,*p_btn;

typedef struct auxiliary_queue_node{
    p_btn data;
    auxiliary_queue_node* next;
}aqn,*p_aqn;

typedef struct auxiliary_queue{
    p_aqn rear,front;
}aq;

void queue_init(aq &x){
    x.front=(p_aqn) malloc(sizeof (aqn));
    x.rear=x.front;
    x.front->next= nullptr;
}

void queue_insert(aq &x,p_btn y){
    x.rear->data=y;
    p_aqn temp=(p_aqn) malloc(sizeof (aqn));
    x.rear->next=temp;
    x.rear=temp;
    x.rear->next= nullptr;
}

void queue_delete(aq &x){
    p_aqn temp=x.front;
    x.front=x.front->next;
    free(temp);
}

void bt_insert(btn &x,aq &y,element_type a){
    if(y.front->data->left_child== nullptr){
        y.front->data->left_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.front->data->left_child;
        temp->data=a;
        queue_insert(y,temp);
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
    else if(y.front->data->right_child== nullptr){
        y.front->data->right_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.front->data->right_child;
        temp->data=a;
        queue_insert(y,temp);
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
    else{
        queue_delete(y);
        y.front->data->left_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.front->data->left_child;
        temp->data=a;
        queue_insert(y,temp);
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
}

void bt_init(btn &x,aq &y,element_type a){
    queue_init(y);
    queue_insert(y,&x);
    x.left_child= nullptr;
    x.right_child= nullptr;
    x.data=a;
}

#endif //UNTITLED_BINARY_TREE_CHAIN_H
