/**
 *   > File Name: movingtables_shuzu.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/11
 *   用数组模拟，求解最大重叠区间数(注意别理解错了)
 *   样例数据：
 *   3
 *   4 5
 *   5 6
 *   6 7
 *   》》》20
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 500
int main(){
    int T,n,a[N];
    int b,c;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&b,&c);
            if(b>c){
                int temp=b;
                b=c;
                c=temp;
            }
            if(b%2)b+=1;
            if(c%2)c+=1;
            for(int i=b;i<=c;i+=2){
                a[i]+=10;
            }
        }
        int ans=-1;
        for(int i=2;i<400;i+=2){
            if(a[i]>ans) ans=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}