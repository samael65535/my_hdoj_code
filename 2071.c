#include<stdio.h>
int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    int n, i;
    float num[105], max=0.0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%f", &num[i]);
      max=max<num[i]?num[i]:max;
    }
    printf ("%.2f\n", max);
  }
  return 0;
}

