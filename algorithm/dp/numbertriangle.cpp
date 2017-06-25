/**
 *   > File Name: numbertriangle.cpp  数字三角形问题
 *   > Author: yyHaker
 *   > Created Time: 2017/5/22
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXN 50

int a[MAXN][MAXN];
int d[MAXN][MAXN];
int n;

/**
 * 动态规划解法
 */
void dp(){
 for(int k=1;k<=n;k++){
  d[n][k]=a[n][k];
 }
 for(int i=n-1;i>=1;i--){
  for(int j=1;j<=i;j++){
   d[i][j]=a[i][j] + (d[i+1][j] > d[i+1][j+1] ? d[i+1][j] :d[i+1][j+1]);
  }
 }
}

/**
 * 记忆化搜索的方法(递归)(先初始化d)
 */
int dp_search(int i,int j){
 if(i<=n&&j<=n){
  if(d[i][j]>=0) return d[i][j];
  else return d[i][j]= a[i][j]+ (i == n ? 0 : (dp_search(i+1,j) > dp_search(i+1,j+1) ? dp_search(i+1,j) : dp_search(i+1,j+1)));
 }else return 0;
}

int main(){
 cin>>n;
 cout<<"please input the distance"<<endl;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=i;j++){
   cin>>a[i][j];
  }
 }

 //dp()
 //cout<<"d[1][1]="<<d[1][1]<<endl;

 memset(d,-1,sizeof(d));
 dp_search(1,1);
 cout<<"d[1][1]="<<d[1][1]<<endl;
 system("Pause");
 return 0;
}

