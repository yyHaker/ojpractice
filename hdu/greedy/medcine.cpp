/**
 *   > File Name: medcine.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/20
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int C;
    int n,V,W;
    int p[110];
    scanf("%d",&C);
    while(C--){
        scanf("%d%d%d",&n,&V,&W);
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }
        sort(p,p+n);
        double sum=0.0;
        int k=0;
        for(int i=0;i<n;i++){
            if((sum+p[i])<=(k+1)*W){
                sum+=p[i];
                k++;
            }
        }
        if(k==0) printf("0 0.00\n");
        else printf("%d %.2f\n",k*V,sum/(k*100));
    }
    return 0;
}