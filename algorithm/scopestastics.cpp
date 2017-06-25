/**
 *   > File Name: scopestastics.cpp  二分查找求上下界可以很方便的求解范围统计问题
 *   > Author: yyHaker
 *   > Created Time: 2017/5/21
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int v[10000];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    sort(v,v+n);  //从小到大排序
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",upper_bound(v,v+n,b)-lower_bound(v,v+n,a));
    }
    system("pause");
    return 0;
}
