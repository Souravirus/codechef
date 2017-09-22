#include<bits/stdc++.h>
#define lli long long int
#define mod  1000000007
using namespace std;
map<int, set<int> > :: iterator itm;
set<int>:: iterator its;

int findTotal(int , int)
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, m, k;
    cin>>T;

    while(T--)
    {
        cin>>n>>m>>k;  
        map<lli, set<lli> >mapmax;
        map<lli, set<lli> >mapmin;
        lli u, v, count=0;
        lli sum=0;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            if(u>v)
            {
                lli temp=u;
                u=v;
                v=temp;
            }
            mapmax[u].insert(v);
            mapmin[v].insert(u);
            count++;
        }
        sum+=pow(count, k);
        sum=sum%mod;
        for(int i=1; i<=n; i++)
        {
            int icount=0;
            if(mapmax.find(i)!=mapmax.end())
                icount=count-mapmax[i].size();
            if(mapmin.find(i)!=mapmin.end())
                icount=count-mapmin[i].size();
            sum+=pow(icount, k);
            sum=sum%mod;
            for(int j=i; j<=n; j++)
            {
                int tempcount=0;
                if(mapmax.find(j)!=mapmax.end())
                    tempcount=icount-mapmax[i].size();
                if(mapmin.find(j)!=mapmin.end())
                    tempcount=icount-mapmin[i].size();
                sum=pow(tempcount, k);
                sum=sum%mod;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
