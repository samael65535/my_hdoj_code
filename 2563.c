#include<stdio.h>
long long num[22];
int main(int argc, char *argv[])
{
  int n;
  num[1]=3;
  for(n=2; n<21; n++){
    /* num[n]=num[n-1]+4*(n-1); */
    num[n]=num[n-2]+2*num[n-1];
  }
  scanf("%d", &n);
  while(n--){
    int c;
    scanf("%d", &c);
    printf ("%I64d\n", num[c]);
  }
  return 0;
}
