/**
 *   > File Name: repairwall.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(int a,int b){
    return a>b;
}

int main(){
    int L,N;
    int A[610];
    while(scanf("%d%d",&L,&N)!=EOF){
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        sort(A,A+N,cmp);
        int sum=0;
        int k=0;
        int ok=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            k++;
            if(sum>=L){
                ok=1;
                break;
            }
        }
        if(ok) printf("%d\n",k);
        else printf("impossible\n");

    }
    return 0;
}
