/**
 *   > File Name: alphresort.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/12
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//字符比较函数
int cmp_char(const void* _a,const void* _b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return *a-*b;
}

//字符串比较函数
int cmp_string(const void* _a,const void* _b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return strcmp(a,b);
}

//

int main(){
    char word[2000][10],sorted[2000][10];
    int n=0;
    for( ; ;){
        scanf("%s",word[n]);
        if(word[n][0]=='*') break;    //遇到结束标志退出循环
        n++;
    }
   //给所有单词排序
    qsort(word,n,sizeof(word[0]),cmp_string);
    for(int i=0;i<n;i++){
        strcpy(sorted[i],word[i]);
        //给每个单词排序
        qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
    }
    char s[10];
    while(scanf("%s",s)==1) {
        //给输入单词排序
        qsort(s,strlen(s),sizeof(char),cmp_char);
        int found=0;
        for(int i=0;i<n;i++){
            if(strcmp(sorted[i], s)==0){
                found=1;
                printf("%s ",word[i]);
            }
        }
        if(!found) printf(":(");
        printf("\n");
    }
   return 0;
}
