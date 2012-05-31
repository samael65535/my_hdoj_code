#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
char a[10000], b[10000];
int main(int argc, char *argv[])
{
  memset(a,'0',10000);
  memset(b,'0',10000);

  int n, i;
  char t;

  while(t!=' '){
    t = getchar();
    if(t=='.'){ 
      continue;
    }
    a[i++] = t;
  }
  return 0;
}
