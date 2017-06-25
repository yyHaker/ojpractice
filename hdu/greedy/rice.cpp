/**
 *   > File Name: rice.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct rice{
    int price;
    int weight;
};

bool cmp(rice a,rice b){
    return a.price<b.price;
}

int main(){
    int C;
    int n,m;
    rice r[1010];
    scanf("%d",&C);
    while(C--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&r[i].price,&r[i].weight);
        }
        sort(r,r+m,cmp);  //按照价格从小到大排序

        int res=n;
        double w=0;
        for(int i=0;i<m;i++){
            if(res-r[i].price*r[i].weight>0){
                w+=r[i].weight;
                res-=r[i].price*r[i].weight;
            }else{
                w+=res/(r[i].price+0.0);
                break;
            }
        }
        printf("%.2f\n",w);
    }

    return 0;
}
