/**
 *   > File Name: FilthRich.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 */
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int r,c;
int a[1001][1001];
int d[3][2]={1,0,0,1,1,1};
struct node{
    int x;
    int y;
    int w;
};
int maxw=0;
void bfs(){
    queue<node> q;
    node s;
    s.x=0;
    s.y=0;
    s.w=a[0][0];
    q.push(s);
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(t.x==r-1&&t.y==c-1){
            if(t.w>maxw) maxw=t.w;
        }
        for(int i=0;i<2;i++){
            node nt;
            nt.x=t.x+d[i][0];
            nt.y=t.y+d[i][1];
            if(nt.x>=0&&nt.x<r&&nt.y>=0&&nt.y<c){
                nt.w=t.w+a[nt.x][nt.y];
                q.push(nt);
            }
        }
    }
}

int main(){
    int T,k=0;
    scanf("%d",&T);
    while(T--){
        k++;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&a[i][j]);
            }
        }
        maxw=0;
        bfs();
        printf("Scenario #%d:\n",k);
        printf("%d\n",maxw);
    }
    return 0;
}