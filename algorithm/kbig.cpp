/**
 *   > File Name: quicksort.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/20
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int kindex;

void swap(int *A,int x,int y){
    int temp=A[x];
    A[x]=A[y];
    A[y]=temp;
}

int partition(int *A,int x,int y,int p){      //p为划分值
    int l=x,r=y;
    while(l<r){
        swap(A,l,r);
        while(A[l]<p&&l<r) l++;    //从左往右找到第一个大于或等于p的值
        while(A[r]>=p&&l<r) r--;   //从右往左找到第一个小于p的值
    }
    swap(A,l,y);
    return l;        //保证l左边的值小于p，右边的值大于等于p(第一次交换很重要)
}

void quicksort(int *A,int x,int y,int kindex){
    if(x>=y) return;
    else{
        int p=A[x];     //以某种策略选择划分点
        int k=partition(A, x, y,p);
        if(kindex<k-x+1){
            quicksort(A,x,k-1,kindex);
        }else if(kindex>k-x+1){
            quicksort(A,k+1,y,kindex);
        }
    }
}

int main(){
    int A[10]={4,4,8,2,9,3,6,10,10};  //求数组中第k大的数
    cin>>kindex;
    quicksort(A,0,8,kindex);
    cout<<A[kindex-1]<<endl;
    for(int i=0;i<=8;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}
