/**
 *   > File Name: sumproblem.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/24
 */
#include <iostream>

using namespace std;

int sum(int n){
    int result=0;
    for(int i=1;i<=n;i++){
        result+=i;
    }
    return result;
}

int main(){
    int n;
    while(cin>>n){
        cout<<sum(n)<<endl;
        cout<<endl;
    }
}
