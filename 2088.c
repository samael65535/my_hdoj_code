#include <stdio.h>
int main(int argc, char *argv[])
{
  int sum = 0;
  int stack[101];
  int n, aver, i, f, k;
  while(scanf("%d", &n) != EOF && n>0){
    if(f) printf ("\n");
    f = 1;
    for(i=0; i<n; i++){
      scanf("%d", &stack[i]);
      sum += stack[i];
    }
    aver = sum / n;
    for(i=0; i<n; i++){
      if(stack[i] < aver)
	k += aver - stack[i];
      stack[i] = 0;
    }
    printf ("%d\n", k);
    k = 0;
    sum = 0;
    aver = 0;
  }
  return 0;
}
