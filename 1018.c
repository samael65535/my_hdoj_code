#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{

  int i, n, c;
  scanf("%d", &c);
  while(c--){
    while(scanf("%d", &n)!=EOF){
      double b=1.0;
      for(i=2; i<=n; i++){
	b+=(double)log10(i);
      }
      printf ("%d\n",(int)b);
    }
  }
  return 0;
}

