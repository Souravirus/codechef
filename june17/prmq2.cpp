#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
int main(){
	int N, Q, L, R, X, Y, lar=2, A[100001], sp[1000001]={0};
	bool prime[1000001];
	memset(prime, true, sizeof(prime));
	while(sqrt(1000000)>=lar){
		if(prime[lar]){
			//cout<<lar<<" is prime"<<endl;
			sp[lar]=lar;
			//cout<<"sp[lar]="<<lar<<endl;
			for(int i=lar*2;i<=1000000;i+=lar)
			{
				prime[i]=false;	
				if(sp[i]==0)
				{
							//cout<<"sp["<<i<<"]"<<lar<<endl;
					sp[i]=lar;
				}
			}
		}
		lar++;
	}
	map<int, map<int, int> >mymap; 
	map<int, map<int, int> > :: iterator itm; 
	vector<map<int, int> > myvect;
	map<int, int> ::iterator itut;
	map<int, int> ::iterator itut2;
	cin>>N;
	for(int k=0; k<N; k++){
		scanf("%d", &A[k]);
		int B=A[k];
		itm=mymap.find(A[k]);
		if(itm==mymap.end())
		{
			map<int, int> umap;	
			while(B!=1){
				if(sp[B]==0){
					sp[B]=B;
				}
				itut=umap.find(sp[B]);
				if(itut==umap.end()){
					umap.insert(pair<int, int>(sp[B],1));
				}
				else{
					itut->second++;
				}
				B/=sp[B];
			}
			mymap.insert(pair<int, map< int, int> >(A[k], umap));
		}
	}
	//cout<<"inserted prime factors"<<endl;
	for(int k=0;k<N;k++){
		map<int, int>umap;
		if(k!=0){
			umap=myvect[k-1];
		}
		itm=mymap.find(A[k]);
		for(itut=itm->second.begin();itut!=itm->second.end();itut++){
			itut2=umap.find(itut->first);
			if(itut2==umap.end())
			{
				umap.insert(pair<int, int>(itut->first, itut->second));
			}
			else
			{
				itut2->second+=itut->second;
			}
		}
		myvect.push_back(umap); 
	}
	//cout<<"inserted all the vectors"<<endl;	
	//next phase
	cin>>Q;
	while(Q--){
		int sum=0;
		scanf("%d", &L);
		scanf("%d", &R);
		scanf("%d", &X);
		scanf("%d", &Y);
		while(X<=Y){
			if(prime[X]){
				if(L!=1)
					itut=myvect[L-2].find(X);
				itut2=myvect[R-1].find(X);
				int countl;
				int countr;
				if(L==1)
				{
					countl=0;
				}
				else if(itut==myvect[L-2].end()){
					countl=0;
				}
				else{
					countl=itut->second;
				}
				if(itut2==myvect[R-1].end())
				{
					countr=0;
				}
				else{
					countr=itut2->second;
				}
				sum+=countr-countl;	
			}
			X++;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
