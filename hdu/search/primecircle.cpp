/**
 *   > File Name: primecircle.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/2
 */
#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[30],b[30];
int visited[30];
bool isprime(int m){
    if(m==1)  return false;
    if(m==2) return true;
    for(int i=2;i*i<=m;i++){
        if(m%i==0) return false;
    }
    return true;
}
void dfs(int depth){
    if(depth==n+1){
        //check
        if(isprime(b[1]+b[n])){
            for(int j=1;j<n;j++){
                cout<<b[j]<<" ";
            }
            cout<<b[n]<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]&&(b[depth-1]+i)%2!=0&&isprime(i+b[depth-1])){
            b[depth]=i;
            visited[i]=1;
            dfs(depth+1);
            visited[i]=0;
        }
    }
}

int main(){
    int c=1;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        memset(visited,0,sizeof(visited));
        b[1]=1;
        visited[1]=1;
        cout<<"Case "<<c++<<":"<<endl;
        //dfs
        dfs(2);
        cout<<endl;
    }
}
