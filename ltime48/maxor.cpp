#include<bits/stdc++.h>
typedef long long int ulli;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ulli t, n;
	cin>>t;
	while(t--){
		cin>>n;
		ulli a[n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		ulli count=0;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				ulli bor=a[i]|a[j];
				//cout<<"bor"<<bor<<endl;
				//cout<<"max"<<max(a[i], a[j])<<endl;
				if(bor<=max(a[i], a[j]))
				{
					//cout<<"hello"<<endl;
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
