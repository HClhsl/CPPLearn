//
// Created by 28580 on 2023/8/5.
//


#ifndef UNTITLED_BINARY_TREE_H
#define UNTITLED_BINARY_TREE_H

#include "cstdio"
#include "cstdlib"
#define MaxSize 50

typedef char element_type;
typedef struct binary_tree_node{
    element_type data;
    binary_tree_node* left_child;
    binary_tree_node* right_child;
}btn,*p_btn;

typedef struct auxiliary_queue{
    p_btn data[MaxSize];
    int rear,front;
}aq;

void bt_insert(btn &x,aq &y,element_type a){
    if(y.data[y.front]->left_child== nullptr){
        y.data[y.front]->left_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.data[y.front]->left_child;
        temp->data=a;
        y.data[y.rear++]=temp;
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
    else if(y.data[y.front]->right_child== nullptr){
        y.data[y.front]->right_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.data[y.front]->right_child;
        temp->data=a;
        y.data[y.rear++]=temp;
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
    else{
        y.data[++y.front]->left_child=(p_btn) malloc(sizeof (btn));
        p_btn temp=y.data[y.front]->left_child;
        temp->data=a;
        y.data[y.rear++]=temp;
        temp->left_child= nullptr;
        temp->right_child= nullptr;
    }
}

void bt_init(btn &x,aq &a1,element_type a){
    a1.rear=a1.front=0;
    a1.data[a1.rear++]=&x;
    x.left_child= nullptr;
    x.right_child= nullptr;
    x.data=a;
}

#endif //UNTITLED_BINARY_TREE_H
