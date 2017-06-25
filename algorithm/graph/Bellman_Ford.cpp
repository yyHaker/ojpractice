/**
 *   > File Name: Bellman_Ford.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/30
 *   最坏的时间复杂度O(nm)
 */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 100
#define MAXM 100
#define INF 100000

int n,m;
int d[MAXN];
int u[MAXM],v[MAXM],w[MAXM];

void bellman_ford(){
    for(int i=0;i<n;i++) d[i]= i==0? 0 : INF;
    for(int k=0;k<n-1;k++){   //迭代n-1次
        for(int i=0;i<m;i++){    //检查每条边
            int x=u[i],y=v[i];
            if(d[x]<INF){
                d[y]=min(d[y],d[x]+w[i]);
            }
        }
    }
}

queue<int> q;
bool inq[MAXN];
int first[MAXN];
int nnext[MAXM];

void bellman_ford_queue(){
    for(int i=0;i<n;i++) d[i]= i==0? 0 : INF;
    memset(inq,0,sizeof(inq));   //”在队列中“ 标志
    q.push(0);
    while(!q.empty()){
        int x=q.front(); q.pop;
        inq[x]= false;  //清除“在队列中”标志
        for(int e=first[x];e!=-1;e=nnext[e]){
            if(d[v[e]]>d[x]+w[e]){
                d[v[e]]=d[x]+w[e];
                if(!inq[v[e]]){    //如果已经在队列中了就无需重复添加
                    inq[v[e]]=true;
                    q.push(v[e]);
                }
            }
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) first[i]=-1; //初始化表头
    for(int e=0;e<m;e++){
        cin>>u[e]>>v[e]>>w[e];
        nnext[e]=first[u[e]];
        first[u[e]]=e;
    }

}
