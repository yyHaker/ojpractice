/**
 *   > File Name: changestyle_bc.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/9
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=10000+10;
int a[26];
char word[maxn];

int find(int x){
    int v=x;
    while (a[x]!=x){
        x=a[x];
    }
    if(a[v]!=a[x]){
        a[v]=x;
    }
    return x;
}

bool merge(int i,int j){
    int fa,fb;
    fa=find(i);
    fa=find(j);
    if(fa==12) return true;
    if(fa!=fb){
        a[fa]=fb;  //让m始终为头节点，始终不合并，理由请自己深思。
        return true;
    }
    return false;
}



int main(){
    int len,i,x,y;
    while(scanf("%s",word)!=EOF){
        getchar();
        for(i=0;i<26;i++){
            a[i]=i;
        }
        while(word[0]!='0'){
            len=strlen(word);
            x=word[0]-'a';
            y=word[len-1]-'a';
            merge(x,y);
            scanf("%s",word);
            getchar();
        }
        if(find(1)==12){
            printf("Yes.\n")
        }else{
            printf("No.\n");
        }
    }
    return 0;
}
