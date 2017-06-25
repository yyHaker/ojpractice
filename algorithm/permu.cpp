/**
 *   > File Name: permu.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   int n,p[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p,p+n);
    do{
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(p,p+n));
    system("pause");
    return 0;
}

