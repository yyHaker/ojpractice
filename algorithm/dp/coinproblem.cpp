/**
 *   > File Name: coinproblem.cpp   硬币问题
 *   > Author: yyHaker
 *   > Created Time: 2017/5/23
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 10000

int n;  //硬币种数
int V[MAXN];  //面值
int d[MAXN];  //d[i] 表示从节点i出发到节点0的最长路径
int vis[MAXN];  //表示节点i是否计算过

//记忆化搜索最长路径
int dp_max(int S){
    int &ans=d[S];
    if(vis[S]) return d[S];
    vis[S]=1;
    ans=-1;
    for(int i=1;i<=n;i++){
        if(S>=V[i]) ans = max(ans,dp_max(S-V[i])+1);
    }
    return ans;
}

//输出字典序最小的方案
void print_ans(int *d,int S){
    for(int i=1;i<=n;i++){
        if(S>=V[i] && d[S]==d[S-V[i]]+1){
            cout<<V[i]<<" ";
            print_ans(d,S-V[i]);
            break;
        }
    }
}
int main(){
    int S;
    memset(vis,0,sizeof(vis));
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>V[i];
    }
    //置d[0]=0;即设置末节点
    d[0]=0;
    vis[0]=1;
    cout<<dp_max(S)<<endl;
    cout<<"输出方案:"<<endl;
    print_ans(d,S);
    system("pause");
    return 0;
}
