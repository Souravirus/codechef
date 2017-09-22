#include<bits/stdc++.h>
using namespace std;
int main(){
	int R, L;
	char str[501];
	cin>>R;
	while(R--){
		int flagH=0, flag=0;
		cin>>L;
		for(int i=0;i<L;i++){
			cin>>str[i];
			if(str[i]=='H' &&  flagH==0)
			{
				flagH=1;
			}
			else if(str[i]=='H' &&  flagH!=0)
				flag=1;
			else if(str[i]=='T' &&  flagH==1){
				flagH=0;
			}
			else if(str[i]=='T' && flagH==0){
				flag=1;
			}
			else if(str[i]!='.')
				flag=1;
		}
		if(flag==1||flagH==1)
			cout<<"Invalid"<<endl;
		else
			cout<<"Valid"<<endl;
	}
	return 0;
}
