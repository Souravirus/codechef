#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int k, a, b;
		cin>>k>>a>>b;
		if(a>b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		if(k%2==0)
		{
			if(b-a==k/2)
			{
				cout<<"0"<<endl;
			}
			else if(b-a<k/2)
			{
				cout<<b-a-1<<endl;	
			}
			else
				cout<<k-(b-a)-1<<endl;
		}
		else
		{
			if(b-a<=k/2)
			{
				cout<<b-a-1<<endl;	
			}
			else
				cout<<k-(b-a)-1<<endl;

		}
	}
	return 0;
}
