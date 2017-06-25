/**
 *   > File Name: medicine_ac.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/20
 */
设浓度p,质量为m,对于体积V里的物质质量为：m=p*v;
如此得到总液体的总质量 M，和总体积 V；
之后的浓度为： P=M/V;

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdio>
using namespace std;
int main()
{
    int t, n,v,w,i,sum,count;
    cin>>t;
    while(t--)
    {
        cin>>n>>v>>w;
        vector<int>pi(n);
        for(i=0;i<n;i++)
        {
            cin>>pi[i];
        }
        sort(pi.begin(),pi.end(),less<int>());
        count=sum=0;
        for(i=0;i<n;i++)
        {
            sum+=pi[i];
            if(sum<=w*(count+1))
                count++;
            else
            {
                sum-=pi[i];
                break;
            }
        }
        if(count)
            printf("%d %.2lf\n",count*v,sum/(count*100.0));
        else
            printf("0 0.00\n");
    }
    return 0;
}