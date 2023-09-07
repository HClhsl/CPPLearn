//
// Created by 28580 on 2023/9/4.
//
#include <unistd.h>
#include "SqList.h"
#include "iostream"
using namespace std;

bool if_subsequence(Sqc a,Sqc b){
    a=a->next;
    b=b->next;
    Sqc x=b;
    for(;a!= nullptr;){
        if(a->data!=b->data){
            a=a->next;
        } else{
            Sqc t=a;
            for(;b!= nullptr&&a!= nullptr&&a->data==b->data;){
                a=a->next;
                b=b->next;
            }
            if(b== nullptr){
                return true;
            }
            else{
                a=t->next;
                b=x;
            }

        }
    }
    return false;
}

int main(){
    Sqc a,b;
    init_list_chain_random(a,20);
    sleep(1);
    init_list_chain_random(b,3);
    bool x= if_subsequence(a,b);
    cout<<x;
}