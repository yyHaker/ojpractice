/**
 *   > File Name: maxsequece.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/26
 */
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 10000
int main(){
    int K;
    int a[MAXN+1];
    while(scanf("%d",&K)!=EOF&&K!=0){
        for(int i=1;i<=K;i++){
            scanf("%d",&a[i]);
        }

        int max=0,tmax=0;
        int s=0,e=0,ts=0,te=0;
        int flag=1;
        for(int i=1;i<=K;i++){
            if(a[i]>=0) flag=0;
        }
        if(flag){
            printf("%d %d %d\n",0,a[1],a[K]);
        }else{
            for(int i=1;i<=K;i++){
                if(tmax<=0){
                    tmax=a[i];
                    ts=i;
                    if(K==1) te=i;
                }else{
                    tmax+=a[i];
                    te=i;
                }
                if(tmax>max){  //更新最大值
                    max=tmax;
                    s=ts;
                    e=te;
                }
            }
            printf("%d %d %d\n",max,a[s],a[e]);
        }

    }
}
