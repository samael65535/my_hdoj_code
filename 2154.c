#include<stdio.h>
/*   设走i步，则f[i]=2^i-f[i-1] 

       因为第i次比第i-1次多走一步，而当走i-1步时，达到B或C，再走一步即可达到A。

       走i步共有2^i中走法，走i步的所有走法数减去走i-1步达到A的景象数易得为走i步到A的走法总数。 */
int main(int argc, char *argv[])
{
  int i, a[1005]; 
  a[1]=0;
  a[2]=2;
  for(i=3; i<1001; i++){
    a[i] = (a[i-1]+2*a[i-2]) % 10000;
  }
  while(scanf("%d", &i)!=EOF && i){
    printf ("%d\n", a[i]);
  }
  return 0;
}

