#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, n;
	set<int> myset;
	set<int> ::iterator its;
	set<int> oset;
	set<int> ::iterator itso;
	cin>>T;
	int count=4;
	while(T--){
		cin>>n;
		if(myset.empty())
		{
			myset.insert(1);
			myset.insert(2);
			oset.insert(3);
		}
		while(n>myset.size()){
			if(oset.find(count)==oset.end()){
				myset.insert(count);
				for(its=myset.begin();its!=myset.end(); its++)
				{
					oset.insert(count+*its);
				}
			}
			count++;
		}
		its=myset.begin();
		for(int i=0;i<n;i++){
			cout<<*its<<" ";
			its++;
		}
		cout<<endl;
	}
}
