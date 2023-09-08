//
// Created by 28580 on 2023/9/8.
//
#include "Queue.h"
#include "Stack.h"

void queue_reverse_with_stack(rq &q,stack s){
    elem_type data= de_queue(q);
    while(data!=-1) {
        push(s, data);
        data= de_queue(q);
    }
    data=pop(s);
    while(data!=-1) {
        en_queue(q, data);
        data = pop(s);
    }
}

int main(){
    srand(time(nullptr));
    rq q;
    stack s;
    for(int i=0;i<20;i++){
        en_queue(q,number_generate());
    }
    print_queue(q);
    queue_reverse_with_stack(q,s);
    print_queue(q);
}