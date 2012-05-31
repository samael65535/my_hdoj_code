#include<stdio.h>
int main(int argc, char *argv[])
{
  int m, n;
  while(scanf("%d%d", &m, &n) != EOF){
    int t = m<n?m:n;
    int s = m>n?m:n;
    int i;
    if(m==n || t==1) printf ("%d\n", s);
    else{
      for(i=2;i<=s;i++){
	if(t*i % s == 0) break;
      }
      printf ("%d\n", t*i);
    }
  }
  return 0;
}
