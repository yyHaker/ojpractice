/**
 *   > File Name: bigfact.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/12
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define Maxn  3000
int main(){
    int f[Maxn]; //存储n！的运算结果
    int n;
    cin>>n;
    memset(f,0,sizeof(f));
    f[0]=1;
    for(int i=2;i<=n;i++){
        //乘以i
        int c=0; //保存进位
        for(int j=0;j<Maxn;j++){
            int s=f[j]*i+c;
            f[j]=s%10;
            c=s/10;
        }
    }
    //忽略前导0
    int i;
    for( i=Maxn-1;i>=0;i--){
        if(f[i]!=0) break;
    }
    for(int j=i;j>=0;j--){
        cout<<f[j];
    }
    cout<<endl;
    system("pause");
}
