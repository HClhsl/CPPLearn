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

bool queue_is_empty(aq x){
    return x.rear==x.front;
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

void bt_pre_order_for_WPL(p_btn x,int length,int &sum){
    if(x->left_child== nullptr&&x->right_child== nullptr) {
        sum+=length*x->data;
    }
    if(x->left_child!= nullptr){
        bt_pre_order_for_WPL(x->left_child, length + 1, sum);
    }
    if(x->right_child!= nullptr){
        bt_pre_order_for_WPL(x->right_child,length+1,sum);
    }
}

void bt_pre_order(p_btn x){
    if(x!= nullptr) {
        putchar(x->data);
        bt_pre_order(x->left_child);
        bt_pre_order(x->right_child);
    }
}

void bt_in_order(p_btn x){
    if(x!= nullptr){
        bt_in_order(x->left_child);
        putchar(x->data);
        bt_in_order(x->right_child);
    }
}

void bt_post_order(p_btn x){
    if(x!= nullptr){
        bt_post_order(x->left_child);
        bt_post_order(x->right_child);
        putchar(x->data);
    }
}

void bt_level_order(p_btn x){
    aq q1;
    queue_init(q1);

    queue_insert(q1,x);
    for(; !queue_is_empty(q1);){
        x=q1.front->data;
        printf("%c",q1.front->data->data);
        queue_delete(q1);
        if(x->left_child!= nullptr) {
            queue_insert(q1,x->left_child);
        }
        if(x->right_child!= nullptr){
            queue_insert(q1,x->right_child);
        }
    }
}

#endif //UNTITLED_BINARY_TREE_CHAIN_H
