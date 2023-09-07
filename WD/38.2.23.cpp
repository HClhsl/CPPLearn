//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

void find_public(Sqc a,Sqc b){
    Sqc t1=a->next,t2=b->next;
    while(t1!= nullptr&&t2!= nullptr){
        t1=t1->next;
        t2=t2->next;
    }
    int diff=0,flag=0;
    if(t1== nullptr){
        flag=1;
        while(t2!= nullptr){
            t2=t2->next;
            diff++;
        }
    } else if(t2== nullptr){
        flag=2;
        while(t1!= nullptr){
            t1=t1->next;
            diff++;
        }
    }else{
        diff=0;
    }
    t1=a->next;
    t2=b->next;
    if(flag==2){
        while(diff){
            t1=t1->next;
            diff--;
        }
    } else if(flag==1){
        while (diff){
            t2=t2->next;
            diff--;
        }
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    printf("%3d",t1->data);
    list_print_chain(t1);
}

int main(){
    Sqc a,b,c;
    init_list_chain_random(a,20);
    init_list_chain_random(b,30);
    init_list_chain_random(c,18);
    Sqc t1=a->next,t2=b->next;
    while(t1->next!= nullptr){
        t1=t1->next;
    }
    t1->next=c->next;
    while(t2->next!= nullptr){
        t2=t2->next;
    }
    t2->next=c->next;
    list_print_chain(c);
    find_public(a,b);
    return 0;
}