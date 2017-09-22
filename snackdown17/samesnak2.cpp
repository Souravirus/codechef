#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int T, X[4], Y[4],flag2X, flag2Y, flag3X, flag3Y, flagf ;
	cin>>T;
	while(T--){
		flag2X=0;flag2Y=0;
		flagf=0;
		flag3X=0; flag3Y=0;
		for(int i=0;i<4;i++){
			cin>>X[i];
			cin>>Y[i];
		}
		if(X[0]==X[1])
		{
			if(X[2]==X[0] && X[3]==X[0]){
				if(Y[0] <= Y[2] && Y[2]<=Y[1] || Y[1] <= Y[2] && Y[2]<=Y[0])	
				flagf=1;
				else if(Y[0] <= Y[3] && Y[3]<=Y[1] || Y[1] <= Y[3] && Y[3]<=Y[0])	
				flagf=1;
			}
			else if(X[2]==X[0])
			{
				if(Y[2]==Y[0] || Y[2]==Y[1])
				{
					flagf=1;
				}
			}
			else if(X[3]==X[0])
			{
				if(Y[3]==Y[0] || Y[3]==Y[1])
				flagf=1;
			}
		}
		if(Y[0]==Y[1])
		{
			if(Y[2]==Y[0] && Y[3]==Y[0]){
				if(X[0] <= X[2] && X[2]<=X[1] || X[1] <= X[2] && X[2]<=X[0])	
				flagf=1;
				else if(X[0] <= X[3] && X[3]<=X[1] || X[1] <= X[3] && X[3]<=X[0])	
				flagf=1;
			}
			else if(Y[2]==Y[0])
			{
				if(X[2]==X[0] || X[2]==X[1])
				{
					flagf=1;
				}
			}
			else if(Y[3]==Y[0])
			{
				if(X[3]==X[0] || X[3]==X[1])
				flagf=1;
			}
		}
		if(X[2]==X[3]){
			if(X[2]==X[0] && X[1]==X[2])
			{
				if(Y[2] <= Y[0] && Y[0]<=Y[3] || Y[3] <= Y[0] && Y[0]<=Y[2])	
				flagf=1;
				else if(Y[2] <= Y[1] && Y[1]<=Y[3] || Y[3] <= Y[1] && Y[1]<=Y[2])	
				flagf=1;
			}
			else if(X[2]==X[0])
			{
				if(Y[2]==Y[0] || Y[0]==Y[3])
				{
					flagf=1;
				}
			}
			else if(X[1]==X[2])
			{
				if(Y[1]==Y[2] || Y[1]==Y[3])
				flagf=1;
			}
		}
		if(Y[2]==Y[3]){
			if(Y[2]==Y[0] && Y[1]==Y[2])
			{
				if(X[2] <= X[0] && X[0]<=X[3] || X[3] <= X[0] && X[0]<=X[2])	
				flagf=1;
				else if(X[2] <= X[1] && X[1]<=X[3] || X[3] <= X[1] && X[1]<=X[2])	
				flagf=1;
			}
			else if(Y[0]==Y[2])
			{
				if(X[2]==X[0] || X[0]==X[3])
				{
					flagf=1;
				}
			}
			else if(Y[1]==Y[2])
			{
				if(X[1]==X[2] || X[3]==X[1])
				flagf=1;
			}
		}
		if(flagf==1)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		
	}
	return 0;	
}
