#include<bits/stdc++.h>
#define mod 1000000007
typedef long long int ulli;
using namespace std;
ulli arr[200][200][100];
ulli dfs(int a[], int n, int pos)
{
	int b[1000];
	for(int i=0; i<n; i++){
		b[i]=a[i];
	}
	ulli sum=0;
	if(arr[a[pos]][a[pos+1]][pos]!=-1 )
	{
		return arr[b[pos]][b[pos+1]][pos];
	}
	if(pos+1<n)
	{
		if(pos+2<n)
		{
			sum+=dfs(b, n, pos+1);  	
			sum=sum%mod;
		}
		else
		{
			sum++;
			sum=sum%mod;
		}
			while(b[pos]!=0 && b[pos+1]!=0)
			{
				if(pos+2<n)
				{
					b[pos+1]--;
					b[pos]--;
					b[pos+2]++;
				}
				else 
				{
					n++;
					b[pos+1]--;
					b[pos]--;
					b[pos+2]=1;
				}
				if(pos+2<n)
				{
					sum+=dfs(b, n, pos+1);  	
					sum=sum%mod;
				}
				else
				{
					sum++;
					sum=sum%mod;
				}
			}
	}
	arr[a[pos]][a[pos+1]][pos]=sum%mod;
	return sum%mod;	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[1000];
		for(int i=0; i<200; i++)
		{
			for(int j=0; j<200; j++)
			{
				for(int k=0; k<100; k++)
					arr[i][j][k]=-1;
			}
		}
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		if(n==1)
			cout<<"1"<<endl;
		else
		{
			cout<<dfs(a, n, 0)<<endl;
		}
	}
	return 0;
}
