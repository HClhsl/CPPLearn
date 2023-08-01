//
// Created by 28580 on 2023/8/1.
//SqList Demo
#include <cstdio>
#define MAX_LENGTH 50
#define InitSize 100

typedef struct {
    char sec[MAX_LENGTH];
    int len;
}SqList;

void init(SqList* s, char* p){
    int i;
    for(i=0;(*p)!='\0';p++){
        s->sec[i]=*p;
        i++;
    }
    s->len=i;
}

void print_list(SqList* s){
    for(int i=0;i<s->len;i++){
        printf("%c",s->sec[i]);
    }
    printf("\n");
}

bool insert(SqList* s,int n,char a){
    if(s->len==50||n<1||n>s->len+1){
        printf("Error,no space left");
        return false;
    }
    else {
        for (int i=s->len;i>=n;i--) {
            s->sec[i]=s->sec[i-1];
        }
        s->sec[n-1]=a;
        s->len++;
        return true;
    }
}

char del(SqList* s,int n){
    if(n<1||n>s->len){
        printf("Error!\n");
        return 'E';
    }
    else {
        char x = s->sec[n - 1];
        for (int i = s->len; n < i; n++) {
            s->sec[n - 1] = s->sec[n];
        }
        s->len--;
        return x;
    }
}

int SearchList(SqList s,char a){
    for(int i=0;i<s.len;i++){
        if(s.sec[i]==a){
            return i+1;
        }
    }
    return 0;
}

int main(){
    SqList L1;
    char a[30]="Merry Christmas!";
    init(&L1,a);
    print_list(&L1);
    insert(&L1,5,'S');
    print_list(&L1);
    del(&L1,2);
    print_list(&L1);
    int ret=SearchList(L1,'!');
    printf("%d",ret);
}
