//
// Created by 28580 on 2023/8/6.
//

#ifndef UNTITLED_BINARY_INDEX_TREE_H
#define UNTITLED_BINARY_INDEX_TREE_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef int element_type;

typedef struct binary_index_tree{
    element_type data;
    binary_index_tree* left_child;
    binary_index_tree* right_child;
}bit,*p_bit;

element_type number_generate(){
    return rand() % 100;
}

int bit_compare(bit &x,element_type a){
    return x.data-a;
}

void bit_insert(bit &x,element_type a){
    if(bit_compare(x,a)>0&&x.left_child!= nullptr){
        bit_insert(*(x.left_child),a);
    } else if(bit_compare(x,a)>0&&x.left_child== nullptr){
        x.left_child=(p_bit) malloc(sizeof (bit));
        x.left_child->left_child= nullptr;
        x.left_child->right_child= nullptr;
        x.left_child->data=a;
    } else if(bit_compare(x,a)<=0&&x.right_child!= nullptr){
        bit_insert(*x.right_child,a);
    } else if (bit_compare(x,a)<=0&&x.right_child== nullptr){
        x.right_child=(p_bit) malloc(sizeof (bit));
        x.right_child->right_child= nullptr;
        x.right_child->left_child= nullptr;
        x.right_child->data=a;
    }
}

void bit_init(bit &x,int num){
    srand(time(nullptr));
    x.data=number_generate();
    x.left_child= nullptr;
    x.right_child= nullptr;
    for(int i=1;i<num;i++){
        bit_insert(x,number_generate());
    }
}

void bit_in_order(p_bit x){
    if(x!= nullptr){
        bit_in_order(x->left_child);
        printf("%d ",x->data);
        bit_in_order(x->right_child);
    }
}

void bit_search(bit x,element_type key,bool &ret){
    if(bit_compare(x,key)>0){
        if(x.left_child!= nullptr)
            bit_search(*x.left_child,key,ret);
        else
            ret=false;
    } else if(bit_compare(x,key)==0){
        ret=true;
    } else if(bit_compare(x,key)<0){
        if(x.right_child!= nullptr)
            bit_search(*x.right_child,key,ret);
        else
            ret=false;
    }
}

void bit_delete(bit &x,element_type key){
    if(&x== nullptr){
        return;
    }
    if(x.data>key){
        bit_delete(*x.left_child,key);
    } else if(x.data<key){
        bit_delete(*x.right_child,key);
    } else{
        if(x.left_child== nullptr){
            p_bit temp=&x;
            x=*x.right_child;
            free(temp);
        } else if(x.right_child== nullptr){
            p_bit temp=&x;
            x=*x.left_child;
            free(temp);
        }else{
            p_bit temp=x.left_child;
            while(temp->right_child!= nullptr){
                temp=temp->right_child;
            }
            x.data=temp->data;
            bit_delete(*x.left_child,temp->data);
        }
    }

}

#endif //UNTITLED_BINARY_INDEX_TREE_H
