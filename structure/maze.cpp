/**
 *   > File Name: maze.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 30

int maze[MAXN][MAXN],q[MAXN*MAXN],vis[MAXN][MAXN],fa[MAXN][MAXN],dist[MAXN][MAXN],last_dir[MAXN][MAXN];  //maze表示迷宫，q队列，vis标记迷宫中的点是否被访问，fa父节点数组，dist表示到起点的距离
int m,n;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs(int x, int y){             //从迷宫某一坐标处开始广度优先搜索
    int front=0,rear=0;
    int u=x*m+y;
    vis[x][y]=1;
    fa[x][y]=u;
    dist[x][y]=0;

    q[rear++]=u;
    while(front<rear){
        u=q[front++];
        x=u/m;
        y=u%m;
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&maze[nx][ny]&&!vis[nx][ny]){
                int v=nx*m+ny;
                q[rear++]=v;
                vis[nx][ny]=1;

                fa[nx][ny]=u;                    //保存父节点编号
                dist[nx][ny]=dist[x][y]+1;  //计算到起点的的距离
                last_dir[nx][ny]=d;   //保存方向
            }
        }
    }
}

void print_path(int x,int y) {
    int fx=fa[x][y]/m;
    int fy=fa[x][y]%m;
    if(fx!=x||fy!=y){
        print_path(fx,fy);
        cout<<fa[x][y]<<" ";
    }
}
int main(){
     //输入迷宫
    scanf("%d%d",&m,&n);
    char s[n];
    for(int x=0;x<m;x++){
        scanf("%s",s);
        for(int y=0;y<n;y++){
            maze[x][y]=s[y]-'0';
        }
    }
    //广搜
    bfs(0,0);
    print_path(0,4);
    cout<<endl;

    cout<<dist[0][4]<<endl;
    system("pause");
    return 0;

}
