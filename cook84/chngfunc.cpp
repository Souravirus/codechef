#include<bits/stdc++.h>
using namespace std;
int main(){
	int A, B;
	cin>>A>>B;
	int sum=0;
	for(int i=1; i<=A; i++)
	{
		int flag=0;
		for(int j=i+1; j<=A+1; j++)
		{
			int s1=i*i;
			int s2=(j)*(j);
			int diff=s2-s1;
			if(diff<=B)
			{
				sum++;
				flag=1;
			}
			else
				break;
		}
		if(flag==0)
			break;
	}
	cout<<sum;
	return 0;
}
