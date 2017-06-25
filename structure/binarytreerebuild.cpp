/**
 *   > File Name: binarytreerebuild.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/16
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define M 100

void build(int n,char* s1,char* s2,char*s)  //n指当前树的长度，s1先序序列，s2中序序列，s后序序列
{
    if(n<=0) return;
    int p = strchr(s2,s1[0])-s2;       //找到根节点在中序遍历中的位置
    build(p,s1+1,s2,s);                    //递归构造左子树的后序遍历
    build(n-p-1,s1+p+1,s2+p+1,s+p);  //递归构造右子树的后序遍历
    s[n-1]=s1[0];                             //把根节点加到最后
}

int main(){
    char s1[M],s2[M],*ans;
    while(scanf("%s%s",s1,s2) == 2){
        int n=strlen(s1);
        build(n,s1,s2,ans);
        ans[n]='\0';
        printf("%s\n",ans);
    }


}
