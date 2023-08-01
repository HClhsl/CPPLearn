#include <stdio.h>

void modify_pointer(int* &p,int *q){
    p=q;
}

int main(){
//    int *p=NULL;
//    int i=10;
//    int *q=&i;
//    modify_pointer(p,q);
//    printf("%d",*p);
    bool a= true;
    bool b= false;
    printf("a=%d\nb=%d",a,b);
}
