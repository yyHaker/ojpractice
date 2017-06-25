/**
 *   > File Name: coinproblem.cpp   Ӳ������
 *   > Author: yyHaker
 *   > Created Time: 2017/5/23
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXN 10000

int n;  //Ӳ������
int V[MAXN];  //��ֵ
int d[MAXN];  //d[i] ��ʾ�ӽڵ�i�������ڵ�0���·��
int vis[MAXN];  //��ʾ�ڵ�i�Ƿ�����

//���仯�����·��
int dp_max(int S){
    int &ans=d[S];
    if(vis[S]) return d[S];
    vis[S]=1;
    ans=-1;
    for(int i=1;i<=n;i++){
        if(S>=V[i]) ans = max(ans,dp_max(S-V[i])+1);
    }
    return ans;
}

//����ֵ�����С�ķ���
void print_ans(int *d,int S){
    for(int i=1;i<=n;i++){
        if(S>=V[i] && d[S]==d[S-V[i]]+1){
            cout<<V[i]<<" ";
            print_ans(d,S-V[i]);
            break;
        }
    }
}
int main(){
    int S;
    memset(vis,0,sizeof(vis));
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>V[i];
    }
    //��d[0]=0;������ĩ�ڵ�
    d[0]=0;
    vis[0]=1;
    cout<<dp_max(S)<<endl;
    cout<<"�������:"<<endl;
    print_ans(d,S);
    system("pause");
    return 0;
}
