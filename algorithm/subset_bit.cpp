/**
 *   > File Name: subset_bit.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>

using namespace std;

void print_subset(int n,int s){  //打印{0,1,2,...,n-1}的子集s
    for(int i=0;i<n;i++){
        if(s&(1<<i))  cout<<i<<" ";   //表示相应的位置是否需要输出
    }
    cout<<endl;
}
int main(){
   int n;
    while(cin>>n,n){
        for(int i=0;i<(1<<n);i++){
            print_subset(n,i);
        }
    }
    return 0;
}
