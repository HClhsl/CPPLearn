//
// Created by 28580 on 2023/8/2.
//
#include <cstdio>
#include <cstdlib>

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    LNode *next;
}LNode,*linkList;

void print_list(linkList x){
    for(x=x->next;x!=nullptr;x=x->next){
        printf("%d\t",x->data);
    }
    printf("\n");
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
    t=(linkList) malloc(sizeof (LNode));
    t->next=x->next;
    x->next=t;
    t->data=a;
}

void tail_insert(linkList x,ElementType a,ElementType b){
    while(x->next){
        x=x->next;
    }
    linkList l=(LNode*) malloc(sizeof (LNode));
    x->next=l;
    l->next=(LNode*) malloc(sizeof (LNode));
    l->data=a;
    l=l->next;
    l->next= nullptr;
    l->data=b;
}

ElementType search_by_location(linkList x,int locate){
    x=x->next;
    while(x->next!= nullptr){
        if(locate!=1){
            x=x->next;
            locate--;
        }
        else{
            return x->data;
        }
    }
    printf("Locate Error");
    return 0;
}

int search_by_data(linkList x,ElementType data){
    int n=0;
    while(x->data!=data&&x->next!= nullptr){
        x=x->next;
        n++;
    }
    if((x->data==data)) {
        return n;
    }
    else{
        printf("No such data\n");
        return 0;
    }
}

linkList GetEle(linkList x,int locate){
    while(x!= nullptr){
        if(locate!=0){
            x=x->next;
            locate--;
        }
        else{
            return x;
        }
    }
    printf("Locate Error\n");
    return nullptr;
}

void insert_in_locate(linkList x,int locate,ElementType a){
    linkList l= GetEle(x,locate-1);
    if(l==nullptr){
        printf("Location Error\n");
        return;
    }
    linkList t=(linkList) malloc(sizeof (LNode));
    t->next=l->next;
    l->next=t;
    t->data=a;
}

int main(){
    linkList p;
    list_init(p,1);
    int x[10];
    x[0]=1;
    x[1]=1;
    for(int i=2;i<10;i++){
        x[i]=x[i-1]+x[i-2];
        head_insert(p,x[i]);
    }
    print_list(p);
    insert_in_locate(p,7,77);
    print_list(p);
//    int ret=search_by_data(p,13);
//    printf("13 located at %d of the LNode\n",ret);
//    ElementType t= search_by_location(p,5);
//    printf("The 5  of the LNode is %d\n",t);
}