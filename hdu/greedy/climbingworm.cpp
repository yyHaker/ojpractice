/**
 *   > File Name: climbingworm.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/11
 */
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n,u,d,time;
    int step;
    while(scanf("%d%d%d",&n,&u,&d)&&n!=0){
        time=0;
        step=0;
        while(step<n){
            step+=u;
            time+=1;
            if(step>=n) break;
            step-=d;
            time+=1;
        }
        printf("%d\n",time);
    }
}
