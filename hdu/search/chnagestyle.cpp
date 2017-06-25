/**
 *   > File Name: chnagestyle.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/9
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=10001;
char ans[maxn],word[maxn][2],vis[maxn];   //ans保存一条路的结果
int num;
bool flag;
void dfs(char *s,int deepth){
    if(ans[deepth-1]=='m'){
        flag=1;
        return;
    }
    for(int i=0;i<num;i++){
        if(!vis[i]&&word[i][0]==s[1]){
            vis[i]=1;
            if(flag) return;
            ans[deepth]=word[i][0];
            ans[deepth+1]=word[i][1];
            dfs(word[i],deepth+2);
            vis[i]=0; //回朔
        }
    }
}
int main(){
    char str[55];
    int len,i;
    while(scanf("%s",str)!=EOF){
        memset(ans,0,sizeof(ans));
        memset(word,0,sizeof(word));
        num=0;
        while(str[0]!='0'){                     //只保存一个单词的首位字母
            len=strlen(str);
            word[num][0]=str[0];
            word[num][1]=str[len-1];
            num++;
            scanf("%s",str);
        }
        flag=0;
        for(i=0;i<num;i++){
            if(word[i][0] == 'b'){
                memset(vis,0,sizeof(vis));
                if(flag) break;
                vis[i]=1;
                dfs(word[i],2);   //对于每一个以b开头的单词都跑一次dfs
            }
        }
        if(flag) printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}
