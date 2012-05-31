#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int a[152], b[152];
  int i,j,k=0;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for(i=2; i<151; i++){
    if(a[i]==0){
      b[k++]=i;
      for(j=2; j*i<151; j++)
	a[i*j]=1;
    }
  }
  int n;
  memset(a, 0, sizeof(a));
  a[0]=1;
  for(i=0; i<k; i++){
    for(j=0; j+b[i]<151; j++)
      a[j+b[i]]+=a[j];
  }
  scanf("%d", &i);
  while(i--){
    while(scanf("%d", &n)!=EOF){
      printf ("%d\n", a[n]);
    }
  }
  return 0;
}
