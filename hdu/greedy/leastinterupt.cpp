/**
 *   > File Name: leastinterupt.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 *   思路：对于每一个导弹，询问之前的系统能不能放，若不能放增加新系统；否则放到最小的那个系统里
 *   (超时)
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10005

int main(){
    int n;
    int sys[MAXN];  //存储之前系统最小高度的炮弹
    int map[MAXN];  //存储n个炮弹的高度
    while(scanf("%d",&n)){

        memset(sys,0,sizeof(sys));
        memset(map,0, sizeof(map));
        for(int i=0;i<n;i++){
            scanf("%d",&map[i]);
        }
        int sum=0;  //系统个数
        int flag;
        for(int i=0;i<n;i++){
            sort(sys,sys+sum);  //从小到大排序
            flag=0;
            for(int j=0;j<sum;j++){  //询问之前的系统能不能放
                if(sys[j]>=map[i]){
                  sys[j]=map[i];
                    flag=1;
                    break;
                }
            }
            if(flag==0){  //不能放，增加新系统
                sys[sum]=map[i];
                sum+=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
