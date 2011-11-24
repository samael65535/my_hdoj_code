#include<stdio.h>
int main(int argc, char *argv[])
{
  int str[1005];
  int n, i;
  while(scanf("%d", &n) != EOF){
    for(i=0; i<n; i++){
      scanf("%d", &str[i]);
    }
    for(i=0; i<n; i++){
      printf ("%c",str[i]);
    }
  }
  return 0;
}
