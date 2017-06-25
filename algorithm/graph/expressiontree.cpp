/**
 *   > File Name: expressiontree.cpp  表达式树-一个表达式构建成树
 *   > Author: yyHaker
 *   > Created Time: 2017/5/28
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1000;
int lch[maxn],rch[maxn];char op[maxn]; //每个节点的左右儿子编号和字符
int nc=0; //节点数

int build_tree(char* s,int x,int y){
    int c1=-1,c2=-1,p=0;
    int u;  //节点编号
    if(y-x==0){    //仅一个字符，建立单独节点
        u=++nc;
        lch[u]=rch[u]=0;
        op[u]=s[x];
        return u;
    }
    //找到最后一个运算符
    for(int i=x;i<=y;i++){
        switch(s[i]){
            case '(': p++; break;
            case ')': p--; break;
            case '+':
            case '-': if(!p) c1=i; break;
            case '*':
            case '/': if(!p) c2=i; break;
        }
    }
    if(c1<0) c1=c2;
    if(c1<0) return build_tree(s,x+1,y-1); //整个表达式被一个括号围起来
    u=++nc;  //设置当前根节点的编号
    lch[u]=build_tree(s,x,c1-1);
    rch[u]=build_tree(s,c1+1,y);
    op[u]=s[c1];
    return u;
}

int main(){
    char s[20];
    cin>>s;
    int len=strlen(s);
    printf("%d\n",len);
    build_tree(s,0,len-1);
    return 0;
}
