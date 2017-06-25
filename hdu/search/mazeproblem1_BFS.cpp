/**
 *   > File Name: mazeproblem1_BFS.cpp   使用优先级队列实现的广度优先搜索
 *   > Author: yyHaker
 *   > Created Time: 2017/6/2
 */
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define mm(a,b) memset(a,b,sizeof(a))     //定义操作

struct node
{
    int x,y,step;
    friend bool operator<(node n1,node n2)    //优先级队列的排序准则
    {
        return n2.step<n1.step;
    }
};
int to[4][2]={0,1,0,-1,1,0,-1,0};
int map[111][111],cnt[111][111],flag[111][111];
int n,m;
int tim;
int bfs(){
    priority_queue<node> q;
    node a,t,p;
    a.x=0;
    a.y=0;
    a.step=0;
    map[0][0]=-1;
    q.push(a);
    while(!q.empty()){
        p=q.top(); q.pop();
        if(p.x==n-1&&p.y==m-1) return p.step;
        for(int i=0;i<4;i++){
            t.x=p.x+to[i][0];
            t.y=p.y+to[i][1];
            if(t.x>=0&&t.x<=n-1&&t.y>=0&&t.y<=m-1&&map[t.x][t.y]!=-1){
                t.step=p.step+map[t.x][t.y]+1;
                map[t.x][t.y]=-1;  //置该节点不能再被访问
                flag[t.x][t.y]=i+1;   //记录方向
                q.push(t);  //加入到优先级队列
            }
        }
    }
    return 0;
}
void printresult(int x,int y){
    if(!flag[x][y]) return;
    int n_x=x-to[flag[x][y]-1][0];
    int n_y=y-to[flag[x][y]-1][1];
    printresult(n_x,n_y);
    //printf("%ds: (%d, %d) -> (%d,%d)\n",tim++,n_x,n_y,x,y);
    printf("%ds:(%d,%d)->(%d,%d)\n", tim++, n_x, n_y, x, y);
    while(cnt[x][y]--){
        //printf("%ds : FIGHT AT (%d,%d)\n",tim++,x,y);
        printf("%ds:FIGHT AT (%d,%d)\n",tim++,x,y);
    }
}

int main(){
    while(cin>>n>>m){
        mm(map,-1);
        mm(cnt,0);
        mm(flag,0);
        char c[111];
        for(int i=0;i<n;i++){
            scanf("%s",c);
            for(int j=0;j<m;j++){
                if(c[j]=='.')map[i][j]=0;
                else if(c[j]=='X') map[i][j]=-1;
                else map[i][j]=cnt[i][j]=c[j]-'0';
            }
        }
        int ans=bfs();
        if(ans){
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            tim=1;
            printresult(n-1,m-1);
        }else{
            puts("God please help our poor hero.");
        }
        puts("FINISH");
    }
    return 0;
}