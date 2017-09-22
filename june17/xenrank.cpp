#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int T, count, U, V;
	cin>>T;
	while(T--){
		cin>>U>>V;
		long long int sum=U+V;
		count=1+((sum*(sum+1))/2);
		long long int rank=count+(U-0);
		cout<<rank<<endl;
	}
	return 0;
}
