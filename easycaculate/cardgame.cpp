/**
 *   > File Name: cardgame.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/14
 */
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    queue<int> q;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(!q.empty()){
        printf("%d ",q.front());
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}
