#include<iostream>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
int re[40000];
void bigplus(int n)
{
    int i,flag=0;
    for(i=1;i<=re[0];i++)
    {
        re[i]=re[i]*n+flag;
        if(re[i]>99999){
            flag=re[i]/100000;
            re[i]%=100000;
        }
        else flag=0;
    }
    if(flag){ re[i]=flag;re[0]++;} // 如果这样要考虑有多少个0?re[0]存的是多少个0?
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF){
        re[0]=1;re[1]=1;
        for(i=2;i<=n;i++)
            bigplus(i);
        printf("%d",re[re[0]]);
        for(i=re[0]-1;i>=1;i--)
            printf("%05d",re[i]); // 5位一组
    }
    return 0;
}
