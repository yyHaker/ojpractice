/**
 *   > File Name: blackwhite.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include<iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MaxN 100
int mat[MaxN][MaxN],vis[MaxN][MaxN];

void dfs(int x,int y){
    if(!mat[x][y]||vis[x][y]) return;  //白格子或者已经被访问，直接返回
    vis[x][y]=1; //标记被访问
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);

    dfs(x-1,y+1);
    dfs(x+1,y+1);
    dfs(x-1,y-1);
    dfs(x+1,y-1);
}
int main(){
    int n;
    char s[MaxN];
    cin>>n;
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;j<n;j++){
            mat[i+1][j+1]=s[j]-'0';   //把整个图像往中间挪一点，以便dfs无需判断越界
        }
    }
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]&&mat[i][j]){
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}
