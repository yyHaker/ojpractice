/**
 *   > File Name: mappractice.cpp   学习使用map
 *   > Author: yyHaker
 *   > Created Time: 2017/6/4
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<map>
#include<string>
using namespace std;

char str[25],s[25];
int main(){
    map<string,string> m;
    map<string,string> ::iterator ite;   //声明一个迭代器
    string str1;
    char ch;
    scanf("%s",str);
    while(scanf("%s",str)!=EOF){
        if(!strcmp(str,"END")){
            break;
        }
        scanf("%s",s);
        m[s]=str;          //把英文当做值，火星文当做键
    }
    //处理第二段
    scanf("%s",str);
    getchar();
    str1.clear();
    while(str1!="END"){
        scanf("%c",&ch);   //以单个字符输入，满足条件时
        if(ch>='a'&&ch<='z'){
            str1+=ch;      //压入string这样的字符数组中
        }else{
            if(ch>='A'&&ch<='Z') break;     //出现大写字母立刻退出
            ite=m.find(str1);  //通过键值找到映射值
            if(ite!=m.end())  cout<<ite->second;  //如果有则输出
            else cout<<str1;
            printf("%c",ch);  //输出空格等无关字符
            str1.clear();
        }
    }
    return 0;
}
