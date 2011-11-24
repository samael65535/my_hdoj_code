#include<stdio.h>
int main(int argc, char *argv[])
{
  int e[101];
  int n, i;
  int time;
  while(scanf("%d", &n) != EOF && n>0){
    for(i=0; i<n; i++){
      e[i] = 0;
    }
    time = 0;
    for(i=1; i<=n; i++){
      scanf("%d", &e[i]);
      time += e[i]-e[i-1]>0 ? 6*(e[i]-e[i-1]) : 4*(e[i-1]-e[i]);
      time += 5;
    }
    printf ("%d\n", time);
  
  }
  return 0;
}
