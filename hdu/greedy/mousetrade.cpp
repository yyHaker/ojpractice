/**
 *   > File Name: mousetrade.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/10
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1005

struct node{
    int J;
    int F;
    double cj;
};
bool compare(node a,node b){
    return a.cj>b.cj;   //降序排序
}

int main(){
    int M,N;
   node room[MAX];
    while(scanf("%d%d",&M,&N)&&!(M==-1&&N==-1)){
        for(int i=1;i<=N;i++){
            scanf("%d%d",&room[i].J,&room[i].F);
            room[i].cj=room[i].J/(room[i].F+0.0);
        }
        sort(room+1,room+N+1,compare);
        double max=0;
        int tm=M;
       for(int i=1;i<=N;i++){
           if(tm<=room[i].F){
               max+=tm*room[i].cj;
               break;
           }
           max+=room[i].J;
           tm-=room[i].F;
       }
        printf("%.3f\n",max);
    }

    return 0;
}
