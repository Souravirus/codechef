#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int lli;
using namespace std;
int main()
{
    int T;
    cin>>T;
    int n, m, k;
    while(T--)
    {
        map<int, vector<int> mymap;
        cin>>n>>m>>k;
        int sum=0; 
        int u, v;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v; 
            sum++;
            if(mymap.find(u)==mymap.end())
            {
                vector<int>vec;
                vec.push_back(v);
                mymap.insert(vec);
            }
            else
                mymap[u].push_back(u);
            if(mymap.find(v)==mymap.end())
            {
                vector<int>vec;
                vec.push_back(u);
                mymap.insert(vec);
            }
            else
                mymap[v].push_back(v);
        }
    }
    return 0;
}
