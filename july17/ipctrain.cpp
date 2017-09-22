#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second>b.second;
}
int main(){
	int T;
	int N, D;
	int Di, Ti, Si;
	pair<int, int>foo;
	vector<pair<int, int> > ::iterator itv2;
	vector<pair<int, int> > ::iterator itv1;
	cin>>T;
	while(T--){
		cin>>N>>D;
		int arr[D]={0};
		int sad=0;
		vector<pair<int, int> > dt;
		vector<pair<int, int> > s;
		for(int i=0; i<N; i++)
		{
			scanf("%d%d%d", &Di,&Ti,&Si);
			foo=make_pair(Di, Ti);	
			dt.push_back(foo);
			foo=make_pair(i, Si);
			s.push_back(foo);
		}
		sort(s.begin(), s.end(), sortbysecdesc);
		for(itv1=s.begin(); itv1!=s.end(); itv1++)
		{
			int count=dt[itv1->first].second;
			//cout<<"count"<<count<<endl;
			int start=dt[itv1->first].first;
			//cout<<"start"<<start<<endl;
			start--;
			while(count && start < D)
			{
				if(!arr[start])
				{
					count--;
					arr[start]=1;
				}
				start++;
			}
			sad+=count*(itv1->second);	
		}
		cout<<sad<<endl;
	}
	return 0;

}
