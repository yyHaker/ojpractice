/**
 *   > File Name: WoodenSticks.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 *   思路：用结构体存储l，w，排序，每次选择排序在前面的那个sticks并标记，直到所有被标记
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
    int l,w,d;     //l,w分别表示长度和重量，d表示该sticks是否被加工
}node[5050];

bool cmp(Node a,Node b){
    return a.l==b.l? a.w<b.w : a.l<b.l;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        memset(node,0,sizeof(node));
        for(int i=0;i<n;i++){
            scanf("%d%d",&node[i].l,&node[i].w);
        }
        sort(node,node+n,cmp);
        int sum=0;
        for(int k=0;k<n; ){
            sum+=1;    //第一个直接加一分钟
            int l=0,w=0;
            for(int i=0;i<n;i++){
                if(node[i].d==0){
                    if(node[i].l>=l && node[i].w>=w){
                        k++;
                        node[i].d=1;
                        l=node[i].l;
                        w=node[i].w;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
