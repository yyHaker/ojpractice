/**
 *   > File Name: mergesort.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/20
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void merg_sort(int *A,int x,int y,int *T){
    if(y-x>1){
        int m=x+(y-x)/2;    //划分
        int p=x,q=m+1,i=x;
        merg_sort(A,x,m,T);
        merg_sort(A,m+1,y,T);

        while(p<=m||q<=y){
            if(q>y||p<=m&&A[p]<=A[q])   T[i++]=A[p++];
            else T[i++]=A[q++];
        }
        for(i=x;i<=y;i++)  A[i]=T[i];
    }
}
int main(){
    int A[10]={4,7,4,2,9,3,6,2,6};
    int T[10];
    merg_sort(A,0,8,T);
    for(int i=0;i<=8;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}
