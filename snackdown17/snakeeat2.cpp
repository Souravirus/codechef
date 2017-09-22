#include<iostream>
#include<vector>
#include<set>
using namespace std;
int binsearch(vector<long long int>v, int start, int end, int ind, int K){
	int curans=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if((K*(ind-mid))-(v[ind]-v[mid])==mid+1)
		{
			return mid+1;
		}
		else if((K*(ind-mid))-(v[ind]-v[mid])<mid+1){
			curans=mid+1;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	if(curans!=-1)
		return curans;
	
	else
		return ind+1;
}
int main(){
	int T, N, Q, L, K, flag, count,pos,diff;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cin>>Q;
		vector<long long int> v;
		multiset<int>myset;
		for(int i=0;i<N;i++)
		{
			cin>>L;
			myset.insert(L);
		}
		multiset<int>::iterator itt;
		long long total=0;
		int i=0;
		for(itt=myset.begin();itt!=myset.end(); itt++){
			total+=*itt;
			v.push_back(total);
			i++;
		}
		for(int i=0;i<Q;i++)
		{
			cin>>K;
			count=0;
			multiset<int>::iterator it=myset.lower_bound(K);
			multiset<int>::iterator c=myset.end();
			int count=distance(it,c);
		//	cout<<"count"<<count<<endl;
		it--;
			pos=N-count;
//			cout<<"pos"<<pos<<endl;
			int posi=binsearch(v, 0, pos-1, pos-1,K);
	//		cout<<"posi"<<posi<<endl;
			count+=pos-posi;
			cout<<count<<endl;
		}
	//	for(int i=0;i<N;i++)
		//	cout<<L[i];
	}
	return 0;
}
