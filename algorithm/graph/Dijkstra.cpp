/**
 *   > File Name: Dijkstra.cpp       单元最短路径问题的Dijkstra算法(适用于有向图无向图且边的权值为正的情况)
 *   > Author: yyHaker
 *   > Created Time: 2017/5/30
 *   时间复杂度O(n^2)
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 100
#define INF 10000

int n;    //顶点个数
int w[MAXN][MAXN];  //带权邻接矩阵
int v[MAXN];         //标记节点
int d[MAXN];        //d[i]记录起点到i的距离长度，假设起点为0

int fa[MAXN];       //记录最短路径

void  dijksra(){
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++) d[i] = i == 0 ? 0 : INF;
    for(int i=0;i<n;i++){
        int x,min=INF;
        for(int y=0;y<n;y++){
            if(!v[y]&&d[y]<min){
                min=d[y];
                x=y;  //记录最小的d[]值的节点
            }
        }
        v[x]=1;
        for(int y=0;y<n;y++){
            //d[y]=min(d[y],d[x]+w[x][y]);
            if(d[y]>d[x]+w[x][y]){
                d[y]=d[x]+w[x][y];
                fa[y]=x;
            }
        }
    }
}

void print_path(int i){
    if(i!=0){
        print_path(fa[i]);
    }
    cout<<i<<" ";
}

int main(){
    cout<<"please input the node num:"<<endl;
    cin>>n;
    memset(w,INF,sizeof(w));    //w[i][j]=INF表示边ij不存在
    cout<<"please input the side num:"<<endl;
    int m,u,v,weight;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>weight;
        w[u][v]=weight;
        //w[v][u]=weight;   //(有向图只赋值一边)
    }
    //0表示起点，求得单元最短路径为
    memset(fa,0,sizeof(fa));  //fa[0]=0;
    dijksra();
    cout<<"the shortest path to every node is:"<<endl;
    for(int i=0;i<n;i++){
        print_path(i);
        cout<<" totallength is:"<<d[i]<<endl;
    }
    system("pause");
    return 0;
}
