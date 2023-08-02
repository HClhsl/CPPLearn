//
// Created by 28580 on 2023/8/2.
//
#include <cstdlib>
#include <cstdio>

typedef struct node{
    int data;
    struct node* next;
}NODE,*LNode;

void list_init(LNode &x,int a){
    x=(LNode) malloc(sizeof (NODE));
    x->next= (LNode)malloc(sizeof (NODE));
    LNode l=x->next;
    l->next= nullptr;
    l->data=a;
}

void head_insert(LNode x,int a){
    LNode l=(LNode) malloc(sizeof (NODE));
    l->next=x->next;
    x->next=l;
    l->data=a;
}

void list_print(LNode x){
    x=x->next;
    while (x!= nullptr){
        printf("%d\t",x->data);
        x=x->next;
    }
    printf("\n");
}

LNode split_list(LNode x){
    int n=0;
    LNode l=x;
    while(l!= nullptr){
        l=l->next;
        n++;
    }
    l=x;
    for(int i=0;i<n/2;i++) {
        l = l->next;
        x=l;
    }
    l = l->next;
    x->next= nullptr;
    return l;
}

void list_inverse(LNode x){
    LNode t1,t2,t3,temp;
    t1=x->next;
    for(;x!= nullptr;){
        t1=x->next;
        t2=t1->next;
        t3=t2->next;
        x->next->next=t1;
        x=x->next;
    }

}

int main(){
    LNode p;
    list_init(p,1);
    int x[20];
    x[0]=1;
    x[1]=1;
    for(int i=2;i<20;i++){
        x[i]=x[i-1]+x[i-2];
        head_insert(p,x[i]);
    }
    list_print(p);
    LNode q;
    q=(LNode) malloc(sizeof (NODE));
    q->next=split_list(p);
    list_print(p);
    list_print(q);
}