#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int T, X[4], Y[4],flag2X, flag2Y, flag3X, flag3Y, flagf;
	cin>>T;
	while(T--){
		flag2X=0;flag2Y=0;
		flagf=0;
		flag3X=0; flag3Y=0;
		for(int i=0;i<4;i++){
			cin>>X[i];
			cin>>Y[i];
			if(i==2){
				if(X[i]==X[0]&&X[i]==X[1]){
					if(Y[i]==Y[0]||Y[i]==Y[1])
						flagf=1;
					else	if(Y[0]<Y[i] && Y[i]<Y[1] || Y[1]<Y[i] && Y[i]<Y[0])
						flag2X=1;
				}
				if(Y[i]==Y[0]&&Y[i]==Y[1]){
					if(X[0]<X[i] && X[i]<X[1] || X[1]<X[i] && X[i]<X[0])
						flag2Y=1;
					else if(X[i]==X[0]||X[i]==X[1])
						flagf=1;
				}
			}
			else if(i==3){
				
				if(X[i]==X[0]&&X[i]==X[1]){
					if(Y[0]<Y[i] && Y[i]<Y[1] || Y[1]<Y[i] && Y[i]<Y[0])
						flag3X=1;
					else if(Y[i]==Y[0]||Y[i]==Y[1])
						flagf=1;
				}
				if(Y[i]==Y[0]&&Y[i]==Y[1]){
					if(X[0]<X[i] && X[i]<X[1] || X[1]<X[i] && X[i]<X[0])
						flag3Y=1;
					else if(X[i]==X[0]||X[i]==X[1])
						flagf=1;
				}
			}
		}
		if(flag2X==1){
			if(X[3]==X[0])
			{
				flagf=1;
			}
		}
		if(flag3X==1){
			if(X[2]==X[0])
			{
				flagf=1;
			}
		}
		if(flag2Y==1){
			if(Y[3]==Y[0])
			{
				flagf=1;
			}
		}
		if(flag3Y==1){
			if(Y[2]==Y[0])
			{
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
