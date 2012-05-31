#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  char name[11];
  int q;
  int cost;
};
int cmp(const void* a, const void* b) /* 三级比较,注意排序规则 */
{
  struct student* s1=(struct student*) a;
  struct student* s2=(struct student*) b;
  if(s1->q == s2->q){
    if(s1->cost == s2->cost)
      return strcmp(s2->name, s1->name)<0;
    return s1->cost - s2->cost;
  }
  return s2->q - s1->q;
}
int main(int argc, char *argv[])
{
  int n, m, j=0;
  struct student students[10000];
  scanf("%d%d", &n, &m);
  while(scanf("%s",students[j].name)!=EOF){
    int i, a=0, b=0, sum=0, questions=0;
    for(i=0; i<n; i++){
      scanf("%d(%d)", &a, &b);	/* 输入可以默认 */
      if(a<=0) continue;
      else{
	questions++;
	sum += a+b*m;
	b=0;
      }
    }
    students[j].q = questions;
    students[j].cost = sum;
    j++;
  }
  qsort(students, j, sizeof(students[0]), cmp); /* 不加1 */
  for(m=0; m<j; m++)
    printf("%-10s %2d %4d\n",students[m].name, students[m].q, students[m].cost);
  return 0;
}
