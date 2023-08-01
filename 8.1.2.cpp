//
// Created by 28580 on 2023/8/1.
//SqList Homework
#include <cstdio>
#define MAX_LENGTH 50

typedef struct {
    int sec[MAX_LENGTH];
    int len;
}SqList;

void print_list(SqList s){
    for(int i=0;i<s.len;i++){
        printf("%3d",s.sec[i]);
    }
    printf("\n");
}

void init(SqList &s, int* p,int t){
    int i;
    for(i=0;i<t;p++){
        s.sec[i]=*p;
        i++;
    }
    s.len=i;
    //print_list(s);
}

bool insert(SqList &s,int n,int a){
    if(s.len==50||n<1||n>s.len+1){
        printf("false\n");
        return false;
    }
    else {
        for (int i=s.len;i>=n;i--) {
            s.sec[i]=s.sec[i-1];
        }
        s.sec[n-1]=a;
        s.len++;
        print_list(s);
        return true;
    }
}

int del(SqList &s,int n){
    if(n<1||n>s.len){
        printf("false\n");
        return 0;
    }
    else {
        int x = s.sec[n - 1];
        for (int i = s.len; n < i; n++) {
            s.sec[n - 1] = s.sec[n];
        }
        s.len--;
        print_list(s);
        return x;
    }
}

int SearchList(SqList s,int a){
    for(int i=0;i<s.len;i++){
        if(s.sec[i]==a){
            return i+1;
        }
    }
    return 0;
}

int main(){
    SqList L1;
    int a[3]={1,2,3};
    int n,i;
    scanf("%d %d",&n,&i);
    init(L1,a,3);
    insert(L1,n,i);
    scanf("%d",&n);
    del(L1,n);
}
