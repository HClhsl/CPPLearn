// Created on iPad.

#include <cstdio>
#include <cstdlib>
#define MAX_LENGTH 50

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    LNode *next;
}LNode,*linkList;

int main() {
    ElementType x;
    int n=3;
    linkList p,q;
    p=(LNode*)malloc(sizeof(LNode));//头节点空间申请
    p->next=(LNode*) malloc(sizeof (LNode));
    q=p->next;
    scanf("%d",&x);
    q->data=x;
    while(n){
        q->next=(LNode*) malloc(sizeof (LNode));
        q=q->next;
        scanf("%d",&x);
        q->data=x;
        q->next=NULL;
        n--;
    }
    //q->next=NULL;
    for(linkList k=p->next;k!=NULL;k=k->next){
        printf("%d\t",k->data);
    }
    return 0;
}