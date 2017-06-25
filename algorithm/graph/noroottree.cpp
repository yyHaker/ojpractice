/**
 *   > File Name: noroottree.cpp 无根树转换为有根树
 *   > Author: yyHaker
 *   > Created Time: 2017/5/28
 */
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> G[100];  //vector是stl中的可变长数组
int p[100];
//将无根树转换为有根树
void dfs(int u,int fa){
    int d=G[u].size();
    for(int i=0;i<d;i++){
        int v=G[u][i];
        if(v!=fa) dfs(v,p[v]=u);
    }
}
int main(){
    int u,v,n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){    //输入n-1条边
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root=1;
    p[root]=-1;  //表示根节点的父节点不存在
    dfs(root,-1);
    return 0;
}
