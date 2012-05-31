#include<stdio.h>
#include<math.h>
long long serach(long long p)
{
  long long s=(long long)sqrt((double)2*(double)p);
  /* if(p-(1+s)*s/2>0) */
  /*   return p-(1+s)*s/2; */
  /* else if(p-(1+s)*s/2<0) */
  /*   return p-(s-1)*s/2; */
  if((1+s)*s/2-p==0) return s;
  while((1+s)*s/2-p>0){
    s--;
  }
  return p-(1+s)*s/2;;
}
int main()
{
  int n;
  scanf("%d", &n);    
  while(n--){
    long long c;
    scanf("%I64d", &c);
    printf ("%I64d\n", serach(c)%9?serach(c)%9:9);
  }
  return 0;
}
