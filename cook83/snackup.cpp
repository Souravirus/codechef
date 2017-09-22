#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	int N;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<N<<endl;
		for(int i=0;i<N;i++){
			cout<<N<<endl;
			for(int j=1;j<=N;j++){
				cout<<j<<" ";
				if((i+j)%N!=0)
					cout<<(i+j)%N<<" ";
				else
					cout<<N<<" ";
				if((i+j+1)%N!=0)
					cout<<(i+j+1)%N<<endl;
				else
					cout<<N<<endl;
			}
		}
	}
	return 0;
}
