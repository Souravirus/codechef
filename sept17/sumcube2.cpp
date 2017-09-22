#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int lli;
using namespace std;
lli dfs(map<lli, set<int> > mymap, lli *dp, lli n, lli ind)
{
    lli count=0;
    for(int i=ind+1;i<=n; i++)
    {
        if(mymap.find(ind)!=mymap.end())
        {
            if(mymap[ind].find(i)!=mymap[ind].end())
            {
                cout<<"ind"<< ind<<" i"<<i<<endl;
                count+=1;
                count=count%mod;
            }
        }
        if(dp[i]==-1)
        {
            cout<<"in dp -1"<<endl;
            count+=dfs(mymap, dp, n, i);
            count=count%mod;
            dp[i]=count;
        }
        else
        {
            count+=dp[i];
            count=count%mod;
        }
    }
    dp[ind]=count;
    cout<<" for ind"<<ind<<" count"<<count<<endl;
    return count;
}

int main()
{
    int T;
    cin>>T;
    lli n, m, k;
    while(T--)
    {
        cin>>n>>m>>k;
        map<lli, set<int> > mymap;
        lli u, v;
        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            set<lli> s;
            if(u>v)
            {
                lli temp=u;
                u=v;
                temp=u;
            }
            mymap[u].insert(v);
        }
        lli dp[n];
        for(int i=1; i<=n; i++)
            dp[i]=-1;
        lli ans=0;
        for(lli i=1; i<=n; i++)
        {
            ans+=dfs(mymap, dp, n, i); 
        }
        cout<<"elements in dfs"<<endl;
        for(lli i =1; i<=n; i++)
            cout<<"for "<<i<<" "<<dp[i]<<endl;
        ans-=n;
        ans%=mod;
        cout<<ans;
    }
}
