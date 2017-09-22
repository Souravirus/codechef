#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, n;
	char prev;
	cin>>T;
	while(T--){
		int count=0;
		cin>>n;
		char** S = new char*[2];
		for(int i = 0; i < 2; ++i)
    		S[i] = new char[n];
		int flagu=0;
		int flag1=0;
		int flag2=0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>S[i][j];				
			}
		}
		for(int j=0;j<n;j++){
			if(S[0][j]=='*' && flag1==1)
			{
				count++;
				flag2=0;
				flag1=0;
			}
			else if(S[1][j]=='*' && flag2==1)
			{
				count++;
				flag1=0;
				flag2=0;
			}
			if(S[0][j]=='*' && flag1==0)
				flag1=1;
			if(S[1][j]=='*' && flag2==0)
				flag2=1;
			if(flag1==1 && flag2==1)
				flagu=1;
			
			
		}
		if(flagu==1)
		count++;
		cout<<count<<endl;
	}
	return 0;
}
