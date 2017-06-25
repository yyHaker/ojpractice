/**
 *   > File Name: HourseRacing.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

struct node{
    int s,d;  //s表示速度，d表示是否已经比赛
};

bool cmp(node a,node b){
    return a.s>b.s;  //排序准则
}

int main(){
    int n;
    node tian[MAXN];
    node king[MAXN];
    while(cin>>n){
        for(int i=0;i<n;i++){
            scanf("%d",&tian[i].s);
            tian[i].d=0;
        }
        sort(tian,tian+n,cmp);
        for(int i=0;i<n;i++){
            scanf("%d",&king[i].s);
            king[i].d=0;
        }
        sort(king,king+n,cmp);
        //计算最多能够赢的场数
        int v=0;
        int t=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(tian[i].d==0&&king[j].d==0&&tian[i].s>king[j].s){
                    tian[i].d=1;
                    king[j].d=1;
                    v++;
                    t=i;//记录tian的下标
                }
            }
        }
        //计算输的场次（t+1-->n-1）
        int lose=0;
        for(int i=n-1;i>=t+1;i--){
            int j=0;
            if(tian[i].s<king[j].s){
                lose++;
            }
            j++;
        }
        int sum=(v-(lose))*200;
        printf("%d\n",sum);
    }
    return 0;
}
