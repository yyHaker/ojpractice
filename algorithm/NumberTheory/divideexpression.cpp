/**
 *   > File Name: divideexpression.cpp    怎么判断一串除法表达式为整数
 *   > Author: yyHaker
 *   > Created Time: 2017/6/3
 */
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXNK 10000

//欧几里得算法求最大公约数
int gcd(int a,int b){
    return b==0? a : gcd(b,a%b);
}
//利用欧几里得算法求最小公倍数(lcm(a,b)*gcd(a,b)=a*b)
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}


int main(){
    int X[MAXNK];
    int K;
    while (scanf("%d",&K)){
        for(int i=0;i<K;i++){
            scanf("%d",&X[i]);
        }
        //judge
        X[2]=X[2]/gcd(X[2],X[1]);
        for(int i=3;i<=K;i++){
            X[2]=X[2]/gcd(X[i],X[2]);
        }
        if(X[2]==1) printf("YES\n");
        else printf("NO\n");
    }

}
