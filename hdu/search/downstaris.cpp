/**
 *   > File Name: downstaris.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/8
 */
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    int x;
    int y;
    int time;
    friend bool operator<(node n1,node n2){   //优先级队列的排列准则
        return n2.time<n1.time;
    }
};
char maze[30][30];
bool visited[30][30];
int M,N;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};   //i=1,4 左右    i=2,3 上下
int  stairs[30][2]; //记录楼梯坐标
int stairsnum=0;
void change(){
    for(int i=0;i<stairsnum;i++){
        if(maze[stairs[i][0]][stairs[i][1]]=='|') maze[stairs[i][0]][stairs[i][1]]='-';
        if(maze[stairs[i][0]][stairs[i][1]]=='-') maze[stairs[i][0]][stairs[i][1]]='|';
    }
}

int bfs(int a,int b){
    priority_queue<node> q;
    node s,t;
    s.x=a;
    s.y=b;
    s.time=0;
    q.push(s);
    visited[s.x][s.y]=1;
    while(!q.empty()){
        t=q.top(); q.pop();
        if(maze[t.x][t.y]=='T')  return t.time;
        for(int i=0;i<4;i++){
            int nx=t.x+dx[i];
            int ny=t.y+dy[i];
            int ntime=t.time+1;
            if(nx>=0&&nx<M&&ny>=0&&ny<N&&maze[nx][ny]!='*'&&!visited[nx][ny]){
                if(maze[nx][ny]=='-'&&(i==1||i==4)){
                    ny+=dy[i];
                    if(ny<0||ny>=N||maze[nx][ny]=='*'||visited[nx][ny]==1) continue;
                }
                if(maze[nx][ny]=='|'&&(i==2||i==3)){
                    nx+=dx[i];
                    if(nx<0||nx>=M||maze[nx][ny]=='*'||visited[nx][ny]==1) continue;
                }
                if((maze[nx][ny]=='|'&&(i==2||i==3))||(maze[nx][ny]=='-'&&(i==1||i==4))) continue;
                node newnode;
                newnode.x=nx;
                newnode.y=ny;
                newnode.time=ntime;
                q.push(newnode);
                visited[nx][ny]=1;
                change();  //更换梯子方向
            }
        }
    }
    return 0;
}


int main(){
    int a,b;
    char s[30];
    while(scanf("%d%d",&M,&N)){
        memset(visited,0,sizeof(visited));
        stairsnum=0;
        for(int i=0;i<M;i++){
            scanf("%s",s);
            for(int j=0;j<N;j++){
                maze[i][j]=s[j];
                if(maze[i][j]=='S'){ //记录起点
                    a=i;
                    b=j;
                }
                if(maze[i][j]=='|'||maze[i][j]=='-'){
                    stairs[stairsnum][0]=i;
                    stairs[stairsnum][1]=j;
                    stairsnum++;
                }
            }
        }
        int ans=bfs(a,b);
        if(ans) printf("%d\n",ans);

    }
}

