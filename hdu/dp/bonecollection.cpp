/**
 *   > File Name: bonecollection.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/28
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1010

int main(){
    int T,N,V;
    int value[MAXN];
    int volume[MAXN];
    int dp[MAXN];  //dp[j]表示容量为j的背包中最多所能容纳的价值
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&V);
        for(int i=1;i<=N;i++){
            scanf("%d",&value[i]);
        }
        for(int j=1;j<=N;j++){
            scanf("%d",&volume[j]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            for(int j=V;j>=volume[i];j--){
                dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
            }
        }
        printf("%d\n",dp[V]);
    }
}
