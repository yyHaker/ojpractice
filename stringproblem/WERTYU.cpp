/**
 *   > File Name: WERTYU.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/11
 */
#include <iostream>
#include <cstdio>

using namespace std;
int main(){
    char *s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i,c;
    while((c=getchar())!=EOF){
        for(i=1;s[i]&&s[i]!=c;i++);       //s[i]指向\0时候，s[i]==NULL
        if(s[i]) putchar(s[i-1]);
        else putchar(c);
    }
    return 0;
}
