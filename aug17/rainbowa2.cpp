#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		int b[n];
		int c[n];
		for(int i=0; i<7; i++)
		{
			c[i]=0;
			b[i]=0;
		}
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		int count=1;
		int flag=0;
		int phase=0;	
		for(int i=0; i<n; i++)
		{
			if(phase==0)
			{
				if(a[i]>=8)
				{
					flag=1;
					//cout<<"flag0"<<endl;
					break;
				}
				else if(a[i]==count)
				{
					b[a[i]-1]++;
				}
				else if(a[i]==count+1)
				{
					b[a[i]-1]++;	
					count++;
					//cout<<"count"<<count<<endl;
				}
				else if(count==7 && a[i]==6)
				{
					phase=1;	
					count--;
					c[6]=b[6];
					c[a[i]-1]++;
				}
				else
				{
					flag=1;
					//cout<<"flag1"<<endl;
					break;
				}
			}
			else if(phase==1)
			{
				//cout<<"hello in phase 2"<<endl;
				if(a[i]>=8)
				{
					flag=1;
				//	cout<<"flag2"<<endl;
					break;
				}
				else if(a[i]==count)
				{
					c[a[i]-1]++;
				}
				else if(a[i]==count-1)
				{
					c[a[i]-1]++;
					count--;
				}
				else
				{
					flag=1;
				//	cout<<"flag3"<<endl;
					break;
				}
			}
		}
		for(int i=0; i<7; i++)
		{
			//cout<<"bi"<<i<<b[i]<<endl;
			//cout<<"ci"<<i<<c[i]<<endl;
			if(b[i]!=c[i])
			{
				flag=1;
				//cout<<"flag4"<<endl;
				break;
			}
		}
		if(flag==1)
		cout<<"no"<<endl;	
		else
			cout<<"yes"<<endl;
	}
	return 0;
}
