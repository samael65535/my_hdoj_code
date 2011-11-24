#include<stdio.h>
#include<string.h>
#define N 1005
main()
{
  int a[N], b[N], sum[N], t=0;		
  int i = 0, k = 0;
  char sa[N], sb[N];
  int length;
  int n, s=1;
  while(scanf("%d", &n)!=EOF){
    while(s<=n){
      for(i = 0; i < N ; i++){
	a[i] = 0;
	b[i] = 0;
	sa[i] = '0';
	sb[i] = '0';
      }
      scanf("%s", sa);
      scanf("%s", sb);
      printf ("Case %d:\n", s);
      for(i = N-1-strlen(sa)+1, k=0; i<=N-1; i++, k++){
	a[i] = sa[k]-'0';
	printf ("%d", a[i]);
      }
      printf(" + ");
      for(i = N-1-strlen(sb)+1, k=0; i<=N-1; i++, k++){
	b[i] = sb[k]-'0';
	printf ("%d", b[i]);
      }
      printf(" = ");
      length = strlen(sa)>strlen(sb)?strlen(sa):strlen(sb);
      for(i=N-1; i >= N-1-length; i--){
	sum[i] = t+a[i]+b[i]>=10?(a[i]+b[i]+t)%10:a[i]+b[i]+t; 
	t = a[i]+b[i]+t>=10 ? 1 : 0;
      }
      sum[i] = t==0?0:1;
      if(sum[N-1-length] != 0) printf("%d", sum[N-1-length]);
      for (i = N-1-length+1; i<=N-1; i++){
	printf ("%d",sum[i]);
      }
      s++;
      t = 0;
      if(s<=n) printf ("\n");
      printf("\n");
    }
    s = 1;
  }
}
