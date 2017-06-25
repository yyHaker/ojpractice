/**
 *   > File Name: cyclestring.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/11
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MaxLen 80
int main(){
    char s[MaxLen];
    cin>>s;
    int len=strlen(s);
    for(int i=1;i<=len;i++){
        if(len%i==0){
            int k=1;  //标志i可以作为字符串的周期
            for(int j=i;j<len;j++){
                if(s[j]!=s[j%i]){
                    k=0;
                    break;
                }
            }
            if(k==1) {
                cout<<"最小周期:"<<i<<endl;
                break;
            }

        }
    }
    system("pause");
    return 0;
}
