/**
 *   > File Name: maxmin.cpp   利用二分法求解最大最小值问题
 *   > Author: yyHaker
 *   > Created Time: 2017/5/21
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define INF 1000

int n;
//能否把包含n个整数的输入序列划分成m个连续的子序列，使得所有的S(i)均不超过x？
bool P(int a[],int m,int x){
    int sum=0;
    int seg=1;   //累积段数
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>x){
            sum=a[i];   //另起一段
            seg++;
        }
    }
    return seg<=m;   //表明能否换分为m段
}

int value(int a[],int low,int high,int seg){
    if(low==high){
        return low;
    }else{
        int x=(low+high)/2;
        if(P(a,seg,x)) return value(a,low,x,seg);
        else return value(a,x+1,high,seg);
    }
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //求出x的边界值
    int min=INF,max=0;
    for(int i=0;i<n;i++){
        max+=a[i];
        if(a[i]<min) min=a[i];
    }
    cout<<endl;
    int maxmin=value(a,min,max,m);
    cout<<maxmin<<endl;

    system("pause");
    return 0;
}
