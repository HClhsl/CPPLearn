//
// Created by 28580 on 2023/8/2.
//
/*设线性表L=a1 a2 a3... 采用带头结点的单链表保存，链表中
的结点定义如下：
typedef struct node {
int data;
struct node* next;
} NODE；
请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L 中的各结点，
得到线性表L'=a1 an a2 an-1...。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C 或C++语言描述算法，关键之处给出注释。
（3）说明你所设计的算法的时间复杂度。*/

#include <cstdlib>
#include <cstdio>

typedef struct node{
    int data;
    struct node* next;
}NODE,*LNode;

void list_init(LNode &x,int a){
    x=(LNode) malloc(sizeof (NODE));
    x->next= (LNode)malloc(sizeof (NODE));
    LNode l=x->next;
    l->next= nullptr;
    l->data=a;
}

void head_insert(LNode x,int a){
    LNode l=(LNode) malloc(sizeof (NODE));
    l->next=x->next;
    x->next=l;
    l->data=a;
}

void list_print(LNode x){
    x=x->next;
    while (x!= nullptr){
        printf("%d\t",x->data);
        x=x->next;
    }
    printf("\n");
}

LNode split_list(LNode x){
    int n=0;
    LNode l=x;
    while(l!= nullptr){
        l=l->next;
        n++;
    }
    l=x;
    for(int i=0;i<n/2;i++) {
        l = l->next;
        x=l;
    }
    l = l->next;
    x->next= nullptr;
    return l;
}

void list_inverse(LNode &x){
    LNode head,beg,end;
    head=x;
    beg=x->next;
    end=beg->next;
    for(;beg->next!= nullptr;){
        beg->next=end->next;
        end->next=head->next;
        head->next=end;
        end=beg->next;
    }
}

LNode GetEle(LNode x,int locate){
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

void list_plus(LNode x,LNode p){
    LNode temp,temp2;
    temp2=p;
    LNode A,B;
    for(int n=1; p->next!= nullptr;n++){
        A=GetEle(x,2*n-1);
        B=GetEle(p,1);
        p->next=B->next;
        B->next=A->next;
        A->next=B;

    }
    A->next->next= nullptr;

}

int main(){
    LNode p;
    list_init(p,1);
    int x[20];
    x[0]=1;
    x[1]=1;
    for(int i=2;i<20;i++){
        x[i]=x[i-1]+x[i-2];
        head_insert(p,x[i]);
    }
    //list_print(p);
    LNode q;
    q=(LNode) malloc(sizeof (NODE));
    q->next=split_list(p);
    list_print(p);
    list_print(q);
    list_inverse(q);
    list_print(q);
    list_plus(p,q);
    list_print(p);
}