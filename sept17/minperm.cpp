#include<bits/stdc++.h>
using namespace  std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n;
    cin>>t;
    while(t--)
    {
       cin>>n;
       int a[n+1];
       if(n%2==0)
       {
           for(int i=1; i<=n;i+=2)
           {
               a[i]=i+1;
               a[i+1]=i;
           }
       }
       else
       {
           for(int i=1; i<=n-3; i+=2)
           {
                a[i]=i+1;
                a[i+1]=i;
           }
           a[n-2]=n-1;
           a[n-1]=n;
           a[n]=n-2;
       }
       for(int i=1; i<=n; i++)
           cout<<a[i]<<" ";
       cout<<endl;
    }
    return 0;
}
