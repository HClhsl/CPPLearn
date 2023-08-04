//
// Created by 28580 on 2023/8/3.
//
#include "cstdio"
#include "cstdlib"

typedef struct LNode{
    int data;
    LNode* next;
}Node,*p_node;

void node_print(p_node x){
    for(x=x->next;x!= nullptr;x=x->next){
        printf("%d ",x->data);
    }
    printf("\n");
}

void insert_head(p_node &x){
    int a;
    p_node l;
    x=(p_node) malloc(sizeof (Node));
    x->next= nullptr;
    scanf("%d",&a);
    for(;a!=9999;){
        l=(p_node) malloc(sizeof (Node));
        l->next=x->next;
        l->data=a;
        x->next=l;
        scanf("%d",&a);
    }
}

p_node node_split(p_node x){
    p_node a,b;
    a=x->next;
    b=a;
    for(;b->next!= nullptr;a=a->next){
        b=b->next;
        if(b->next== nullptr)
            break;
        b=b->next;
    }
    p_node t=(p_node) malloc(sizeof (LNode));
    t->next=a->next;
    a->next= nullptr;
    return t;
}

void node_reverse(p_node &x){
    if (x->next== nullptr){
        return;
    }
    p_node r,s,t;
    r=x->next;
    s=r->next;
    t=s->next;
    while(t!= nullptr){
        s->next=r;
        r=s;
        s=t;
        t=t->next;
    }
    s->next=r;
    t=x->next;
    x->next=s;
    t->next= nullptr;
}

void node_merge(p_node x,p_node y){
    p_node cur,p,q;
    cur=p=x->next;
    q=y->next;
    for(;p!= nullptr&&q!= nullptr;){
        p=p->next;
        cur->next=q;
        q=q->next;
        cur=cur->next;
        cur->next=p;
        cur=cur->next;
    }
    if(p!= nullptr){
        cur->next=p;
        cur->next->next= nullptr;
    }
    if(q!= nullptr){
        cur->next=q;
        cur->next->next= nullptr;
    }
}

int main(){
    p_node l;
    insert_head(l);
    node_print(l);
    p_node n= node_split(l);
    node_print(l);
    node_print(n);
    node_reverse(n);
    node_print(n);
    node_merge(l,n);
    node_print(l);
}