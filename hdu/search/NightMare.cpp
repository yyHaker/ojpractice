/**
 *   > File Name: NightMare.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/4
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
    int x,y,time,bomb;
    friend bool operator<(node n1,node n2){
        return n2.time<n1.time;
    }
};
int T,N,M;
int maze[10][10];
int visit[10][10];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

int bfs(int a,int b){
    priority_queue<node> q;
    node s,t,nn;
    s.x=a,s.y=b,s.time=0,s.bomb=6;  //初始化起点
    q.push(s);
    int maxbomb=0;
    while(!q.empty()){
        t=q.top(); q.pop();
        if(maze[t.x][t.y]==3&&t.bomb>0) return t.time;
        for(int i=0;i<4;i++){
            nn.x=t.x+dx[i];
            nn.y=t.y+dy[i];
            nn.time=t.time+1;
            nn.bomb=t.bomb-1;
            if(nn.x>=0&&nn.x<=N-1&&nn.y>=0&&nn.y<=M-1&&maze[nn.x][nn.y]!=0&&!visit[nn.x][nn.y]&&nn.bomb>0){
                if(maze[nn.x][nn.y]==4){
                    nn.bomb=6;  //重置炸弹
                    visit[nn.x][nn.y]=1;
                }
                q.push(nn);
                if(nn.bomb>maxbomb) maxbomb=nn.bomb;
            }
        }
        if(maxbomb<0) return 0;
    }
    return 0;
}
int main(){
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&maze[i][j]);
                if(maze[i][j]==2){
                    a=i;
                    b=j;
                }
            }
        }
        memset(visit,0,sizeof(visit));
        int ans=bfs(a,b);
        if(ans) printf("%d\n",ans);
        else printf("-1\n");
    }
}
