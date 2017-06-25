/**
 *   > File Name: flyingtomars.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 3005

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int N;
    int s[MAXN];
    int t[MAXN]; //零时数组
    while(scanf("%d",&N)){
        for(int i=0;i<N;i++){
            scanf("%d",&s[i]);
        }
        memset(t,0,sizeof(t));
        int k=1;
        t[0]=s[0];
        int num=1;
        for(int i=1;i<N;i++){
            int flag=0;
            for(int j=0;j<k;j++){
                if(s[i]==t[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){  //没有相同的
                t[k]=s[i];
                k++;
            }else{
                memset(t,0,sizeof(t));
                t[0]=s[i];
                k=1;
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}