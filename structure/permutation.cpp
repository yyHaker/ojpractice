/**
 *   > File Name: toposort.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void permutation(int a[],int m,int n) {
    if(m==n){
        for(int i=0;i<=n;i++){
           cout<<a[i]<<" ";
        }
        cout<<endl;
    }else{
        for(int i=m;i<=n;i++){
            swap(a,m,i);
            permutation(a,m+1,n);
            swap(a,m,i);
        }
    }

}


int main(){
   int a[]={1,2,3,4};
    //cout<<sizeof(a)/sizeof(a[0])<<endl;
    permutation(a,0,3);
    system("pause");
    return 0;
}

