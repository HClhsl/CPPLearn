//
// Created by 28580 on 2023/8/27.
//

#ifndef UNTITLED_SQLIST_H
#define UNTITLED_SQLIST_H

#include "cstdlib"
#include "cstdio"
#include <ctime>

#define max_size_pe 200

typedef int elem_type;

typedef struct SqList_static{
    elem_type data[max_size_pe];
    int length;
}SqList_static;

typedef struct SqList_chain{
    elem_type data;
    SqList_chain* next;
}*Sqc;

typedef struct SqList_double_recycle_chain{
    elem_type data;
    SqList_double_recycle_chain *next,*prior;
}*psd;

elem_type number_generate(){
    return rand() % 100;
}

bool init_list_random(SqList_static &s,int num){
    srand(time(nullptr));
    s.length=0;
    for(int i=1;i<=num;i++){
        s.data[i]=number_generate();
        s.length++;
    }
    return true;
}

bool init_list_random_recycle(Sqc &s,int num){
    srand(time(nullptr));
    s=(Sqc) malloc(sizeof (SqList_chain));  //头节点的建立
    Sqc temp=s;
    temp->next= nullptr;
    for(int i=1;i<=num;i++){
        temp->next= (Sqc)malloc(sizeof (SqList_chain));
        temp=temp->next;
        temp->data=number_generate();
        temp->next= s->next;
    }
    return true;
}

void list_print_recycle(Sqc s){
    Sqc temp=s->next;
    printf("%3d",temp->data);
    for(temp=temp->next;temp!=s->next;temp=temp->next){
        printf("%3d",temp->data);
    }
    printf("\n");
}

bool init_list_chain_random(Sqc &s,int n){
    srand(time(nullptr));
    s=(Sqc) malloc(sizeof (SqList_chain));  //头节点的建立
    Sqc temp=s;
    temp->next= nullptr;
    for(int i=1;i<=n;i++){
        temp->next= (Sqc)malloc(sizeof (SqList_chain));
        temp=temp->next;
        temp->data=number_generate();
        temp->next= nullptr;
    }
    return true;
}

bool init_double_chain(psd &x,elem_type *a){
    psd temp;
    temp=(psd) malloc(sizeof (SqList_double_recycle_chain));
    temp->data=a[0];
    temp->next=temp;
    temp->prior=temp;
    x=temp;
    for(int i=1;i<10;i++){
        psd t=(psd) malloc(sizeof (SqList_double_recycle_chain));
        t->data=a[i];
        temp->next=t;
        t->prior=temp;
        t->next=x;
        temp=t;
        x->prior=t;
    }
    return true;
}

bool init_double_chain_random(psd &x,int num){
    psd temp;
    temp=(psd) malloc(sizeof (SqList_double_recycle_chain));
    temp->data=number_generate();
    temp->next=temp;
    temp->prior=temp;
    x=temp;
    for(int i=1;i<num;i++){
        psd t=(psd) malloc(sizeof (SqList_double_recycle_chain));
        t->data=number_generate();
        temp->next=t;
        t->prior=temp;
        t->next=x;
        temp=t;
        x->prior=t;
    }
    return true;
}

bool list_print(SqList_static s){
    if(s.length==0)
        return false;
    for(int i=1;i<=s.length;i++){
        printf("%3d",s.data[i]);
    }
    printf("\n");
    return true;
}

bool list_print_chain(Sqc s){
    s=s->next;
    while(s!= nullptr){
        printf("%3d",s->data);
        s=s->next;
    }
    printf("\n");
    return true;
}

bool list_print_double_recycle(psd x){
    psd t=x;
    for(;x!=t->prior;x=x->next) {
        printf("%3d", x->data);
    }
    printf("%3d\n", x->data);
    return true;
}

bool list_insert(SqList_static &s,int locate,int data){
    if(s.length == max_size_pe || locate < 1 || locate > s.length + 1)
        return false;
    for(int i=s.length;i>=locate;i--){
        s.data[i+1]=s.data[i];
    }
    s.data[locate]=data;
    s.length++;
    return true;
}

bool list_insert_chain_head(Sqc &s,int data){
    Sqc t=(Sqc)malloc(sizeof (SqList_chain));
    t->next=s->next;
    t->data=data;
    s->next=t;
    return true;
}

bool list_insert_chain_tail(Sqc s,int data){
    while(s->next!= nullptr){
        s=s->next;
    }
    s->next=(Sqc)malloc(sizeof (SqList_chain));
    s->next->data=data;
    s->next->next= nullptr;
    return true;
}

bool list_del(SqList_static &s,int locate,elem_type &data){
    if(locate>s.length||locate<1||s.length==0)
        return false;
    data=s.data[locate];
    for(int i=locate;i<s.length;i++){
        s.data[i]=s.data[i+1];
    }
    s.length--;
    return true;
}

bool list_del_chain_head(Sqc &s){
    Sqc temp=s->next;
    s->next=s->next->next;
    free(temp);
    return true;
}

bool list_del_chain_tail(Sqc s){
    while(s->next->next!= nullptr){
        s=s->next;
    }
    Sqc temp=s->next;
    s->next= nullptr;
    free(temp);
    return true;
}

void list_del_repeat(SqList_static &s){
    elem_type data;
    for(int i=1;i<s.length;i++) {
        for (int t = i + 1; t < s.length; t++) {
            if (s.data[t] == s.data[i]) {
                list_del(s, t, data);
            }
        }
    }
}

bool init_list_random_range(SqList_static &s,int num){
    srand(time(nullptr));
    s.length=0;
    for(int i=1;i<=num;i++){
        s.data[i]=number_generate()%30;
        s.length++;
    }
    return true;
}

void list_chain_reverse(Sqc s){
    Sqc p,q,r;
    p=s->next;
    q=p->next;
    r=q->next;
    for(;r!= nullptr;){
        p->next=r;
        q->next=s->next;
        s->next=q;
        q=p->next;
        r=r->next;
    }
    p->next= nullptr;
    q->next=s->next;
    s->next=q;
}

#endif //UNTITLED_SQLIST_H
