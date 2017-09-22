#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t, N;
	cin>>t;
	while(t--)
	{
		cin>>N;
		int a[N];
		for(int i=0; i<N; i++)
		{
			cin>>a[i];
		}
		int count=1;
		int flag=0;
		for(int i=0; i<=N/2; i++)
		{
			if(a[i]==count)
			{
				if(a[i]!=a[N-i-1])
				{
					flag=1;
					break;
				}
			}
			else if(a[i]==count+1)
			{
				count++;
				if(a[i]!=a[N-i-1])
				{
					flag=1;
					break;
				}
			}
			else{
				flag=1;
				break;
			}
			if(a[i]>=8)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
