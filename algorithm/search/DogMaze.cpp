/**
 *   > File Name: DogMaze.cpp    深度优先搜索加回朔加奇数偶数剪枝
 *   > Author: yyHaker
 *   > Created Time: 2017/6/1
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int N,M,T;
char ch[10];
int maze[10][10];
int sx=0,sy=0,ex=0,ey=0;  //起点和终点
int ok=false;
int da[4]={1,0,-1,0};
int db[4]={0,1,0,-1};
bool visit[10][10];
int count_=0;

void  dfs(int a,int b){
    if(count_==T&&maze[a][b]==2){
        ok=true;
        return;
    }
    if(count_>T||ok) return;
    if((T-count_-abs(a-ex)-abs(b-ey))%2==1) return;   //奇数偶数剪枝
    for(int i=0;i<4;i++){
        int x=a+da[i];
        int y=b+db[i];
        if(maze[x][y]!=-1&&visit[x][y]==0){
            visit[x][y]=1;
            count_++;
            dfs(x,y);
            visit[x][y]=0;
            count_--;
            if(ok) return;
        }
    }
}
int main(){
    while(cin>>N>>M>>T){
        if(N==0&&M==0&&T==0) break;
        memset(maze,-1,sizeof(maze));
        memset(visit,0,sizeof(visit));
        int w=0;//统计墙的个数
        for(int i=1;i<=N;i++){
            scanf("%s",ch);
            for(int j=1;j<=M;j++){
                switch (ch[j-1]){
                    case 'S': maze[i][j]=1;sx=i,sy=j; break;
                    case '.': maze[i][j]=0;break;
                    case 'D': maze[i][j]=2;ex=i,ey=j;break;
                    case 'X':maze[i][j]=-1;w++;break;
                    default: maze[i][j]=-1; break;
                }
            }
        }
        ok= false;
        //可走方块是否比时间多，最短时间是否比t小,奇偶剪枝
        if(N*M-w<T&&abs(sx-ex)+abs(sy-ey)>T||(T-abs(sx-ex)-abs(sy-ey))%2==1){
            printf("NO\n");
            continue;
        }
        //dfs
        count_=0;
        visit[sx][sy]=1;
        dfs(sx,sy);
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
