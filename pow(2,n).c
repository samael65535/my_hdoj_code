#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* cal(int k)
{
  int i, j=1, s, t = 0;
  char *sum = (char *)malloc(1000*sizeof(char)+1);
  sum[0] = '1';
  for(i = 1; i<=k; i++){
    for(s = 0; s < strlen(sum); s++){
      j = sum[s] - '0';
      j = j * 2 + t;
      t = j/10>0 ? 1 : 0;
      sum[s] = j%10 + '0';
    }
    if(t!=0){
      sum[s] = t + '0';
      t=0;
nnnn    }
  }
  for(i = strlen(sum); i>=0; i--){
    printf ("%c", sum[i]);
  }
  printf ("\n");
  return sum;
}
int main(int argc, char *argv[])
{
  int n;
  while(scanf("%d", &n) != EOF){
    cal((n-2)/2);
  }
  return 0;
}
