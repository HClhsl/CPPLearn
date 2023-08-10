//
// Created by 28580 on 2023/8/6.
//
#include "cstdio"
#include "cstdlib"
using namespace std;
int MidSearch(int* A,int* B,int len){
    int SA=0,SB=0,EA=len-1,EB=len-1,MA,MB;
    while(SA!=EA||SB!=EB) {
        MA = (SA + EA) / 2;
        MB = (SB + EB) / 2;
        if (A[MA] < B[MB]) {
            if((SA+EA)%2==0) {
                SA = MA;
                EB = MB;
            } else{
                SA=MA+1;
                EB=MB;
            }
        } else if (A[MA] > B[MB]) {
            if((SA+EA)%2==0) {
                EA = MA;
                SB = MB;
            } else{
                EA=MA;
                SB=MB+1;
            }
        } else if(A[MA]==B[MB]){
            return A[MA];
        }
    }
    return A[SA]<B[SB]?A[SA]:B[SB];
}

int main(){
    int A[]={11,13,15,17,19};
    int B[]={2,4,6,8,20};
    int mid=MidSearch(A,B,5);
    printf("%d",mid);
}