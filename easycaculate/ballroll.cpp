/**
 *   > File Name: ballroll.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/15
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){
    int D,I;
    int k;
    while(scanf("%d %d",&D,&I) == 2){
        int s[1<<D];
        memset(s,0,sizeof(s));   //初始化开关，0表示关闭，1表示打开
        for(int i=1;i<=I;i++){   //连续让I个小球下落
             k=1;
            for(int j=1;j<=D-1;j++){ //每个小球最多下降D-1次
                int m=k;
                k= s[k] ? 2*k+1 : 2*k;
                s[m]=!s[m];
            }
        }
        printf("%d\n",k);
    }
    system("pause");
    return 0;
}
