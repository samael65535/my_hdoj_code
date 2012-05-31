#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
  int T;
  int N;
  scanf("%d", &T);
  while(T--){
    int sum=1;
    int i=2;
    scanf("%d", &N);
    int tmp = (int)sqrt(N);
    for(i=2; i<=tmp; i++){
      if(N%i == 0){
	/* N/i也一定为约数 */
	sum+=i;
	/* i*i=n 会多加一次 不能是n/i==i 可能会是整数?*/
	if(i*i != N)
	  sum+=N/i;
      }
    }
    printf ("%d\n", sum);
  }
  return 0;
}
 
