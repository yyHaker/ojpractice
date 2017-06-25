/**
 *   > File Name: subset_vector.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>

using namespace std;

/*递归输出n以内所有的子集,其中b表示该节点是否选中，cur为当前下标,初始值0*/
void print_subset(int n,bool *b,int cur){
    if(cur==n){
        for(int i=0;i<n;i++){
            if(b[i]) cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    b[cur]=true;
    print_subset(n,b,cur+1);
    b[cur]=false;
    print_subset(n,b,cur+1);
}
int main(){
    bool b[20]={0};   //判断当前每一个节点的选中状态
    int n;
    while(cin>>n,n){
        print_subset(n,b,0);
    }
    return 0;
}
