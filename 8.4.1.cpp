//
// Created by 28580 on 2023/8/4.
//
#include "cstdio"
#include "cstdlib"

typedef int element_type;

typedef struct LNode{
    element_type data;
    LNode* next;
}l_node,*p_node;

void node_print(p_node x){
    for(x=x->next;x!= nullptr;x=x->next){
        printf("%d ",x->data);
    }
    printf("\n");
}

void list_insert_tail(p_node &x){
    x=(p_node)malloc(sizeof (LNode));
    x->next= nullptr;
    p_node t=x;
    element_type a;
    scanf("%d",&a);
    for(;a!=9999;){
        t->next=(p_node)malloc(sizeof (LNode));
        t=t->next;
        t->data=a;
        t->next= nullptr;
        scanf("%d",&a);
    }
}

element_type list_search_location(p_node x,int locate){
    for(;locate!=0&&x!= nullptr;x=x->next){
        locate--;
    }
    if(locate==0)
        return x->data;
    else
        return 0;
}

void list_insert_location(p_node x,int locate,element_type a){
    if(locate<1)
        return;
    for(locate--;locate!=0&&x!= nullptr;x=x->next){
        locate--;
    }
    if(locate!=0){
        printf("location error");
        return;
    }
    p_node temp=(p_node ) malloc(sizeof (LNode));
    temp->next=x->next;
    x->next=temp;
    temp->data=a;
}

void list_delete_location(p_node x,int locate){
    if(locate<1)
        return;
    for(locate--;locate!=0&&x!= nullptr;x=x->next){
        locate--;
    }
    if(locate!=0){
        printf("location error");
        return;
    }
    p_node temp=x->next;
    x->next=temp->next;
    free(temp);
}

int main(){
    p_node l;
    list_insert_tail(l);
    node_print(l);
    element_type a= list_search_location(l,5);
    printf("%d\n",a);
    list_insert_location(l,13,99);
    node_print(l);
    list_delete_location(l,13);
    node_print(l);
}