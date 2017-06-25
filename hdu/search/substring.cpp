/**
 *   > File Name: substring.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/6/9
 *   1.学会用c++的string类型  string.length()   string.substr(i,j)
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[110];
int t;
int cmp(const string& a,const string& b){
    return a.length()<b.length();
}

int dfs(string now,string rev,int len){
    for(int i=1;i<t;i++){
        int sign=0;
        for(int j=0;j+len<=str[i].length();j++){
            string sub=str[i].substr(j,len);// 返回从j开始长度为len的字符串
            if(sub==now||sub==rev){
                sign=1;
                break;  //找到就继续判断下一个字符串
            }
        }
        if(!sign) return 0;   //有一个字符串不满足就退出
    }
    return len;
}


int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>str[i];
        }
        sort(str,str+t,cmp);
        int len=str[0].length();
        int max=0;
        for(int i=len;i>=1;i--){
            for(int j=0;j+i<=len;j++){
                string now=str[0].substr(j,i);   //substr(j,i)从j开始长度为i的子串
                string rev=now;
                reverse(rev.begin(),rev.end());
                int ma=dfs(now,rev,i);
                if(ma>max) max=ma;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
