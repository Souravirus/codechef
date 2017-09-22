#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	int T, N, count, countn;
	lli sump, sumn, ansp;
	cin>>T;
	while(T--){
		cin>>N;
		sump=0;
		multiset<int>myset;
		multiset<int>::reverse_iterator itp;
		sumn=0;
		count=0;
		countn=0;
		for(int i=0;i<N;i++){
			int num;
			scanf("%d", &num);
			if(num>0)
			{
				count++;
				sump+=num;
			}
			else{
				myset.insert(num);
				sumn+=num;
				countn++;
			}
		}
		ansp=count*sump;
		ansp+=sumn;
		if(count){
			int i=0;
			itp=myset.rbegin();
			while(itp!=myset.rend()){
				//cout<<"hello "<<*itp<<endl;
				lli anst;	
				sump+=*itp;	
				count++;
				anst=count*sump;
				sumn-=*itp;
				anst+=sumn;
				if(anst>ansp){
					ansp=anst;
					itp++;
				}
				else
					break;
			}
		}
			cout<<ansp<<endl;
	}
	return 0;
}
