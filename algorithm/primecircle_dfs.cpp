/**
 *   > File Name: primecircle_dfs.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/18
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXN 20

int n,A[MAXN],vis[MAXN];
int isp[MAXN*2];

bool is_prime(int m){
    if(m==1) return false;
    if(m==2||m==3) return true;
    for(int i=2;i*i<=m;i++){
        if(m%i==0) return false;
    }
    return true;
}

void dfs(int cur){
    if(cur==n&&isp[A[0]+A[n-1]]){
        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }else{
        for(int i=2;i<=n;i++){   //尝试放置数i
            if(!vis[i]&&isp[i+A[cur-1]]){
                A[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;                  //回朔
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=2;i<=n*2;i++){  //生成素数表
        isp[i]=is_prime(i);
    }
    for(int i=0;i<n;i++){
        A[i]=i+1;
    }
   dfs(1);

    system("pause");
    return 0;
}
