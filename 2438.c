#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
#define  INF 0.0000001  
double x, y,l,d;
double cal(double i)
{
  return -(x-l*sin(i)-d/cos(i))/tan(i);
}
void fun()
{
  double left=0, right=PI/2.0, mid, mmid; /* PI的取值与别人的程序不一样 */
  while(right-left>INF){
    mid=(left+right)/2.0;
    /* mmid=(left+mid)/2.0; */
    mmid=(mid+right)/2.0;
    if(cal(mid)>cal(mmid))
      right=mmid;
    else
      left=mid;
  }
  if(cal(left)<y) printf ("yes\n");
  else printf ("no\n");
}
int main()
{	
  while(scanf("%lf%lf%lf%lf",&x,&y,&l,&d)!=EOF){
    if(d>=x||d>=y) printf ("no\n");
    else fun();
  }
  return 0;
}
