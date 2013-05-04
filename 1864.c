#include <stdio.h>
#include <string.h>
#define MAX(x, y) (x > y ? x : y)
/**
 *现有一笔经费可以报销一定额度的发票。
 *允许报销的发票类型包括买图书（A类）、文具（B类）、差旅（C类），要求每张发票的总额不得超过 * 1000元，
 *每张发票上，单项物品的价值不得超过600元。现请你编写程序，在给出的一堆发票中找出可以报销的、不超过给定额度的最大报销额。
 *
 * 01 背包 注意单项物品不能超过600元, 总额不超过1000元
 */

struct item
{
float value;
int cost;
};

struct item items[1000];
float f[10000];

int main()
{
  int n;
  float q;
  while(scanf("%f%d", &q, &n) != EOF && n != 0){
    memset(items, 0, sizeof(items));
    memset(f, 0, sizeof(f));
    int i, m, j, t = 1;
    for(i = 1; i <= n; i++){
      scanf("%d", &m);
      char ch1, flag = 1;
      float v = 0.0, a=0.0, b=0.0, c=0.0;
      for(j = 1; j <= m; j++){
        scanf(" %c:%f", &ch1, &v);
        if(ch1 == 'A')
          a += v;
        else if(ch1 == 'B')
          b += v;
        else if(ch1 == 'C')
          c += v;
        else
          flag=0;
      }
      if(a>600 || b>600 || c>600 || a+b+c>1000)
        flag=0;
      if(flag != 0){
        items[t].value = a + b + c;
        items[t++].cost = m;
      }
    }
    float tmp, ans = -1.0;
    for(i = 1; i <= t; i++){
      for(j = n; j > 0; j--){
        tmp = f[j-1] + items[i].value;
        if(tmp <= q){
          f[j] = MAX(tmp, f[j]);
          ans = MAX(ans, f[j]);
        }
      }
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
