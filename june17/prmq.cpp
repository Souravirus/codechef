#include<bits/stdc++.h>
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
			
	unordered_map<int, unordered_map<int, int> > mymap;
	unordered_map<int, unordered_map<int, int> >::iterator itu;
	unordered_map<int, int> ::iterator itut;
	cin>>N;
	int k=1;
	while(N--){
		scanf("%d", &A[k]);
		itu=mymap.find(A[k]);
		if(itu==mymap.end()){
			//cout<<"I am in itu inserting mode now "<<A[k]<<endl;
			unordered_map<int, int> umap;
			int B=A[k];
			int curr=sp[B];
			int count=0;
			while(B!=1){
				//cout<<"now in while B==1 wala loop B: "<<B<<endl;
				//cout<<"sp[B]:"<<sp[B]<<endl;
				if(sp[B]==0){
					sp[B]=B;
				}
				if(sp[B]==curr){
					count++;
				}
				else{
					curr=sp[B];
					count=1;
				}
				itut=umap.find(sp[B]);
				if(itut==umap.end()){
					umap.insert(pair<int, int>(sp[B],count)); 
					//cout<<"inserting new element sp[B]:"<<sp[B]<<endl;
				}
				else{
					itut->second=count;
					//cout<<"inserting inside element sp[B]:"<<sp[B]<<" count:"<<count<<endl;
				}
				if(sp[B]!=0)
					B/=sp[B];
			}
			mymap.insert(pair<int, unordered_map<int, int> >(A[k], umap)); 
		}
		k++;
	}
	cin>>Q;
	while(Q--){
		int sum=0;
		scanf("%d", &L);
		scanf("%d", &R);
		scanf("%d", &X);
		scanf("%d", &Y);
		while(X<=Y){
			if(prime[X]){
				//cout<<X <<" is prime checked"<<endl;
				for(int i=L;i<=R;i++){
					itu=mymap.find(A[i]);
					itut=itu->second.find(X);
					if(itut!=itu->second.end()){
						//cout<<"inside itut wala loop"<<endl;
						sum+=itut->second;
					}
				}
			}
			X++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
