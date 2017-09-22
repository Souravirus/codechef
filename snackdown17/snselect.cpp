#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		int count=0;
		int countm=0;
		for(int i=0;i<S.length(); i++)
		{
			if(S[i]=='m')
			{
				countm++;
			}
			if(S[i]=='m' && i!=0 && S[i-1]=='s')
			{
				S[i-1]='d';
				count++;
			}
			else if(S[i]=='m' && i!=S.length()-1 && S[i+1]=='s')
			{
				S[i+1]='d';
				count++;
			}
		}
		int counts=S.length()-countm-count;
		if(countm==counts)
		{
			cout<<"tie"<<endl;
		}
		if(countm>counts)
			cout<<"mongooses"<<endl;
		if(countm<counts)
			cout<<"snakes"<<endl;
	}
}
