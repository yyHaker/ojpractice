/**
 *   > File Name: ccgame.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/27
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <cstring>

using namespace std;
int T,n,m,ans;
char c;
bool a[1005][1005];
int l[1005][1005],r[1005][1005],h[1005][1005];
void make()
{
    int k;
    ans=0;
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(h,0,sizeof(h));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]) h[i][j]=h[i-1][j]+1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[i][j])
            {
                l[i][j]=j;
                while(l[i][j]>0&&h[i][l[i][j]-1]>=h[i][j])
                    l[i][j]=l[i][l[i][j]-1];
            }
        for(int j=m;j>0;j--)
            if(a[i][j])
            {
                r[i][j]=j;
                while(r[i][j]>0&&h[i][r[i][j]+1]>=h[i][j])///
                    r[i][j]=r[i][r[i][j]+1];
            }
        for(int j=1;j<=m;j++)
            ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);///
    }
    printf("%d\n",ans*3);
}
int main()
{
    //freopen("City game.in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%s",&c);
                if(c=='F')
                    a[i][j]=1;
                else a[i][j]=0;
            }
        make();
    }
    return 0;
}
