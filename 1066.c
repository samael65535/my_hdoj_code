#include <stdio.h>
int main(int argc, char *argv[])
{
  long long n;
  while(scanf("%lld", &n) != EOF){
    if(n==0 || n==1) printf ("0\n");
    else{
      long long i, k=1;
      for(i=2; i<=n; i++){
	k=k*i;
	if(k*i%10==0){while(k%10==0){k=k/10;}}
	k=k%10;
	printf ("%lld     %lld\n", k, i);

      }
      /* printf ("%lld     %lld\n", k, i); */
    }
  }
  return 0;
}

