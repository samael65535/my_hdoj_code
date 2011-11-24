// Author: Tanky Woo
// Blog:    www.WuTianQi.com
#include <iostream>
#include <cstdlib>
using namespace std;
 
int nCase, n;
 
 
typedef struct stick{
    int l;
    int w;
}Stick;
 
Stick stick[5005];
 
 
int cmp(const void *arg1, const void *arg2)
{
    Stick *v1 = (Stick*)arg1;
    Stick *v2 = (Stick*)arg2;
    if(v1->l != v2->l)
        return v1->l - v2->l;
    else
        return v1->w - v2->w;
}
 
int Solve()
{
    qsort(stick+1, n, sizeof(Stick), cmp);
    Stick pre;
    int cnt = 0;
    for(int i=1; i<=n; ++i)
        if(stick[i].l != 0 && stick[i].w != 0)
        {
            pre = stick[i];
            stick[i].l = stick[i].w = 0;
 
            for(int j=i+1; j<=n; ++j)
                if(stick[j].l>=pre.l && stick[j].w>=pre.w)
                {
                    pre = stick[j];
                    stick[j].l = 0;
                    stick[j].w = 0;
                }
            cnt++;
        }
    return cnt;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> nCase;
    while(nCase--)
    {
        cin >> n;
        for(int i=1; i<=n; ++i)
            cin >> stick[i].l >> stick[i].w;
        cout << Solve() << endl;
    }
}
