/**
 *   > File Name: bitcount.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/12
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)==2){
        if(!a&&!b) return 0;
        int c=0,count=0;  //c表示进位，count表示进位次数
        while(a%10!=0||b%10!=0){
            c=(a%10+b%10+c) >9 ? 1 : 0;
            count+=c;
            a=a/10;
            b=b/10;
        }
        printf("%d\n",count);
    }
    system("pause");
    return 0;
}
