#include<stdio.h>
#include<math.h>
double fun2(double x, double y)
{
  return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-x*y;
}
double fun(double x, double y)
{

  return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
}
int main(int argc, char *argv[])
{
  int T;
  scanf("%d",&T);
  while(T--){
    double Y, x, temp;
    double l=0, r=100, m;
    scanf("%lf", &Y);
    if(fun(100,Y)<=0){
      printf ("%.f\n",fun2(100, Y));
      continue;
    }
    while(r-l>1e-8){
      m=(l+r)/2;
      if(fun(m,Y)<0)  l=m;
      else r=m;
      /* printf ("%.4f\n",fun(m,Y)); */
    }
    printf ("%.4f\n",fun2(m,Y));
  }
  return 0;
}
