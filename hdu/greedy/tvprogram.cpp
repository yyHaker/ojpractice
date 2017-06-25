/**
 *   > File Name: tvprogram.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/19
 *   思路：每次看能否完整的看最早结束的电视节目
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct program{
    int start;
    int end;
};

bool cmp(program a,program b){   //按照节目结束时间从小到大排序
    return a.end<b.end;
}

int main(){
    int n;
    program p[120];
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].start,&p[i].end);
        }
        //
        sort(p,p+n,cmp);
        int num=1;
        program t=p[0];
        for(int i=1;i<n;i++){
            if(p[i].start>=t.end){
                num++;
                t=p[i];
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
