/**
 *   > File Name: extendgcd.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/3
 */
#include <iostream>
#include <cstdlib>

using namespace std;

//扩展的欧几里得算法求解ax+by=gcd(a,b)
void gcd(int a,int b,int &d,int &x,int &y){
    if(!b){
        d=a; x=1; y=0;
    }else{
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

int main(){
    int a,b,d,x,y;
    cin>>a>>b;
    gcd(a,b,d,x,y);
    system("pause");
    return 0;
}
