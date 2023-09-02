//
// Created by 28580 on 2023/9/2.
//
#include <unistd.h>
#include "SqList.h"

void find_public(Sqc s1,Sqc s2){
    int len1=0,len2=0;
    Sqc t1=s1,t2=s2;
    while(t1!= nullptr){
        len1++;
        t1=t1->next;
    }
    while (t2!= nullptr){
        len2++;
        t2=t2->next;
    }
    int k=len2-len1;
    t1=s1->next;
    t2=s2->next;
    if(k>0){
        while(k){
            t2=t2->next;
            k--;
        }
    } else if(k<0){
        while (-k){
            t1=t1->next;
            k++;
        }
    }
    for(;t1!=t2;){
        t1=t1->next;
        t2=t2->next;
    }
    printf("%3d\t",t1->data);
    printf("%3d\n",t2->data);
}

int main(){
    Sqc s1,s2;
    init_list_chain_random(s1,20);
    sleep(1);
    init_list_chain_random(s2,25);
    Sqc t1=s1,t2=s2;
    for(int i=1;i<15;i++){
        t1=t1->next;
        t2=t2->next;
    }
    t2=t2->next->next->next;
    t1->next=t2->next;
    list_print_chain(s1);
    list_print_chain(s2);
    find_public(s1,s2);
}