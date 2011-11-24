#include <stdio.h>
int a[1002][500] = {0};
int main()
{
  int i,j,k,n,m,t;
  a[0][0] = 0;a[1][0] = 0;a[2][0] = 1;a[3][0] = 1;
  for(i=4;i<=1000;i++)
    {  
      for(j=0;j<500;j++)
        {
	  a[i][j] += a[i-1][j] +a[i-2][j]*2;
	  if(a[i][j] > 9)
            {
	      a[i][j+1] = a[i][j] / 10;
	      a[i][j] = a[i][j] % 10;        //进位        
            }
        }
    }
  while (scanf("%d",&n)!=EOF)
    {
      int flag = 0;
      if (n == 1 || n == 0)
	{
	  printf("0\n");
	  continue;
	}
      for (i=500-1;i>=0;i--)
	{
	  if (a[n][i] != 0 || flag == 1)
	    {
	      flag = 1;
	      printf("%d",a[n][i]);
	    }
	}
      printf("\n");
    }
  return 0;
}
