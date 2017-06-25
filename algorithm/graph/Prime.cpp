/**
 *   > File Name: Prime.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/29
 *   Prime:设图G的顶点结合为U，首先选择一个起始点加入到MST，再从集合U-MST中找到另一个点到MST中任意一点的权值最小，直到所有的点加入到MST
 *   实现：维护两个数组 lowcost[i]表示以i为终点的边的最小权值(lowcost[i]=0表示i加入到了MST)； mst[i]表示对应的lowcost[i]对应的起点
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXN 100
#define MAXCOST 1000000

int graph[MAXN][MAXN];  //使用二维数组存储无向带权图
int prime(int graph[][MAXN],int n){        //n表示n个顶点
    int lowcost[MAXN];  //lowcost[i]表示以i为终点的边的最小权值，lowcost[i]=0表示i点加入到了MST
    int mst[MAXN];       //mst[i]表示对应的lowcost[i]的起点，即说明边<mst[i],i>是MST的一条边，档mst[i]=0表示起点i加入MST
    for(int i=2;i<=n;i++){      //默认第一个点为起点，初始化
        lowcost[i]=graph[1][i];
        mst[i]=1;
    }
    int min,minid,sum=0;
    mst[1]=0; //将第一个节点加入到MST
    for(int i=2;i<=n;i++){
        min=MAXCOST;
        minid=0;
        for(int j=2;j<=n;j++){   //找到与到当前MST任意一点的权值最小的那个顶点
            if(lowcost[j]<min&&lowcost[j]!=0){
                min=lowcost[j];
                minid=j;
            }
        }
        cout<<"V"<<mst[minid]<<"-V"<<minid<<"="<<min<<endl;
        sum+=min;
        lowcost[minid]=0;    //将顶点加入到MST
        for(int j=2;j<=n;j++){   //更新lowcost和mst
            if(graph[minid][j]<lowcost[j]){
                lowcost[j]=graph[minid][j];
                mst[j]=minid;
            }
        }
    }
return sum;
}

int main(){
    int m,n;   //m顶点个数，n边的个数
    int u,v,cost;  //每条边对应的顶点和权值
    cout<<"please input the vnum and snum:"<<endl;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            graph[i][j]=MAXCOST;
        }
    }
    //构建图
    cout<<"please input the node and weight:"<<endl;
    for(int k=1;k<=n;k++){
        cin>>u>>v>>cost;
        graph[u][v]=cost;
        graph[v][u]=cost;
    }
    //求解最小生成树
    cost=prime(graph,m);
    cout<<"the lowest cost is "<<cost<<endl;
    system("pause");
    return 0;
}
