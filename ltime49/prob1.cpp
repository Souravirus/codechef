#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli T, cost[27], presence[27];
	cin>>T;
	string s;
	while(T--)
	{
		for(int i=0; i<26; i++)
			presence[i]=0;
		for(int i=0; i<26; i++)
		{
			cin>>cost[i];
		}
		cin>>s;
		for(int i=0; i<s.length(); i++)
		{
			presence[s[i]-97]=1;
		}
		lli sum=0;
		for(int i=0; i<26; i++)
		{
			if(presence[i]==0)
			{
				sum+=cost[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
