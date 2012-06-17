#include<stdio.h>
int fun(int x)
{
  if(x==0) return 1;
  else{
    int i=1, y=1;
    for(i=1; i<=x; i++){
      y=y*i;
    }
  return y;
  }
}
int main()
{
  int i=0;
  printf("n e\n");
  printf("- -----------\n");
  printf ("0 1\n");
  printf ("1 2\n");
  printf ("2 2.5\n");
  double k=2.5;
  for(i=3; i<=9; i++){
    int j=0;
    k+=1.0/fun(i);
    printf ("%d %.9lf\n",i,k);
  }
}
