/**
 *   > File Name: runproblem_queue.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/10
 *
 *   不使用优先级队列就ac了
 */
#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int K,A,B,C,T;
int maze[55][55][55];
int vis[55][55][55];   //保存是否被访问状态以及到达改点的时间
int d[6][3]={1,0,0,
             -1,0,0,
             0,1,0,
             0,-1,0,
             0,0,1,
             0,0,-1};
struct node{
    int a,b,c;
    int time;
    friend bool operator<(node n1,node n2){  //优先级队列的排序准则
        return n2.time<n1.time;
    }
};
//起点(0,0,0)->(A-1,B-1,C-1)
int bfs(){
   queue<node> q;
    node s;
    s.a=0,s.b=0,s.c=0,s.time=0;
    vis[s.a][s.b][s.c]=1;
    q.push(s);
    while(!q.empty()){
        node t=q.front(); q.pop();
        if(t.a==A-1&&t.b==B-1&&t.c==C-1){
            return t.time;
        }
        //if(t.time>T) return 0;
        node nn;
        for(int i=0;i<6;i++){
            nn.a=t.a+d[i][0];
            nn.b=t.b+d[i][1];
            nn.c=t.c+d[i][2];
            nn.time=t.time+1;
            if(nn.a>=0&&nn.a<A&&nn.b>=0&&nn.b<B&&nn.c>=0&&nn.c<C&&maze[nn.a][nn.b][nn.c]==0&&nn.time<=T){
                if(!vis[nn.a][nn.b][nn.c]||(vis[nn.a][nn.b][nn.c]&&vis[nn.a][nn.b][nn.c]>nn.time)){   //访问了的点可以被访问，但是必须时间比以前短
                    q.push(nn);
                    vis[nn.a][nn.b][nn.c]=nn.time;  //记录时间
                }
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d",&K);
    while(K--){
        scanf("%d%d%d%d",&A,&B,&C,&T);
        for(int a=0;a<A;a++){
            for(int b=0;b<B;b++){
                for(int c=0;c<C;c++){
                    scanf("%d",&maze[a][b][c]);
                }
            }
        }
        //bfs
        memset(vis,0,sizeof(vis));
        int ans=bfs();
        //printf("%d\n",ans);
        if(ans==0||ans>T) printf("-1\n");
        else printf("%d\n",ans);
    }
}

