//
// Created by 28580 on 2023/9/8.
//
#include "Queue.h"

int main(){
    qc q;
    init_queue_chain(q,3);
    print_queue_chain(q);
    en_queue_chain(q,-3);
    print_queue_chain(q);
    de_queue_chain(q);
    de_queue_chain(q);
    de_queue_chain(q);
    de_queue_chain(q);
    de_queue_chain(q);
}