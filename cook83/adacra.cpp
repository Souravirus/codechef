#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	string N;
	cin>>T;
	while(T--){
		cin>>N;
		int flagu=0;
		int countu=0;
		int countd=0;
		int flagd=0;
		for(int i=0;i<N.length(); i++){
			if(N[i]=='U' && flagu==0){
				flagu=1;
				flagd=0;
				countu++;
			}
			else if(N[i]=='D' && flagd==0){
				flagu=0;
				flagd=1;
				countd++;
			}
		}
		if(countd>countu)
			cout<<countu<<endl;
		else
			cout<<countd<<endl;
	}
}
