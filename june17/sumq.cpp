#include<bits/stdc++.h>
#define mod 1000000007 
using namespace std;
int main(){
	int T, p, q, r; 
	unsigned long long int ptotal, rtotal, ans, parr[100000], rarr[100000];
	cin>>T;
	while(T--){
		cin>>p>>q>>r;
		multiset<int> pset;
		multiset<int> qset;
		multiset<int> rset;
		multiset<int> ::iterator its;
		multiset<int> ::iterator itp;
		set<int> ::iterator ppos;
		set<int> ::iterator rpos;
		set<int> ::iterator pind;
		set<int> ::iterator rind;
		multiset<int> ::iterator itr;
		for(int i=0;i<p;i++){
			int num;
			cin>>num;
			num=num%mod;
			pset.insert(num);
		}
		for(int i=0;i<q;i++){
			int num;
			cin>>num;
			num=num%mod;
			qset.insert(num);
		}
		for(int i=0;i<r;i++){
			int num;
			cin>>num;
			num=num%mod;
			rset.insert(num);
		}
		int count=0;
		for(itp=pset.begin();itp!=pset.end();itp++){
			if(count==0){
				parr[count]=*itp;
			}
			else{
				parr[count]=parr[count-1]+*itp;
			}
			parr[count]%=mod;
			count++;
		}	
		count=0;
		for(itr=rset.begin();itr!=rset.end();itr++){
			if(count==0){
				rarr[count]=*itr;
			}
			else{
				rarr[count]=rarr[count-1]+*itr;
			}
			rarr[count]%=mod;
			count++;
		}	
		ptotal=0;
		rtotal=0;
		ans=0;
		ppos=pset.begin();
		rpos=rset.begin();
		for(its=qset.begin();its!=qset.end();its++){
			//cout<<"hello in main loop"<<endl;
			itp=pset.upper_bound(*its);
			if(itp!=pset.begin())
				itp--;
			else
				continue;
			itr=rset.upper_bound(*its);
			if(itr!=rset.begin())
				itr--;
			else 
				continue;
			int size=distance(pset.begin(), itp);
			ptotal=parr[size];	
			size++;
			unsigned long long int pimd=ptotal+((size%mod) * (*its)%mod);
			pimd%=mod;
			
			size=distance(rset.begin(), itr);
			rtotal=rarr[size];
			size++;
			unsigned long long int rimd=rtotal+((size%mod) * (*its)%mod);
			rimd%=mod;
			ans+=pimd*rimd;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
