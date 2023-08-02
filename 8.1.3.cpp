// Created on iPad.

#include <cstdio>
#include <cstdlib>
#define MAX_LENGTH 50

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    LNode *next;
}LNode,*linkList;

void print_list(linkList x){
    for(x=x->next;x!=nullptr;x=x->next){
        printf("%d\t",x->data);
    }
}

void list_init(linkList &x,ElementType a){
    x=(LNode*) malloc(sizeof (LNode));
    linkList l=(LNode*) malloc(sizeof (LNode));
    x->next=l;
    l->data=a;
    l->next= nullptr;
}

void head_insert(linkList &x,ElementType a){
    linkList t;
//    t=x->next;
//    x->next=(LNode*) malloc(sizeof (LNode));
//    x=x->next;
//    x->data=a;
//    x->next=t;
    t=(linkList) malloc(sizeof (LNode));
    t->next=x->next;
    x->next=t;
    t->data=a;
}

void tail_insert(linkList x,ElementType a){
    while(x->next){
        x=x->next;
    }
    linkList l=(LNode*) malloc(sizeof (LNode));
    x->next=l;
    l->next=nullptr;
    l->data=a;
}

int main() {
//    ElementType x;
//    int n=2;
//    linkList p,q;
//    p=(LNode*)malloc(sizeof(LNode));//头节点空间申请
//    p->next=(LNode*) malloc(sizeof (LNode));
//    q=p->next;
//    scanf("%d",&x);
//    q->data=x;
//    while(n){
//        q->next=(LNode*) malloc(sizeof (LNode));
//        q=q->next;
//        scanf("%d",&x);
//        q->data=x;
//        q->next=nullptr;
//        n--;
//    }
//    head_insert(p,9);
//    print_list(p);
    linkList p;
    list_init(p,5);
    head_insert(p,7);
    tail_insert(p,21);
    print_list(p);
    return 0;
}