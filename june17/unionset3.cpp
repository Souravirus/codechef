
#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int p,q,r;
		cin>>p>>q>>r;
		int x[p],y[q],z[r];
		for(int i=0;i<p;i++)
			cin>>x[i];
		for(int i=0;i<q;i++)
			cin>>y[i];
		for(int i=0;i<r;i++)
			cin>>z[i];
		unsigned long long int sum=0,ans=0;
		for(int i=0;i<q;i++){
			for(int j=0;j<p;j++){
				if(x[j]<=y[i]){
					for(int k=0;k<r;k++){
						if(z[k]<=y[i]){
							sum=(((x[j]+y[i])%1000000007)*((z[k]+y[i])%1000000007))%1000000007;
							ans=(ans+sum)%1000000007;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
