//
// Created by 28580 on 2023/9/7.
//
#include "SqList.h"

#define max_size 100

typedef struct share_stake{
    elem_type data[max_size]={0};
    int stake_bottom=-1,stake_head=max_size;
}sh_stake;

void pop_stake_bottom(share_stake &s){
    if(s.stake_bottom==-1)
        return;
    printf("%3d",s.data[s.stake_bottom--]);
}

void pop_stake_head(share_stake &s){
    if(s.stake_head==max_size)
        return;
    printf("%3d",s.data[s.stake_head++]);
}

void push_stake_head(share_stake &s,elem_type data){
    if(s.stake_bottom+1==s.stake_head)
        return;
    s.data[--s.stake_head]=data;
}

void push_stake_bottom(share_stake &s,elem_type data){
    if(s.stake_bottom+1==s.stake_head)
        return;
    s.data[++s.stake_bottom]=data;
}

int main(){
    share_stake s;
    srand(time(nullptr));
    for(int i=0;i<60;i++){
        push_stake_bottom(s,number_generate());
    }
    for(int i=0;i<60;i++){
        push_stake_bottom(s,number_generate());
    }
    for(int i=0;i<60;i++){
        pop_stake_bottom(s);
    }
    for(int i=0;i<60;i++){
        pop_stake_head(s);
    }
}