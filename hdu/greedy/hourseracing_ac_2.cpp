/**
 *   > File Name: hourseracing_ac_2.cpp  田忌赛马
 *   > Author: yyHaker
 *   > Created Time: 2017/6/17
 *   思路：贪心，依次将马速度排序（从大到小），如果田忌最快的马比齐王最快的马还快，直接比赛一场赢一局；
 *   否则，看最慢的马，如果田忌最慢的马比齐王最慢的马快，直接比赛一场赢一局；如果田忌最慢的马不比齐王最慢的马快，
 *        那么田忌用最慢的马去和齐王最快的马比赛一场，输一局；依次下去求解
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(int a,int b){
    return a>b;
}

int main(){
    int a[1005],b[1005];
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        int TFirst=0,QFirst=0;
        int TEnd=n-1,QEnd=n-1;
        int win=0;
        while(n--){
            if(a[TFirst]>b[QFirst]){ //田忌最快的马比齐王最快的快,直接比较赢一局
                TFirst++,QFirst++;
                win++;
            }else if(a[TEnd]>b[QEnd]){  //田忌最慢的马比齐王最慢的快,直接比较赢一局
                TEnd--,QEnd--;
                win++;
            }else if(a[TEnd]<b[QFirst]){ //用田忌最慢的马与齐王最快的马比 ,输一局
                TEnd--,QFirst++;
                win--;
            }
            //平局直接过
        }
        printf("%d\n",win*200);
    }
}
