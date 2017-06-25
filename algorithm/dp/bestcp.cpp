/**
 *   > File Name: bestcp.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/23
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

const int nMax=21;
const double INF=1e10;
int n,S;
struct Node
{
    int x,y,z;
}node[nMax];
double d[1<<nMax];
void init()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
    S=1<<n;
    for(int i=1;i<S;i++)
        d[i]=-1;
    d[0]=0;
}
double min(double a,double b)
{
    return a<b?a:b;
}
double dis(Node &a,Node &b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double dp(int p)
{
    if(d[p]!=-1) return d[p];
    d[p]=INF;
    int i,j;
    for(i=n-1;i>=0;i--)
        if(p & (1<<i))
            break;
    for(j=i-1;j>=0;j--)
        if(p & (1<<j))
            d[p]=min(d[p],dis(node[i],node[j])+dp(p^(1<<i)^(1<<j)));
#ifdef TEST
    printf("%d %d\n",p,d[p]);
#endif
    return d[p];
}
int main()
{
    freopen("E://data1.txt","r",stdin);
    init();
    printf("%.3lf\n",dp(S-1));

    system("pause");
    return 0;
}
