#include<stdio.h>
#include<math.h>
int main()
{
  int m, n;
  while(scanf("%d%d", &m, &n)!=EOF){
    int t, sum1=0, sum2=0;
    if(n<m){
      t=n;n=m;m=t;
    }
    for(t=m; t<=n; t++){
      if(t%2) sum1+=t*t*t;
      else sum2+=t*t;
    }
    printf ("%d %d\n",sum2, sum1);
  }
}
