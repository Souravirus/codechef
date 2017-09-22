#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	string a, b;
	while(T--)
	{
		int ala[26]={0}, alb[26]={0};
		cin>>a;
		cin>>b;
		int count=0;
		for(int i=0; i<a.length(); i++)
		{
			ala[a[i]-97]++;
		}
		for(int i=0; i<b.length(); i++)
		{
			alb[b[i]-97]++;
		}
		count=0;
		for(int i=0; i<26; i++)
		{
	//		cout<<"for "<<i<<"ala"<<ala[i]<<"alb"<<alb[i]<<endl;
			if(ala[i]>=2 && alb[i]==0)
			{
	//			cout<<"hello"<<endl;
				count=2;
				break;
			}
			else if(ala[i]==1 && alb[i]==0)
			{
				count=1;
			}
		}
		if(count==1)
		{
			int flag=0;
			for(int i=0; i<26; i++)
			{
				if(alb[i]>=1 && ala[i]==0)
					flag=1;
			}
			if(flag==0)
				count=2;
		}
		if(count==0 || count==1)
			cout<<"B"<<endl;
		else 
			cout<<"A"<<endl;
	}
	return 0;
}
