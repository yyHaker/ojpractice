/**
 *   > File Name: Floyd.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/30
 *
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 100
#define INF 1000001  //1000*1000+1

int n,m;
int d[MAXN][MAXN];

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int u,v,e;
    //初始化d
    memset(d,INF,sizeof(d));
    for(int i=0;i<n;i++) d[i][i]=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>e;
        d[u][v]=e;
        //d[v][u]=e;  //有向图初始化一边
    }
    floyd();
    system("pause");
    return 0;
}
