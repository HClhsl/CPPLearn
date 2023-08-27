//
// Created by 28580 on 2023/8/9.
//
#include "cstdio"
#include "cstdlib"
#include <ctime>

typedef int element_type;

element_type random_num(){
    return rand()%100;
}

typedef struct {
    element_type *data;
    int len;
}STable,*pst;

void STable_init(pst x,int len){
    x->len=len;
    x->data=(element_type*) malloc(sizeof (element_type)*len);
    for(int i=0;i<len;i++){
        x->data[i]=random_num();
    }
}

void STable_print(pst x){
    for(int i=0;i<x->len;i++){
        printf("%d ",x->data[i]);
    }
}

void exchange(element_type &a,element_type &b){
    element_type x;
    x=a;
    a=b;
    b=x;
}

/*int partition(pst x, int low, int high){
    element_type* ar=x->data;
    int key=ar[low];
    while(low<high){
        while(low<high&&ar[high]>=key){
            --high;
        }
        ar[low]=ar[high];
        while(low<high&&ar[low]<=key){
            ++low;
        }
        ar[high]=ar[low];
    }
    ar[low]=key;
    return low;
}*/

int partition(element_type *x,int low, int high){
    element_type key=x[low];
    while(high>low){
        while(high>low&&x[high]>=key){
            high--;
        }
        x[low]=x[high];
        while(high>low&&x[low]<=key){
            low++;
        }
        x[high]=x[low];
    }
    x[low]=key;
    return low;
}

void STable_quick_sort(element_type *x, int low, int high) {
    if (low < high) {
        int p = partition(x, low, high);  // Corrected the arguments here
        STable_quick_sort(x, low, p - 1);  // Recursively sort the left side
        STable_quick_sort(x, p + 1, high);  // Recursively sort the right side
    }
}

int main(){
    STable t1;
    srand(time(nullptr));
    STable_init(&t1,30);
    STable_print(&t1);
    printf("\n");
    STable_quick_sort(t1.data,0,29);
    STable_print(&t1);
    printf("\n");
}
