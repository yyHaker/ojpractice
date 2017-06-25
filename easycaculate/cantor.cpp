/**
 *   > File Name: cantor.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/14
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int k=1,s=0;
        while(1){
            s+=k;
            if(s>=n)     //n是第k条对角线上的倒数第s-n+1元素
            {
                if(k%2==0){  //n是第k条对角线上的倒数第s-n+1元素(往左下)
                    printf("%d/%d\n",k-s+n,s-n+1);
                }else{          ////n是第k条对角线上的倒数第s-n+1元素(往右上)
                    printf("%d/%d\n",s-n+1,k-s+n);
                }
                break;
            }
            k++;
        }
    }
    system("pause");
    return 0;
}
