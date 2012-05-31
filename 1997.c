#include<stdio.h>
#define MAX 65
int main()
{
  int T;
  int i,j,x,y,z,k,flag,n,t;
    int a[3][MAX];
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(i=0; i<3; i++){
      scanf("%d", &a[i][0]);
      for(j=1; j<=a[i][0]; j++){
	scanf("%d", &a[i][j]);
      }
    }
    flag=1;
    i=1;j=1;k=1;
    x=0;y=1;z=2;
    while(1){
      if(a[x][0]==n || a[z][0]==n) {flag=1;break;}

      if(a[y][0]>0 && a[y][j]==n){flag=0;break;}

      if(a[x][i]==n && a[x][0]>0){
	n--;
	a[x][0]--;
	i++;
	t=y;y=z;z=t;
	t=j;j=k;k=t;		/* 注意如果不像答案上的数组要交换 */
	continue;
      }

      if(a[z][0]>0 && a[z][k]==n){
	n--;
	a[z][0]--;
	k++;
	t=x;x=y;y=t;
	t=i;i=j;j=t;
	continue;
      }
    }
    if(flag) printf ("true\n");
    else printf ("false\n");
  }
  return 0;
}
