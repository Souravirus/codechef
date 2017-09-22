#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, m, n, u, v, arr[100000]={0};
	cin>>T;
	while(T--){
		int count=0;
		cin>>m>>n;
		map<int, set<int> >ele;
		map<int, set<int> >mymap;
		map<int, set<int> >:: iterator itm;
		for(int i=1;i<=n;i++){
			cin>>u;
			cin>>v;
			arr[u]++;
			arr[v]++;
			itm=ele.find(u);
			if(itm==ele.end()){
				set<int> s;
				s.insert(v);
				ele.insert(pair<int, set<int> >(u, s));
			}
			else{
				itm->second.insert(v);
			}
			itm=ele.find(v);
			if(itm==ele.end()){
				set<int> s;
				s.insert(u);
				ele.insert(pair<int, set<int> >(v, s));
			}
			else{
				itm->second.insert(v);
			}
			
		}
		for(int i=1;i<=m;i++){
			itm=mymap.find(arr[i]);
			if(itm==mymap.end()){
				set<int> s;
				s.insert(i);
				mymap.insert(pair<int, set<int> >(arr[i], s));
			}
			else{
				itm->second.insert(i);
			}
		}
		for(int i=0;i<m;i++)
		{
			if(count==m){
				cout<<m-1<<" ";
			}
			else{
				itm=mymap.find(i);
				if(itm!=mymap.end()){
					count+=itm->second.size();
				}
				if(count==m)
				cout<<m-1<<" ";
				else
				cout<<count<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
