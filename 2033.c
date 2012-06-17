#include<stdio.h>
int main()
{
  int a[3], b[3];
  int n;
  scanf("%d", &n);
  while(n--){
    int i;
    for(i=0; i<3; i++)
      scanf("%d", &a[i]);
    for(i=0; i<3; i++)
      scanf("%d", &b[i]);
    for(i=2; i>0; i--){
      int c=a[i]+b[i];
      a[i]=c%60;
      a[i-1]+=c/60;
    }
    a[0]+=b[0];
    printf ("%d %d %d\n",a[0], a[1], a[2]);
  }
}
