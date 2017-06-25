/**
 *   > File Name: robberies.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/25
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 110


int main(){
    int T;
    double prob;
    int N;
    int M[MAXN];
    double P[MAXN];
    double dp[10010];
    int sum;
    cin>>T;
    while(T--){
        scanf("%lf %d",&prob,&N);
        prob=1-prob;  //不被抓的概率
        sum=0;
        for(int i=1;i<=N;i++){
            scanf("%d %lf",&M[i],&P[i]);
            sum+=M[i];  //计算可能的最大抢到的钱
            P[i]=1-P[i];  //P记录不被抓的概率
        }
        //dp求解，dp[i]存储 抢到钱为i不被抓的概率，依次遍历每一个银行(抢或者不抢)，dp使该值最大
        memset(dp,0,sizeof(dp));
        dp[0]=1;    //没有抢到钱，不被抓的概率为1

        for(int j=1;j<=N;j++){
            for(int i=sum;i>=M[j];i--){
                dp[i]=max(dp[i],dp[i-M[j]]*P[j]);  //不抢银行j不被抓的概率   抢银行j不被抓的概率
            }
        }
        for(int i=sum;i>=0;i--){
            if(dp[i]>=prob){
                cout<<i<<endl;
                break;
            }
        }

    }
    return 0;
}



