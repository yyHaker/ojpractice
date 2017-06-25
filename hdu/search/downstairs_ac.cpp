/**
 *   > File Name: downstairs_ac.cpp 诡异的楼梯问题
 *   > Author: yyHaker
 *   > Created Time: 2017/6/8
 *   实现的思路很巧妙，没有使用优先级队列，但能bfs完所有路径并找出最短路径
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 21
using namespace std;

int row, col, ans;
int dir[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
char graph[MAX][MAX];
int status[MAX][MAX];

struct Node{
    int x, y;
    int step;
} init;

bool is_ok(struct Node node){
    //走过的点可以再走，前提是步数必须比以前小        status[node.x][node.y]存储以前的步数,为0表示当前节点没有被访问           node.step存储当前的步数
    if (node.x < 0 || node.x >= col || node.y < 0 || node.y >= row || graph[node.y][node.x] == '*' || (status[node.y][node.x] && status[node.y][node.x] <= node.step))
        return false;
    return true;
};

bool bfs(struct Node init){
    struct Node curr, next;
    queue<Node>Queue;
    Queue.push(init);
    status[init.y][init.x] = 1;    //置改点已访问
    while (!Queue.empty()){
        curr = Queue.front(); Queue.pop();
        if (graph[curr.y][curr.x] == 'T') ans = min(ans, curr.step);
        for (int i = 0; i < 4; i++){
            next.x = curr.x + dir[i][0], next.y = curr.y + dir[i][1], next.step = curr.step + 1;
            if (graph[next.y][next.x] == '|'){
                if (next.x == curr.x && ((curr.step & 1) == 1))   //curr.step为奇数，梯子方向变化(Harry登上楼梯并经过楼梯到达对面的整个过程只需要一分钟)
                    next.step++; //y轴走，梯子不在|
                if (next.y == curr.y && ((curr.step & 1) == 0))
                    next.step++; //x轴走，梯子在|
                next.x += dir[i][0], next.y += dir[i][1];
            } else if (graph[next.y][next.x] == '-'){
                if (next.x == curr.x && ((curr.step & 1) == 0))
                    next.step++; //y轴走，梯子在-
                if (next.y == curr.y && ((curr.step & 1) == 1))
                    next.step++; //x轴走，梯子不在-
                next.x += dir[i][0], next.y += dir[i][1];
            }
            if (!is_ok(next)) continue;
            status[next.y][next.x] = next.step;      //记录步数
            Queue.push(next);
        }
    }
    return false;
}

int main(){
#ifdef _DEBUG
    freopen("f:\\1024.txt", "r", stdin);
#endif
    while (scanf("%d %d", &row, &col) != EOF){
        ans = 0x3f3f3f3f;
        memset(status, 0, sizeof(status));   //置所有节点没有被访问
        for (int i = 0; i < row; i++){
            scanf("%s", graph[i]);
            for (int j = 0; j < col; j++){
                if (graph[i][j] == 'S'){
                    init.x = j, init.y = i;
                    init.step = 0;
                }
            }
    }
        bfs(init);
        printf("%d\n", ans);
    }
    return 0;
}
