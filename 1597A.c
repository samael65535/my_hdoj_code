#include<stdio.h>
#include<math.h>
int main(){
    long long  x,n,y;
    int T;
//    freopen("a.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        x=sqrt((double)n*(double)2)+5;
        y=(x*(x+1))/2;
        while(y>n){
            x--;
            y=(x*(x+1))/2;
        }
        if(y==n)x=x%9;
        else      x=(n-y)%9;       
        if(x==0)printf("9\n");
        else printf("%I64d\n",x);
    }
    return 0;
}
