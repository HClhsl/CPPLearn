//
// Created by 28580 on 2023/9/6.
//
#include "SqList.h"


//From ChatGpt:在您提供的代码中，我发现了一个潜在的问题，这个问题可能导致循环链表的删除操作不正确。问题出现在 del_node 函数中，具体来说，在删除第一个节点时，您在释放节点之前修改了 pre 指针。这可能导致后续的循环链表操作出现问题。为了解决这个问题，您可以稍微修改 del_node 函数
void del_node(Sqc &s,Sqc &pre){
    if (s == pre) {
        Sqc temp = s->next;
        pre = temp->next;
        while (pre->next != s->next) {
            pre = pre->next;
        }
        pre->next = temp->next;
        s->next = pre->next; // 更新头节点的 next 指针
        free(temp);
    }else {
        Sqc temp = pre->next;
        pre->next = temp->next;
        free(temp);
    }
}

//当删除第一个节点时，由于循环链表的缘故，第一个结点拥有两个前驱，因此需要特殊处理
void print_with_del(Sqc s){
    elem_type min=s->next->data;
    Sqc temp=s->next->next,pre=s->next,pre_min=s;
    while(s->next->next!= s->next) {
        for (; temp != s->next; temp = temp->next) {
            if (min >= temp->data) {
                min = temp->data;
                pre_min = pre;
            }
            pre = temp;
        }
        printf("%3d", pre_min->next->data);
        del_node(s,pre_min);
        temp=s->next->next;
        min=s->next->data;
        pre=s->next;
        pre_min=s;
    }
    printf("%3d",s->next->data);
    free(s->next);
    free(s);
}

int main(){
    Sqc s1;
    init_list_random_recycle(s1,10);
    list_print_recycle(s1);
    print_with_del(s1);
}