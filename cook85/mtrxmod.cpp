#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, Q;
	int a[1001][1001];
	int mat[1001];
	cin>>N>>Q;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin>>a[i][j];
		}
	}
	mat[1]=0;
	int count=0;
	int p;
	while(count<Q+1)
	{
		for(int i=2; i<=N; i++)
		{
			mat[i]=-1*a[i][1];
			if(i!=2)
			{
				if(abs(mat[i-1]-mat[i])!=a[i][i-1])
				{
					mat[i]=-1*mat[i];	
				}
			}
		}
		for(int i=1; i<=N; i++)
		{
			cout<<mat[i]<<" ";
		}
		cout<<endl;
		if(count!=Q)
		{
			cin>>p;
			int num;
			for(int i=1; i<=N; i++)
			{
				cin>>num;
				a[i][p]=num;
				a[p][i]=num;
			}
		}
		count++;
	}
	return 0;
}
