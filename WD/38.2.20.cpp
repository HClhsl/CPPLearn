//
// Created by 28580 on 2023/9/6.
//
#include "SqList.h"

typedef struct fre_chain {
    elem_type data;
    fre_chain *pre,*next;
    int fre;
}fc,*pfc;

void init_fre_chain(pfc &l,int num){
    srand(time(nullptr));
    l=(pfc) malloc(sizeof (fc));
    l->next= nullptr;
    l->pre= nullptr;
    pfc temp=l,pre=l;
    for(int i=0;i<num;i++){
        temp->next=(pfc) malloc(sizeof (fc));
        temp=temp->next;
        temp->data=number_generate()%10;
        temp->pre=pre;
        temp->fre=0;
        temp->next= nullptr;
        pre=pre->next;
    }
}

void print_fre_chain(pfc l){
    l=l->next;
    while(l!= nullptr){
        printf("%3d",l->data);
        l=l->next;
    }
    printf("\n");
}

void locate(pfc L,elem_type x){
    pfc s=L;
    while(L!= nullptr){
        if(x==L->data){
            break;
        }
        L=L->next;
    }
    if(L!= nullptr){
        L->fre++;
    } else{
        return;
    }
    s=s->next;
    for(;s!= nullptr;s=s->next){
        if(L->fre>=s->fre){
            L->pre->next=L->next;
            L->next->pre=L->pre;
            L->next=s;
            L->pre=s->pre;
            s->pre->next=L;
            s->pre=L;
            break;
        }
    }
}

int main(){
    pfc l;
    init_fre_chain(l,20);
    print_fre_chain(l);
    locate(l,8);
    locate(l,5);
    locate(l,3);
    print_fre_chain(l);
}