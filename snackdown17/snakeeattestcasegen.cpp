#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int T, N, Q, L, K;
	T=1;
	cout<<T<<endl;
	for(int j=0;j<T;j++){
	N=rand()%100000+1;
	Q=rand()%100000+1;
	cout<<N<<" "<<Q<<endl;
	for(int i=0;i<N;i++)
	{
		T=rand()%1000000000+1;
		cout<<T<<" ";
	}
	cout<<endl;
	for(int i=0;i<Q;i++)
	{
		K=rand()%1000000000+1;
		cout<<K<<" ";
	}
	}
	return 0;
}
