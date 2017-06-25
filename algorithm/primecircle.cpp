/**
 *   > File Name: primecircle.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/18
 */
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 20
bool is_prime(int m){
    if(m==1) return false;
    if(m==2||m==3) return true;
    for(int i=2;i*i<=m;i++){
        if(m%i==0) return false;
    }
    return true;
}

int main(){
    int n,isp[MAXN*2],A[MAXN];
    cin>>n;
    for(int i=2;i<=n*2;i++){  //生成素数表
        isp[i]=is_prime(i);
    }
    for(int i=0;i<n;i++){    //第一个排列
        A[i]=i+1;
    }
    do{
        int ok=1;
        for(int i=0;i<n;i++){    //判断当前排列是否满足相邻元素和为素数
            if(!isp[A[i]+A[(i+1)%n]]){
                ok=0;
                break;
            }
        }
        if(ok){
            for(int i=0;i<n;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
    }while(next_permutation(A+1,A+n));

    system("pause");
    return 0;
}
