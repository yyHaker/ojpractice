/**
 *   > File Name: superjumping.cpp 求解最大递增字段的和
 *   > Author: yyHaker
 *   > Created Time: 2017/5/28
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

int main(){
    int N,value[MAXN];
    int dp[MAXN];  //dp[i]表示以a[i]结尾的最大递增子段的和
    while(cin>>N,N){
        for(int i=1;i<=N;i++){
            scanf("%d",&value[i]);
            dp[i]=value[i];
        }
        for(int i=1;i<=N;i++){           //dp[i]=max{max{dp[j]+value[i]}, value[i]} 其中1=<j<i&&value[j]<value[i]
            int ans=0;
            for(int j=1;j<i;j++){
                if(value[i]>value[j]){
                    ans=max(ans,dp[j]+value[i]);
                }
                dp[i]=max(ans,value[i]);
            }
        }
        int max=0;
        for(int i=1;i<=N;i++){
            if(dp[i]>max)
                max=dp[i];
        }
        printf("%d\n",max);
    }
    return 0;
}
