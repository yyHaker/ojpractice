/**
 *   > File Name: SafeCracker.cpp  深度优先搜索-在一组数中找出满足条件的某几个数问题
 *   > Author: yyHaker
 *   > Created Time: 2017/6/2
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[15],b[10];
int visit[15];
int n,len;
bool judge=false;

bool cmp(char a,char b){
    return a>b;
}
bool check(){
    if(n==b[0]-b[1]*b[1]+b[2]*b[2]*b[2]-b[3]*b[3]*b[3]*b[3]+b[4]*b[4]*b[4]*b[4]*b[4]){
        judge=true;
        return true;
    }else return false;
}
void dfs(int depth){   //依次往b中填充5个数字看是否满足条件，找到即返回
    if(judge) return;
    if(depth==5){
        check();
        return;
    }
    for(int i=0;i<len;i++){
        if(!visit[i]&&!judge){
            b[depth]=a[i];
            visit[i]=1;
            dfs(depth+1);
            visit[i]=0;  //回朔
        }
    }
}
int main(){
    while(scanf("%d %s",&n,a)&&!(n==0&&!strcmp(a,"END"))){
        len=strlen(a);
        judge=false;
        memset(visit,0,sizeof(visit));
        sort(a,a+len,cmp);   //降序排序
        for(int i=0;i<len;i++){      //将字母换成alphabet中相应的数字
            a[i]=a[i]-'A'+1;
        }
        dfs(0);
        for(int i=0;i<5;i++){
            b[i]=b[i]+'A'-1;    //换回字母
        }
        if(judge) printf("%s\n",b);
        else printf("no solution\n");
    }
    return 0;
}
