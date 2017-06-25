/**
 *   > File Name: movingtables.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/11
 *   思路：统计排序
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 210
int main(){
    int T;
    int n;
    int cnt[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int a,b;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            int l=min(a,b);
            int r=max(a,b);
            l=(l+1)/2;
            r=(r+1)/2;
            for(int j=l;j<=r;j++){
                cnt[j]+=10;
            }
        }
        int ans=0;
        for(int i=1;i<=200;i++){
            if(cnt[i]>ans) ans=cnt[i];
        }
        printf("%d\n",ans);
    }
}

