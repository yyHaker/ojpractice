/**
 *   > File Name: ms.cpp
 *   > Author: yyHaker
 *   > Created Time: 2017/5/24
 */
#include <stdio.h>
int a[100010];
int main(){
    int T,N,i,cas=1;
    int start,end,temp,sum,max=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        start=end=temp=1;
        sum=0;
        max=-1001;
        for(i=1;i<=N;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            if(sum>max){
                max=sum;
                start=temp;
                end=i;
            }
            if(sum<0){
                sum=0;
                temp=i+1;
            }
        }
        printf("Case %d:\n",cas++);
        printf("%d %d %d\n",max,start,end);
        if(T>0)
            printf("\n");
    }
    return 0;
}

