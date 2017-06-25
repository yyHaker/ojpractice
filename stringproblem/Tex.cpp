/**
 *   > File Name: Tex.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/11
 */
#include<iostream>
#include <cstdio>

using namespace std;

int main(){
    int c,q=1;
    while((c=getchar())!=EOF)
    {
        if(c=='"'){
            printf("%s", q?"``":"''");
            q=!q;
        }else printf("%c",c);
    }
    return 0;
}
