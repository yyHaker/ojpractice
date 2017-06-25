/**
 *   > File Name: treasure.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct treasure{
    int p;   //单价
    int m;   //体积
};

bool cmp(treasure a, treasure b){   //按照单价从大到小进行排序
    return a.p>b.p;
}
int main(){
    int v,n;
    treasure t[120];
    while(scanf("%d%d",&v,&n),v){
        for(int i=0;i<n;i++){
            scanf("%d%d",&t[i].p,&t[i].m);
        }
        sort(t,t+n,cmp);
        //依次装入直到装满
        int sum=0;
        int tv=v;
        for(int i=0;i<n;i++){
            if(tv>0){
                if(tv>t[i].m){
                    sum+=t[i].m*t[i].p;
                    tv=tv-t[i].m;
                }else{
                    sum+=tv*t[i].p;
                    break;
                }
            }else break;
        }
        printf("%d\n",sum) ;
    }
    return 0;
}