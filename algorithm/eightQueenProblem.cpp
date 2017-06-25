/**
 *   > File Name: eightQueenProblem.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/18
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAXN 40

int C[MAXN];          //第i行皇后存储在第j列
int n;                        //皇后个数（行数）
int tot=0;                 //统计解的个数
void search(int cur){
    if(cur==n) tot++;         //递归边界
    else{
        for(int i=0;i<n;i++){   //依次在cur行i列位置放皇后
           int  ok=1;        //标志能否按照当前方式放置皇后
            C[cur]=i;
            for(int j=0;j<cur;j++){   //检查是否与前面的皇后冲突
                if(C[cur]==C[j] || C[cur]-cur==C[j]-j || C[cur]+cur == C[j]+j){
                    ok=0;
                    break;
                }
            }
            if(ok) search(cur+1);     //如果合法继续递归
        }
    }
}
int main(){
   cin>>n;
    search(0);
    cout<<"tot="<<tot<<endl;

    system("pause");
    return 0;
}
