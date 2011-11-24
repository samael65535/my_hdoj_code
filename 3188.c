#include<stdio.h>
int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int a, b, c;
  while(n--){
    scanf("%d%d%d", &a, &b, &c);
    if(a==b || b==c || c==a)
      printf ("perfect\n");
    else if(a*a+b*b == c*c || b*b+c*c == a*a || a*a+c*c==b*b)
      printf ("good\n");
    else
      printf ("just a triangle\n");
  }
  return 0;
}
