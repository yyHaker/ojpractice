/**
 *   > File Name: lrh.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/27
 *   思路：利用向两边扫描的求出高度不低于当前位置的矩形位置，因为宽度都为1,那么当前矩形的最大矩形面积就是(right[i]-lefr[i]+1)*height[i]了。
 *   最坏的时间复杂度为O(n^2)
 */
#include <iostream>
#include <cstdio>

using namespace std;

__int64 a[100010],l[100010],r[100010];  //l[i]表示向左扫描到>=a[i]的最左位置，r[i]表示向右扫描到>=a[i]的最右位置
int main(){
    __int64 i,j,n,max;
    while(scanf("%lld",&n)!=EOF&&n!=0){
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        l[1]=1,r[n]=n;
        for(i=2;i<=n;i++){
            j=i;
            while(a[j-1]>=a[i]&&j>0)
                j=l[j-1];    //相当于跳步计算
                //j--;
            l[i]=j;
        }
        for(i=n-1;i>=1;i--){
            j=i;
            while(a[j+1]>=a[i]&&j<n)
                j=r[j+1];
                //j++;
            r[i]=j;
        }
        max=-9999;
        for( i=1;i<=n;i++){
            if((r[i]-l[i]+1)*a[i]>max) max=(r[i]-l[i]+1)*a[i];
        }
        printf("%lld\n",max);
    }
    return 0;
}
