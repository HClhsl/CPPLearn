//
// Created by 28580 on 2023/8/31.
//
#include "SqList.h"

typedef struct Chain_List_Without_Head{
    elem_type data;
    Chain_List_Without_Head* next;
}cl,*pcl;

bool init_chain(pcl &s,int n){
    srand(time(nullptr));
    s=(pcl)malloc(sizeof (cl));
    s->data=number_generate()%10;
    pcl temp=s;
    for(int i=1;i<=n;i++){
        temp->next=(pcl)malloc(sizeof (cl));
        temp=temp->next;
        temp->data=number_generate()%10;
        temp->next= nullptr;
    }
    return true;
}

bool print_chain(pcl s){
    while(s->next!= nullptr){
        printf("%3d",s->data);
        s=s->next;
    }
    printf("\n");
    return true;
}
void del_chain_x(pcl &s,elem_type x){
    pcl t=s;
    if(s->next== nullptr)
        return;
    else {
        if (t->next->data != x)
            del_chain_x(t->next, x);
        else {
            if (t->next->next == nullptr) {
                free(t->next->next);
                t->next->next = nullptr;
            } else {
                pcl temp = t->next;
                t->next = temp->next;
                free(temp);
                del_chain_x(t->next, x);
            }
        }
    }
}

int main(){
    pcl s;
    init_chain(s,20);
    print_chain(s);
    del_chain_x(s,6);
    print_chain(s);
}