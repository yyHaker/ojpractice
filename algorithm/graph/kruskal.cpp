/**
 *   > File Name: kruskal.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/29
 *   Kruskal算法：将边按照从下到大进行排序，从小大大依次考察每条边(u,v),如果u和v在同一个连通分量，显然不能将改边添加到MST；
 *   如果u，v不在同一个连通分量，将边加入到MST并合并u，v所在的连通分量
 *   (关于实现主要是连通分量的查询和合并-使用并查集)
 */
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXM 50    //最大边数
#define MAXN 50    //最大顶点数
int u[MAXM],v[MAXM],w[MAXM]; //第i条边的端点序号和权值
int p[MAXN]; //p[x]表示x的父节点  (并查集)
int r[MAXM]; //第i小的边的序号
int cmp(const int i,const int j){
    return w[i]<w[j];
}
int find(int x){  //查询点x的根节点(顺便把遍历过的节点都改成树根的儿子)
    return p[x] == x ? x : p[x]=find(p[x]);
}
int Kruskal(int n,int m){    //n个顶点，m条边
    int ans=0; //最小生成树的代价
    for(int i=1;i<=n;i++) p[i]=i;  //初始化并查集
    for(int i=0;i<m;i++) r[i]=i; //初始化边的序号
    sort(r,r+m,cmp);             //给边排序
    for(int i=0;i<m;i++){
        int e=r[i]; int x=find(u[e]); int y=find(v[e]);  //找出当前边两个端点所在的集合编号
        if(x!=y){
            ans+=w[e];
            p[x]=y;  //合并
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"please input vnum and snum:"<<endl;
    cin>>n>>m;
    cout<<"please input the node and weight:"<<endl;
    for(int i=0;i<m;i++){   //依次输入第i条边的端点序号和权值
        cin>>u[i]>>v[i]>>w[i];
    }
    int sum=Kruskal(n,m);
    cout<<"the total cost is "<<sum<<endl;
    system("pause");
    return 0;
}
