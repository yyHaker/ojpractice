/**
 *   > File Name: mazeproblem1.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/2
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int maze[100][100];
int visited[100][100];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,1};
int N,M;
char s[100];
int time=0;  //计算时间
void dfs(int a,int b){
    if(a==N-1&&b==M-1){
        cout<<"the total time is:"<<time<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x>=0&&x<=N-1&&y>=0&&y<=M-1&&!visited[x][y]&&maze[x][y]!=-1){
            time+=1+maze[x][y];
            visited[x][y]=1;
            dfs(x,y);
            time-=1+maze[x][y];
            visited[x][y]=0;
        }
    }
}


int main(){
    while(scanf("%d %d",&N,&M)){
        memset(maze,-1,sizeof(maze));
        memset(visited,0,sizeof(visited));
         for(int i=0;i<N;i++){
             scanf("%s",s);
             for(int j=0;j<M;j++){
                 char ch=s[j];
                 switch (ch){
                     case '.': maze[i][j]=0;
                         break;
                     case 'X': maze[i][j]=-1;
                         break;
                     default: maze[i][j]=ch-'0';
                         break;
                 }
             }
         }
        //
        visited[0][0]=1;
        dfs(0,0);
    }
    return 0;
}
