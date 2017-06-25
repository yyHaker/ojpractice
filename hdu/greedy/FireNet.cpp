/**
 *   > File Name: FireNet.cpp
 *   > Author: yyHaker         简单的dfs+check
 *   > Created Time: 2017/6/11
 */
#include <iostream>
#include <cstdio>

using namespace std;

int n;
char  maze[6][6];
int vis[6][6];
int ans=0; //统计blockshouse


bool check(int a,int b){
    return (a>=0&&a<n&&b>=0&&b<n&&maze[a][b]=='.');
}

bool recheck(int a,int b){
   if(check(a,b)){
       //检查上下左右四个方向是否满足条件
       //up
       for(int i=a-1;i>=0&&check(i,b);i--){
           if(vis[i][b]) return false;
       }
       //down
       for(int i=a+1;i<n&&check(i,b);i++){
           if(vis[i][b]) return false;
       }
       //left
       for(int j=b-1;j>=0&&check(a,j);j--){
           if(vis[a][j]) return false;
       }
       //right
       for(int j=b+1;j<n&&check(a,j);j++){
           if(vis[a][j]) return false;
       }
       return true;
   }
    return false;
}

void  dfs(int num){
    if(num>ans) ans=num;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(recheck(i,j)&&!vis[i][j]){  //如果i,j位置满足放置blockhouse
                vis[i][j]=1;
                dfs(num+1);
                vis[i][j]=0;//回朔
            }
        }
    }
}
int main(){
    char s[6];
    while(scanf("%d",&n)&&n!=0){
        for(int i=0;i<n;i++){
            scanf("%s",s);
            for(int j=0;j<n;j++){
                maze[i][j]=s[j];
            }
        }
        //dfs
        ans=0;
        dfs(0);
        printf("%d\n",ans);
    }
}
