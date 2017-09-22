#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
	int  T, p, q,r, pa[100000], qa[100000], ra[100000];
	unsigned long long int ans, pimd, rimd, ptotal, rtotal, pcount, rcount, parr[100000], rarr[100000]; 
	cin>>T;
	while(T--){
		cin>>p>>q>>r;
		for(int i=0;i<p;i++){
			scanf("%d",&pa[i]);
		}
		for(int i=0;i<q;i++){
			scanf("%d",&qa[i]);
		}
		for(int i=0;i<r;i++){
			scanf("%d", &ra[i]);
		}
		sort(pa, pa+p);
		sort(qa, qa+q);
		sort(ra, ra+r);
		for(int i=0; i<p; i++){
			if(i==0)
				parr[i]=pa[i];
			else
				parr[i]=parr[i-1]+pa[i];
		//	cout<<"parri"<<parr[i]<<endl;
		}
		for(int i=0; i<r; i++){
			if(i==0)
				rarr[i]=ra[i];
			else
				rarr[i]=rarr[i-1]+ra[i];
		//	cout<<"rarri"<<rarr[i]<<endl;
		}
		pcount=0;
		rcount=0;
		ptotal=0;
		rtotal=0;
		ans=0;
		int j;
		int k;
		int flag;
		for(int i=0;i<q; i++){
		//	cout<<"hello"<<endl;
		 	j=pcount;
			k=rcount;
			flag=1;
			while( flag==1 ){
				flag=0;
				if(pa[j]<=qa[i] && j<p){
					j++;
					flag=1;
				}
				if(ra[k]<=qa[i] && k<r){
					k++;
					flag=1;
				}
			}
			if(j==0||k==0)
				continue;
			ptotal=parr[j-1];
			ptotal%=mod;
			pcount=j;
			rtotal=rarr[k-1];
			rtotal%=mod;
			rcount=k;
		//	cout<<"pcount"<<pcount<<endl;
		//	cout<<"rcount"<<rcount<<endl;
			pimd=(ptotal+((pcount*qa[i])%mod))%mod;
			rimd=(rtotal+((rcount*qa[i])%mod))%mod;
			ans+=(pimd*rimd)%mod;
			ans%=mod;
		//cout<<"ans"<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
