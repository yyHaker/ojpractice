/**
 *   > File Name: eightnumber.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/19
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <stdlib.h>

using namespace std;

typedef int State[9];      //定义“状态”  类型
const int MAXSTATE = 1000000;
State st[MAXSTATE],goal;     //状态数组队列，所有的状态都保存在这里
int dist[MAXSTATE];

const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

set<int> vis;
void init_lookup_table(){
 vis.clear();
}
int try_to_insert(int s){
 int v=0;
 for(int i=0;i<9;i++){
  v=v*10+st[s][i];
 }
 if(vis.count(v))  return 0;
 vis.insert(v);
 return 1;
}

//BFS返回目标状态在st数组下标
int bfs(){
 init_lookup_table();
 int front=1,rear=2;  //定义队列，队尾不存元素
 while(front<rear){
  State& s=st[front];  //定义队首的一个引用
  if(memcmp(goal,s,sizeof(s))==0) return front; //找到目标状态成功返回
  int z;
  for(z=0;z<9;z++){  //找到0的位置
   if(!s[z]) break;
  }
  int x=z/3,y=z%3;
  for(int d=0;d<4;d++){
   int newx=x+dx[d];
   int newy=y+dy[d];
   int newz=newx*3+newy;
   if(newx>=0&&newx<3&&newy>=0&&newy<3){  //如果移动合法
    State& t=st[rear];   //定义队尾的一个引用
    memcpy(t,s,sizeof(s));
    t[newz]=s[z];
    t[z]=s[newz];
    dist[rear]=dist[front]+1;  //更新新节点的距离值
    if(try_to_insert(rear)) rear++;    //如果成功插入查找表，修改队尾指针(入队列)
   }
  }
  front++;         //扩展完毕后再修改队首指针(出队列)
 }
 return 0;
}

int main(){
 for(int i=0;i<9;i++){   //起始状态
  scanf("%d",&st[1][i]);
 }
 for(int i=0;i<9;i++){   //目标状态
  scanf("%d",&goal[i]);
 }
 int ans=bfs();
 if(ans>0) printf("%d\n",dist[ans]);
 else printf("-1\n");
 system("pause");
 return 0;
}