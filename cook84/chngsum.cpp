#include<bits/stdc++.h>

#define mod 1000000007
typedef  long long int li;

using namespace std;

int main()
{
	li N, L[1000100], sum=0;
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cin>>L[i];
	}
	for(int i=0; i<N; i++)
	{
		if(L[i]<maxi)
			maxi=L[i];
		li max=0;
		if(i+1<N)
		{
			for(int j=i+1; j<N; j++)
			{
					if(L[j]>max)
						max=L[j];
					li pro=(maxi*max)%mod;
					li diffs=i+1;
					li diffe=N-j;
					pro=(pro*((diffs*diffe)%mod))%mod;
					sum=(sum+pro)%mod;
			}
		}
	}
	cout<<sum;
}
