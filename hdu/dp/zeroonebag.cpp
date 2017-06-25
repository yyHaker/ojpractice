/**
 *   > File Name: zeroonebag.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/25
 */
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100
#define MAXC 10000

int main(){
    int T;
    cin>>T;
    int n,V[MAXN],W[MAXN],C;
    int d[MAXC];  //d[j]表示容量为j的背包所能装的最大重量
    while(T--){
        cin>>n>>C;
        for(int i=1;i<=n;i++){
            cin>>V[i]>>W[i];
        }
        memset(d,0,sizeof(d));
        d[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=C;j>=V[i];j--){
                d[j]=max(d[j],d[j-V[i]]+W[i]);
            }
        }
        cout<<d[C]<<endl;
    }
    return 0;
}
