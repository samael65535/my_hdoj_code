#include <stdio.h>
#define MAX 50000
/* 可以每一位不只存一个数可以存100 10000之类的, 但要注意0的个数 */
int main(int argc, char *argv[])
{
  short num[MAX];
  int n;
  int i, j, t=0;
  while(scanf("%d", &n) != EOF){
    for(i = MAX-1; i>=0; i--){
      num[i] = -1;
    }
    if(n == 0){
      printf ("1\n");
    }else{
      num[0] = 1;
      for(i=2; i<=n; i++){
	for(j=0; j<MAX; j++){
	  if(num[j] < 0) break;
	  t = num[j]*i + t;
	  if(t>9){
	    num[j] = t%10;
	  }else{
	    num[j] = t;
	  }
	  t = t/10;
	}
	while(t != 0){
	  num[j++] = t%10;
	  t /= 10;
	}
      }
      for(i = MAX-1; i>=0; i--){
	if(num[i] >= 0){
	  printf ("%d", num[i]);
	}
      }
      printf ("\n");
    }
  }
  return 0;
}
