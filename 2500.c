#include<stdio.h>
char *hdu="HDU";
int main()
{
  int i, j, k;
  int row, col;
  int r, c;
  scanf("%d", &i);
  for(j=1; j<=i; j++){
    scanf("%d", &k);
    row=k*3, col=k;
    for(r=1; r<=row; r++){
      for(c=1; c<=col; c++){
	printf("%s", hdu);
      }
      printf ("\n");
    }
  }
  return 0;
}
