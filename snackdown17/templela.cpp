#include<bits/stdc++.h>
using namespace std;
int main(){
	int S, N, H[100], flag=0;
	cin>>S;
	while(S--){
		cin>>N;
		flag=0;
		for(int i=0;i<N;i++)
		{
			cin>>H[i];
			if(N%2==0){
				flag=1;
			}
			else if(i==0)
			{
				if(H[i]!=1)
				{
					flag=1;
				}
			}
			else if(i==N-1){
				if(H[i]!=1 || H[i-1]-H[i]!=1)
					flag=1;
			}
			else if(i<=N/2){
				if(H[i]-H[i-1]!=1)
					flag=1;
			}
			else if(i>N/2){
				if(H[i-1]-H[i]!=1)
					flag=1;
			}
		}
		if(flag==1){
			cout<<"no"<<endl;
		}
		else
			cout<<"yes"<<endl;
	}
	return 0;
}
