#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);
  while(T--){
    double Y;
    double left=0.0, right=100.0, sum, temp, mid;
    int flag=0;
    scanf("%lf", &Y);
    while(left<right){
      mid = (left+right)/2;
      sum = 8*pow(mid, 4) + 7*pow(mid, 3) + 2*pow(mid, 2) + 3*mid + 6;
      if(fabs(sum-Y)<1e-6){ flag=1;break;}
      if(sum>Y) right=mid;
      else left=mid;
      /* printf ("%.4f   %.4f   %.4f\n", sum, mid, Y); */
    }
    if(flag) printf ("%.4f\n",mid);
    else printf ("No solution!\n");
  }
  return 0;
}
