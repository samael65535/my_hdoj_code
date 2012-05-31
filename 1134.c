#include<stdio.h>
long long num[101]={0};
/* 加入大数的乘法 */
int main(int argc, char *argv[])
{

  num[0]=num[1]=1;
  int i, n;
  for(i=2; i<10; i++){
    int a;
    if((i-1)%2){
      for(a=0; a<(i-1)/2+1; a++){
	num[i]+=2*num[a]*num[i-1-a];
      }
    }else{
      for(a=0; a<(i-1)/2; a++){
	num[i]+=2*num[a]*num[i-1-a];
      }
      num[i]+=num[(i-1)/2]*num[(i-1)/2];
    }
    printf ("%d   %lld\n", i, num[i]);
  }
  while(scanf("%d", &n) != EOF && n!=-1){

    printf ("%lld\n",num[n]);
  }
  return 0;
}
