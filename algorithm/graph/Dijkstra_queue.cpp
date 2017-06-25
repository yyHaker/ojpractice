/**
 *   > File Name: Dijkstra_queue.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/30
 *   (实现)  使用邻接表配合优先级队列实现dijkstra
 */
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 100
#define MAXM 100
#define INF 100000

int n,m; //n顶点个数，m表示边的个数
int first[MAXN];  //first[u]保存节点u的第一条边的边号
int u[MAXM],v[MAXM],w[MAXM];
int nnext[MAXM];  //next[e]表示编号为e的边的下一条边的编号
int d[MAXN];     //d[i]表示起点0到i的距离
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;  //二元组构成的优先级队列
bool done[MAXN];

void dijkstra(){
    memset(done,0,sizeof(done));
    for(int i=0;i<n;i++) d[i]= i==0? 0 : INF;
    q.push(make_pair(d[0],0));   //入队列
    while(!q.empty()){
        pii u =q.top();    q.pop();  //获得d值最小的u
        int x=u.second;
        if(done[x]) continue;       //已经算过扔掉
        done[x]=true;
        for(int e=first[x];e!=-1;e=nnext[e]){
            if(d[v[e]]>d[x]+w[e]){
                d[v[e]]=d[x]+w[e];   //松弛成功，更新d[v[e]]
                q.push(make_pair(d[v[e]],v[e]));   //加入优先队列
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
    dijkstra();
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
