/**
 *   > File Name: maxreimbursements.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/26
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[3500000];
int main(){
    int n,m,top;
    double q;
    while((scanf("%lf%d",&q,&n)!=EOF)&&(n!=0)){
        char type;
        double price;
        int money[35];   //记载每张发票的总钱数
        top=(int)(q*100);  //报销额度上限(x100)
        memset(money,0,sizeof(money));
        for(int i=1;i<=n;i++){
            int a=0,b=0,c=0,tag=0;
            scanf("%d",&m);
            for(int j=1;j<=m;j++){
                getchar();
                scanf("%c:%lf",&type,&price);
                int x=(int)(price*100);
                if(type=='A') a+=x;
                else if(type=='B') b+=x;
                else if(type=='C') c+=x;
                else tag=1;
            }
            if(tag!=1&&a+b+c<=100000&&a<=60000&&b<=60000&&c<=60000) money[i]=a+b+c;
            else money[i]=top+1;  //表示不报销该发票
        }
        //01背包，dp求解 dp[j]表示容量为j的背包中所装载的最大容量
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=top;j>=money[i];j--){
                dp[j]=max(dp[j],dp[j-money[i]]+money[i]);
            }
        }
        printf("%.2f\n",dp[top]/100.0);
    }
}
