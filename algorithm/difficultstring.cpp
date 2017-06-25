/**
 *   > File Name: difficultstring.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/18
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAXN  80

int S[MAXN];   //存储相应字符(相对于A的位置)
int n,L;              //n表示串长度，L表示所包含字符种类
int dfs(int cur){
    if(cur==n-1){
        for(int i=0;i<n;i++){
           printf("%c",'A'+S[i]);         //输出方案
        }
        cout<<endl;
        return 0;
    }
    for(int i=0;i<L;i++){    //依次填充字符
        S[cur]=i;
        int ok=1;
        for(int j=1;j*2<=cur+1;j++){           //依次判断长度为2*j的后缀是否前半部分等于后半部分
             int equal=1;
            for(int k=0;k<j;k++){
                if(S[cur-k]!=S[cur-j-k]){
                    equal=0;
                    break;
                }
            }
            if(equal){   //方案不合法跳出循环
                ok=0;
                break;
            }
        }
        if(ok){
            if(!dfs(cur+1)) return 0;          //已经找到直接退出即可
        }
    }
    return 1;
}

int main(){
    cin>>n;
    cin>>L;
    dfs(0);

    system("pause");
    return 0;
}
