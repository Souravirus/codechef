#include<bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int qual[n][m];
		ulli minSalary[n];
		ulli offered[m], maxJob[m];
		qual[n][m];
		for(int i=0; i<n; i++)
		{
			cin>>minSalary[i];
		}
	//	cout<<"after minSalary"<<endl;
		for(int i=0; i<m; i++)
		{
			cin>>offered[i]>>maxJob[i];
		}
	//	cout<<"after offered"<<endl;
		string s;
		for(int i=0; i<n; i++)
		{
			cin>>s;
			for(int j=0; j<m; j++)
			{
				qual[i][j]=s[j]-48;
			}
		}
	//	cout<<"after qual"<<endl;
	//	cout<<"qual printing"<<endl;
		/*for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cout<<qual[i][j];
			}
			cout<<endl;
		}*/
		int obtained[n];
		int company[m]={0};
		ulli tsum=0;	
		int student=0;
		for(int i=0; i<n; i++)
		{
			ulli max=0;
			int flag=0;
			for(int j=0; j<m; j++)
			{
			//	cout<<"hello"<<endl;
				if(qual[i][j]==1)
				{
					if(offered[j]>=max)
					{
						if(minSalary[i]<=offered[j] && maxJob[j]>0)
						{
							max=offered[j];
							obtained[i]=j;
							flag=1;
						}
					}
				}
			}
			if(flag==1)
			{
				company[obtained[i]]=1;
				maxJob[obtained[i]]--;
				tsum+=max;
				student++;
			}
		}
	//	cout<<"after  final "<<endl;
		int compsum=0;
		for(int i=0;i<m; i++)
		{
			if(company[i]==1)
				compsum++;
		}
		int left=m-compsum;	
		cout<<student<<" "<<tsum<<" "<<left<<endl;
	}
	return 0;
}
