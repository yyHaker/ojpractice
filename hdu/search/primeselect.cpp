/**
 *   > File Name: primeselect.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/9
 *   合理利用素数表
 *   素数筛选法：对于不超过n的所有非负整数p，依次删除2p,3p,4p....,没有被删除的数就是素数
 *   改进：p限定为素数，n限制在sqrt(n)以内，内层循环从i*i开始
 */
#include <iostream>
#include <math.h>
using namespace std;
const int maxn= 100000 +10;
bool prime[maxn];
int num[maxn];  //存储素数
int cnt=0;

void f_prime(){ //素数筛选
    int m=(int)sqrt(maxn+0.5);
    for(int i=2;i<=m;i++){
        if(!prime[i]){
            num[cnt++]=i;
            for(int j=i*i;j<=maxn;j+=i){
                prime[j]=1;
            }
        }
    }
}

int main(){
    int m;
    double a,b;
    f_prime();
    while(cin>>m>>a>>b){
        if(m==0&&a==0&&b==0) break;
        int max=0,maxi=0,maxj=0;
        for(int i=0;i<=sqrt(m);i++){ //p
            for(int j=i;j<cnt-1;j++){ //q
                double div=(double)num[i]/(double)num[j]-(a/b);
                if(num[i]*num[j]<=m&&div>=0){
                    if(num[i]*num[j]>max){
                        max=num[i]*num[j];
                        maxi=num[i];
                        maxj=num[j];
                    }
                }
            }
        }
        cout<<maxi<<" "<<maxj<<endl;
    }
    return 0;
}