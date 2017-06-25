/**
 *   > File Name: leastinterupt_ac.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 *   思路：依次判断新来的导弹能否在以前的系统中被拦截，如果不能增加新系统
 *   (ac)
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int i,t,n;
    while(scanf("%d",&t)!=EOF)
    {
        int a[255]={30001}; //把每个拦截系统都赋予能拦截的最大高度
        int xt=1;           //一开始拦截系统只有一个
        while(t--)
        {
            scanf("%d",&n);   //拦截系统最后拦截高度从第一个到后面都是从小到大排列，无需排序
            for(i=0;i<xt;i++) //遍历所有拦截系统最后能拦截高度查看有没有比它高的
                if(n<=a[i]){
                    a[i]=n;
                    break;
                }
            if(n>a[xt-1]){ //如果导弹比最后一个拦截系统高度高，那么就需要再使用下一个拦截系统
                a[xt]=n;
                xt++;
            }
        }
        printf("%d\n",xt);  //输出最后要开辟的拦击系统
    }
    return 0;
}