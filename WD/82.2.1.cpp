//
// Created by 28580 on 2023/9/8.
//
#include "Queue.h"

int main(){
    rq q;
    srand(time(nullptr));
    for(int i=26;i>0;i--) {
        en_queue(q, number_generate());
    }
    for(int i=27;i>0;i--) {
        de_queue(q);
    }
}