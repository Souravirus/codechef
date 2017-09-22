#include<bits/stc++.h>
using namespace std;
int main(){
	int T, N, u, v, count;
	cin>>T;
	while(T--){
		cin>>N;
		map<int, set<int> > mymap;
		map<int, set<int> >::iterator itm;
		map<int, int> asc;
		map<int, int>:: iterator itas;
		for(int i=1;i<N;i++)
		{
			cin>>u;
			cin>>v;
			itm=mymap.find(u);
			if(itm==mymap.end())
			{
				set<int> s;
				s.insert(v);
				mymap.insert(pair<int, set<int> >(u, s);
			}
			else
			{
				mymap[u].insert(v);	
			}
			itm=mymap.find(v);	
			if(itm==mymap.end())
			{
				set<int> s;
				s.insert(u);
				mymap.insert(pair<int, set<int> >(v, s);
			}
			else
			{
				mymap[v].insert(u);	
			}
		}
		for(int i=1;i<=N;i++)
		{
			int o;
			cin>>o;

		}
	}
	return 0;
}
