/**
 *   > File Name: binarytreesearch.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/16
 */
#include <iostream>
#include <cstdio>
#include <mem.h>
#include <cstdlib>

using namespace std;

#define MAXN 200

typedef struct Tnode{
    int have_value;  //是否被赋值过
    int v;
    struct Tnode *left, *right;
}Node;
char s[MAXN+10];
int failed=0;
int ans[MAXN];     //节点的输出序列
Node* root;  //二叉树的根节点

Node *newnode(){   //申请新节点
    Node *u=(Node*)malloc(sizeof(Node));
    if(u!=NULL){
        u->have_value=0;
        u->left=NULL;
        u->right=NULL;
    }
    return u;
}
void addnode(int v,char*s){
    int n=strlen(s);
    Node *u=root;                         //从根节点往下走
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(u->left==NULL) u->left=newnode();    //节点不存在填充新节点
            u=u->left;
        }else if(s[i]=='R'){
            if(u->right==NULL) u->right=newnode();
            u=u->right;
        }
    }
    if(u->have_value) failed=1;  //已经赋值表明输入有误
    u->v=v;
    u->have_value=1;
}
int read_input()
{
    failed=0;
    root = newnode();    //创建根节点
    for( ; ; ){
        if(scanf("%s",s) != 1) return 0;   //整个输入读入
        if(!strcmp(s,"()"))  break;         //读入结束标志
        int v;
        sscanf(&s[1],"%d",&v);                //读入节点值
        addnode(v,strchr(s,',')+1);          //查找逗号，然后插入节点
    }
}
int bfs(){
    int n=0;
    int front=0,rear=1;   //该队列q队首存放元素，队尾不存放元素
    Node* q[MAXN];
    q[0]=root;
    while(front<rear){
        Node* u=q[front++];    //出队列
        if(!u->have_value)  return 0;   //该节点没有赋值直接返回

        ans[n++] = u->v;
        cout<<u->v<<" ";
        if(u->left!=NULL) q[rear++]=u->left;
        if(u->right!=NULL) q[rear++]=u->right;
    }
    return 1;  //正常结束
}
//释放二叉树的空间
void remove_tree(Node* u){
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    free(u);
}
int main(){
    read_input();
    bfs();
    remove_tree(root);
    system("pause");
    return 0;
}

