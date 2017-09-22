#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
int main(){
	int T, N, C[1000000];
	cin>>T;
	while(T--){
		cin>>N;
		int W[N];
		map<int, int>m;
		map<int, int> ::iterator itm;
		ulli max=0;
		for(int i=0; i<N; i++)
		{
			scanf("%d", &C[i]);
		}
		for(int i=0;i<N; i++)
		{
			int s;
			scanf("%d", &W[i]);
		}
		ulli sum=0;
		int j=0;
		for(int i=0; i<N; i++){
			itm=m.find(C[i]);
			if(itm==m.end())
			{
				m.insert(pair<int, int>(C[i], i));
				sum+=W[i];
				if(sum>max)
					max=sum;
			}
			else{
				int z=itm->second;		
				for(int k=j;k<=z;k++){
					m.erase(C[k]);
					sum-=W[k];
				}
				j=z+1;
				sum+=W[i];
				m.insert(pair<int, int>(C[i], i));
				if(sum>max)
					max=sum;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
