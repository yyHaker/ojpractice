/**
 *   > File Name: linkup.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/5
 */
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define MAX  1010

int chess[MAX][MAX];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int visit[MAX][MAX];
bool ok=false;
int change=3;
int direction=-1;

void  dfs(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        ok=true;
        return ;
    }
    if(ok) return;
    for(int i=0;i<4;i++){
        int nx=x1+dx[i];
        int ny=y1+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&(visit[nx][ny]==0)&&(chess[nx][ny]==0||(nx==x2&&ny==y2))){
            bool blus=false;
            int td;  //临时保存方向
            td=direction;
            if(i!=direction){
                change--;
                direction=i;
                blus=true;
            }
            if(change>=0){
                visit[nx][ny]=1;
                dfs(nx,ny,x2,y2);
            }
            visit[nx][ny]=0;   //回朔
            if(blus){
                change++;
                direction=td;
            }
        }
    }
}

bool check(int x1,int y1, int x2, int y2){
    if(chess[x1][y1]==0||chess[x2][y2]==0||chess[x1][y1]!=chess[x2][y2]) return false;
    dfs(x1,y1,x2,y2);
    return ok;
}

int main(){
    int q;
    while(scanf("%d%d",&n,&m)&&!(m==0&&n==0)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&chess[i][j]);
            }
        }
        scanf("%d",&q);
        int x1,y1,x2,y2;
        for(int i=0;i<q;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            memset(visit,0,sizeof(visit));
            visit[x1][y1]=1;
            change=3;
            direction=-1;
            ok= false;
            if(check(x1,y1,x2,y2)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
