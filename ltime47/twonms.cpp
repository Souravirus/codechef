#include<bits/stdc++.h>
using namespace std;
int main(){
	long long T, A, B, N;
	cin>>T;
	while(T--){
		cin>>A>>B>>N;
		if(N%2==0)
		{
			if(A>B)
				cout<<A/B<<endl;
			else
				cout<<B/A<<endl;
		}
		else{
			A=A*2;
			if(A>B)
				cout<<A/B<<endl;
			else
				cout<<B/A<<endl;
		}
	}
	return 0;
}
