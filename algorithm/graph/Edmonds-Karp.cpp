/**
 *   > File Name: Edmonds-Karp.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/31
 *   增广算法：残差网络中任何一条从s到t的有向道路都对应一条原图中的增广路，只要求出该
 *   道路中所有残差量的最小值d，把对应的所有边上的流量增加d即可，这个过程称为增广。
 *   只要残量网络中存在增广路，流量就可以增大。如果残量网络中不存在增广路，则当前流就是最大流。
 */
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 50
#define INF 10000

int n; //定点个数
int cap[MAXN][MAXN];  //容量
int flow[MAXN][MAXN]; //流量
int s,t,f;    //s源点     t汇点     f：s-t的净流量
int a[MAXN];  //s到节点i的路径上的最小残量
int p[MAXN];   //p[v] 记录v的父亲节点
queue<int> q;

void edmonds_karp(){
    memset(flow,0,sizeof(flow));
    f=0;
    for( ; ; ){
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty()){    //BFS找增广路
            int u=q.front(); q.pop();
            for(int v=1;v<=n;v++){
                if(!a[v] && cap[u][v]>flow[u][v]){     //找到新节点v
                    p[v]=u; q.push(v);    //记录v的父亲节点，并将v加入队列
                    a[v]=min(a[v],cap[u][v]-flow[u][v]);   //s-v路径上的最小残量
                }
            }
        }
        if(a[t]==0) break;   //找不到，则当前流已经是最大流
        for(int u=t;u!=s;u=p[u]){   //从汇点往回走
            flow[p[u]][u]+=a[t];  //更新正向流量
            flow[u][p[u]]-=a[t];  //更新反向流量
        }
        f+=a[t];  //更新从s流出的总流量
    }
}


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

    }
    system("pause");
    return 0;
}
