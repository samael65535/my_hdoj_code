#include<stdio.h>
int main()
{ 
  int a=8, b=5;
  printf ("%d\n", a%b);
  printf ("%d\n",(-a)%b);
  printf ("%d\n",a%(-b));
  printf ("%d\n",(-a)%(-b));
  return 0;
}