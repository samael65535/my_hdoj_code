#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005
int main(int argc, char *argv[])
{
  int a[N], b[N], sum[N], t=0;		/* t表示进位临时值 */
  int i = 0, k = 0;
  char sa[N], sb[N];
  int length;
  int n, s=1;
  scanf("%d", &n);
  while(s<=n && n<=20 && n>=1){
    for(i = 0; i < N ; i++){
      a[i] = 0;
      b[i] = 0;
      sa[i] = '0';
      sb[i] = '0';
    }
    scanf("%s", sa);
    scanf("%s", sb);
    printf ("Case %d:\n", s);	/* 注意是Case 不是CASE */
    for(i = N-1-strlen(sa)+1, k=0; i<=N-1; i++, k++){ /* 把字符串变为粒数组存储,从数据尾进行存储 */
      a[i] = sa[k]-48;
      printf ("%d", a[i]);
    }
    printf(" + ");
    for(i = N-1-strlen(sb)+1, k=0; i<=N-1; i++, k++){
      b[i] = sb[k]-48;
      printf ("%d", b[i]);
    }
    printf(" = ");
    length = strlen(sa)>strlen(sb)?strlen(sa):strlen(sb);
    for(i=N-1; i >= N-1-length; i--){
      sum[i] = t+a[i]+b[i]>=10?(a[i]+b[i]+t)%10:a[i]+b[i]+t; /* 关于进位的处理,注意连续进位 */
      t = a[i]+b[i]+t>=10 ? 1 : 0;
      printf ("%d   %d\n", sum[i], t); 
    }
    sum[i] = t==0?0:1; /* 考虑最后一位的进位 */
    if(sum[N-1-length] != 0) printf("%d", sum[N-1-length]);
    for (i = N-1-length+1; i<=N-1; i++){
      printf ("%d",sum[i]);
    }
    s++;
    t = 0;
    if(s<=n) printf ("\n");
    printf("\n");
  }
  return 0;
}
