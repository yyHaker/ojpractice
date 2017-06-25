/**
 *   > File Name: maxsum.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/24
 */
#include <iostream>
using namespace std;


#define MAXN 100010

/**
 * dp:具有最优子结构和重叠子问题
 * dp:最大连续子序列的和只可能以0,1,2,...,n-1中某个位置结尾，当遍历到第i个元素时，判断在它前面的连续子序列的和是否大于0。
 * 如果大于0，则以位置i结尾的最大连续子序列的和为元素i和前面最大子序列的和相加；如果小于0，则以位置i结尾的最大连续子序列的和为元素i。
 * dp方程: sum[i]=max{sum[i-1]+a[i],a[i]}  sum[i]表示以位置i结尾的最大连续子序列的和
 */
int maxsequecesum(int a[],int n,int &begin,int &end){
    int maxsum,maxhere;
    begin=0,end=0;      //记录最大子序列的起点和终点
    int hbegin=0,hend=0; //记录局部起点和终点
    maxsum=maxhere=a[0];      //初始化最大值
    for(int i=1;i<n;i++){
        if(maxhere<0){
            maxhere=a[i];
            hbegin=i;
        } else{
            maxhere+=a[i];
            hend=i;
        }
        if(maxhere>maxsum){      //更新最大子序列的和
            maxsum=maxhere;
            begin=hbegin;
            end=hend;
        }
    }
    return maxsum;
}

int main(){
    int T,N,a[MAXN];
    int maxsum=0,begin=0,end=0;
    cin>>T;
    int i=1;
    while(T--){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>a[j];
        }
        cout<<"Case "<<i++<<":"<<endl;
        maxsum=maxsequecesum(a,N,begin,end);
        cout<<maxsum<<" "<<begin+1<<" "<<end+1<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
