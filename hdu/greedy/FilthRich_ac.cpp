/**
 *   > File Name: FilthRich_ac.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int maxx(int a,int b,int c){
    int sum = a>b? a : b;
    if(sum>c) return sum;
    else return c;
}
int a[1001][1001];
int d[1001][1001];
int main(){
    int T;
    int r,c;
    int k=0;
    scanf("%d",&T);
    while(T--){
        k++;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(d,0,sizeof(d));
        d[0][0]=a[0][0];
        for(int i=1;i<r;i++){
            d[i][0]=d[i-1][0]+a[i][0];
        }
        for(int j=1;j<c;j++){
            d[0][j]=d[0][j-1]+a[0][j];
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                d[i][j]=maxx(d[i-1][j],d[i][j-1],d[i-1][j-1])+a[i][j];
            }
        }
        printf("Scenario #%d:\n",k);
        printf("%d\n\n",d[r-1][c-1]);
    }
    return 0;
}