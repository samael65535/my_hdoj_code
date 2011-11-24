#include<stdio.h>
#define MAX 10
int main(int argc, char *argv[])
{
  char *in = "in";
  char *out = "out";
  char *fin = "FINISH";
  char *yes = "Yes.";
  char *no = "No.";
  int O1[MAX], O2[MAX];
  int n, i;
  while(scanf("%d", &n) != EOF){
    for(i = 1; i <= n; i++){
      scanf("%d", &O1[i]);
    }
    for(i = 1; i <= n; i++){
      scanf("%d", &O2[i]);
    }
  }
  return 0;
}
