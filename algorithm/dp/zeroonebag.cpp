/**
 *   > File Name: zeroonebag.cpp   01背包问题
 *   > Author: yyHaker
 *   > Created Time: 2017/5/23
 *
 *   思考：1.怎么使用滚动数组？
 *             2.如果容量不是整数怎么办？
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXN 100

int n,V[MAXN],W[MAXN],C,d[MAXN][MAXN];

//多阶段决策、递推求解、d[i][j]表示把第i,i+1,i+1,...,n个物品放到容量为j的背包中的最大总容量
void dp(){
 for(int i=n;i>0;i--){
  for(int j=0;j<=C;j++){
   d[i][j] = i == n ? 0 : d[i+1][j];
   if(j>=V[i]){
    d[i][j] = max(d[i+1][j], d[i+1][j-V[i]]+W[i]);
   }
  }
 }
}

int main(){
 cin>>n;
 cout<<"please input the v and the weight:"<<endl;
 for(int i=1;i<=n;i++){
  cin>>V[i]>>W[i];
 }
 cout<<endl;
 cout<<"please input the C:"<<endl;
 cin>>C;
 dp();
 cout<<d[1][C]<<endl;
 system("pause");
 return 0;
}
