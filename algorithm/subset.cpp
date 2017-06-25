/**
 *   > File Name: subset.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/17
 */
#include <iostream>

using namespace std;

int a[20];
/*递归输出n以内所有的子集,其中cur为当前下标,初始值0*/
void print_subset(int n,int* a,int cur){
    for (int i=0;i<cur;i++)//每次递归输出当前子集,靠它来最后输出上一层指定的子集
        cout<<a[i]<<' ';
    cout<<endl;//以行分隔

    //找到当前子集首个值，因为按字典顺序输出，所以每次找到最小的元素，cur > 0，则minElem=a[cur-1]+1,否则为0
    int minElem = cur ? a[cur-1] + 1 : 0;

    //从子集第一个值开始遍历,先不看下面的print_subset(n,a,cur+1)，单看这for循环，
    //可知是将子集第一个值从头往后依次赋值为 minElem....n-1。
    //每次第一个值变化后递归设置下一个值(相当于下一层的第一个值)
    for (int i=minElem;i<n;i++) {
        a[cur]=i;
        //当前层子集第一个值
        //cur+1表示当前层值设置完毕，开始递归下一层，和前面步骤一样。
        //到达最后一层结束后return 到上一层，然后i++,a[cur]的值(首元素)改变，又反复递归下一层...
        print_subset(n,a,cur+1);
    }
}

int main(){
    int n ;
    while (cin>>n,n){
        print_subset(n,a,0);
    }
    return 0;
}
