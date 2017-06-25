/**
 *   > File Name: citygame.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/27
 */
#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXN 1010

using namespace std;

int main(){
    int K,m,n;
    char s[MAXN];
    int h[MAXN],l[MAXN],r[MAXN];
    int maxsquare=0;
    cin>>K;
    while(K--){
        scanf("%d%d",&m,&n);
        memset(h,0,sizeof(h));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%s",s);
                if(s[0]=='F') h[j]++;
                else h[j]=0;
            }
            //计算每一行的l[i]和r[i]，l[i]表示从位置i开始向左的连续>=a[i]的最左下标
            l[1]=1;
            for(int j=2;j<=n;j++){
                int k=j;
                while(k>1&&h[k-1]>=h[j])
                    k=l[k-1];
                l[j]=k;
            }
            r[n]=n;
            for(int j=n-1;j>=1;j--){
                int k=j;
                while(k<n&&h[k+1]>=h[j])
                    k=r[k+1];
                r[j]=k;
            }
            for(int j=1;j<=n;j++){
                int temp=(r[i]-l[i]+1)*h[i]*3;
                if(temp>maxsquare) maxsquare=temp;
            }
        }
        printf("%d\n",maxsquare);
    }
    return 0;
}
