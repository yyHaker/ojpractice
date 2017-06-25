/**
 *   > File Name: flyingtomars_ac.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 *   时间复杂度(排序)
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[3010];
    int n,i;
    int max,count;
    while(scanf("%d",&n)!=EOF)
    {
        max=1;
        count=1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);  //从小到大排序   1 2 2 3 4 4 5 5 5
        for(i=1;i<n;i++)
        {
            if(a[i-1]==a[i])        //找到等级相等的的最多士兵个数，即最少需要的扫把数目
            {
                count++;
                if(count>max)
                    max=count;   //max记录等级相等的最多士兵的个数
                continue;
            }
            count=1;
        }
        printf("%d\n",max);
    }
    return 0;
}

