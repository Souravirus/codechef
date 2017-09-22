#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
int main(){
	ulli T;
	ulli N, D;
	ulli Di, Ti, Si;
	vector<pair<ulli, pair<ulli, ulli> > > :: iterator itvp;
	pair<ulli, ulli> foo;
	pair<ulli, pair<ulli, ulli> > foo2;
	cin>>T;
	while(T--)
	{
		cin>>N>>D;
		vector<pair<ulli, pair<ulli, ulli> > > dts;
		for(ulli i=0; i<N; i++)
		{
			scanf("%lld%lld%lld", &Di, &Ti, &Si);
		//	cout<<"inserting in dts"<<Di<<" "<<Ti<<" "<<Si<<endl;
			foo=make_pair(Ti, Si);
			foo2=make_pair(Di, foo);
			dts.push_back(foo2);
		}
		sort(dts.begin(), dts.end());
		map<ulli, ulli>umap;
		map<ulli, ulli>:: reverse_iterator rit;
		map<ulli, ulli>:: iterator itm;
		ulli count=0;
		for(ulli i=1; i<=D; i++){
		//	cout<<"hello"<<i<<endl;
			while(dts[count].first==i && count<N){
				ulli sm=dts[count].second.second;
		//	cout<<"sm"<<sm<<endl;
				ulli tm=dts[count].second.first;
		//	cout<<"tm"<<tm<<endl;
				if(umap.find(sm)==umap.end())
				{
			//		cout<<"inserting "<<sm<<" "<<tm<<endl;
					umap.insert(pair<int, int>(sm,tm));
				}
				else
				{
					umap[sm]+=tm;
			//		cout<<"umap[sm]"<<sm<<" "<<" "<<tm<<""<<umap[sm]<<endl;
				}
				count++;
			}
			if(!umap.empty())
			{
				rit=umap.rbegin();
			//	cout<<"rit->second before"<<rit->first<<" "<<rit->second<<endl;
				rit->second-=1;
			//	cout<<"rit->second after"<<rit->first<<" "<<rit->second<<endl;
				if(rit->second==0)
				{
			//		cout<<"erasing "<<rit->first<<endl;
					umap.erase(rit->first);
				}
			}
		}
		ulli sad =0;
		if(!umap.empty())
		{
			for(itm=umap.begin(); itm!=umap.end(); itm++)
			{
				sad+=(itm->first*itm->second);
			}
		}
		cout<<sad<<endl;
		//dts.clear();
		//umap.clear();
	}
	return 0;
}
