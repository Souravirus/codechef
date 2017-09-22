#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, N, Q, L, K, flag, count,pos,diff;
	multiset<int>myset;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cin>>Q;
		for(int i=0;i<N;i++)
		{
			cin>>L;
			myset.insert(L);
		}
		for(int i=0;i<Q;i++)
		{
			cin>>K;
			count=0;
		/*	for(int m=0;m<N;m++)
			{
				if(L[m]<K)
				{
					count=m;
					break;
				}
				if(m==N-1)
				{
					count=N;
				}
			}*/
			multiset<int>::iterator it=myset.lower_bound(K);
			multiset<int>::iterator c=myset.end();
			int count=distance(it,c);
			it--;
			flag=1;
			pos=N-count;
			while(flag<pos){
				int ele=*it;
				diff=K-ele;
				flag+=diff;
				if(flag<=pos)
				{
					pos--;
					count++;
					it--;
				}
			}
			cout<<count<<endl;
		}
	//	for(int i=0;i<N;i++)
		//	cout<<L[i];
	}
	return 0;
}
