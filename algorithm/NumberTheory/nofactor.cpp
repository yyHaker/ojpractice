/**
 *   > File Name: nofactor.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/3
 */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
#define MAXN 1000
//筛选法构造1-n的素数表
//对于不超过n的每个非负整数p删除2p、3p、4p.....，当处理完所有的数之后，还没有被删除的数就是素数。
int vis[MAXN];       //素数表
int prime[MAXN];  //素数保存表
void caclprimetable(int n){
    int m=sqrt(n+0.5);
    int c=0;  //统计素数个数
    memset(vis,0,sizeof(vis));
    vis[1]=1;  //1不是素数
    for(int i=2;i<=m;i++){
        if(vis[i]==0){
            prime[c++]=i;
          for(int j=i*i;j<=n;j+=i) vis[j]=1;
        }
    }
}
//求解[n,m]内的所有无平方因子的数
//对于不超过sqrt(m)内的所有素数p，筛选掉[n,m]内p^2的所有倍数
int main(){
    int n,m;
    int count=0;//统计无平方因子的个数
    bool isnofactor[MAXN];
    //构造素数表
    caclprimetable(100);
    while(cin>>n>>m){
        count=m-n+1;
        memset(isnofactor,0,sizeof(isnofactor));   //0表示是无平方因子
        for(int i=2;i<=(int)sqrt(m);i++){
            if(vis[i]==0){
                for(int j=i*i,a=1;j<=m;a++,j=a*i*i){
                    if(j>=n){
                        isnofactor[j]=1;
                        count--;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
