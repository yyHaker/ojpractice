/**
 *   > File Name: fact.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/14
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//素数判定。注意n不能太大
int is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    int prime[100],count=0;
    int n,p[100]; //n和各个素数的指数
    //构造素数表
    for(int i=2;i<=100;i++){
        if(is_prime(i)) prime[count++]=i;
    }
    while(scanf("%d",&n)==1){
        printf("%d =",n);
        memset(p,0,sizeof(p));     //初始化各个指数为0
        int maxp=0;                     //最大因子的下标
        for(int i=1;i<=n;i++){
            int m=i;
            for(int j=0;j<count&&m>=prime[j];j++){  //反复除以primr[j]，并累加p[j]
                while(m%prime[j]==0){
                    m/=prime[j];
                    p[j]++;
                    if(j>maxp) maxp=j; //更新最大因子的下标
                }
            }
        }
        //只循环到最大下标
        for(int i=0;i<=maxp;i++){
            printf(" %d",p[i]);
        }
        printf("\n");
    }
return 0;
}
