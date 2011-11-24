#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        char a[1001];
        cin.getline(a,1001);
        int n=strlen(a);
        for(int i=0;i<n;i++)
        {
            int k=i;
            while(a[k]!=' '&&a[k]!='\0') k++;
            for(int j=k-1;j>=i;j--)
              cout<<a[j]; i=k;
             if(a[i]==' ') cout<<' ';
        }
        cout<<endl;
    }
}
