#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int flags=0, flago=0, prev;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int tsum=0;
		int bor=0;
		int sum=0;
		while(n--)
		{
			int a;
			cin>>a;
			prev=bor;
			bor=bor|a;
			sum+=a;
			if(sum<bor)
			{
				tsum+=prev;
				tsum+=a;
				bor=0;
				sum=0;
			}
		}
		tsum+=bor;
		cout<<sum<<endl;
	}
	return 0;
}
