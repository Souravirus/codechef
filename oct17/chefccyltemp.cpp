nclude "bits/stdc++.h"
using namespace std;
#define N 100010
 
int n,q;
vector<int> sg[N],csg[N],small_low[N],small_high[N];
int low[N],high[N];
int lg[N],clg[N];
int lh[N],hl[N];
 
void init(){
	for(int i=0;i<N;i++){
		sg[i].clear();
		csg[i].clear();
		small_low[i].clear();
		small_high[i].clear();
	}
}
 
void input(){
	int x,y;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=0;j<x;j++) {
			cin>>y;
			sg[i].push_back(y);
			csg[i].push_back(0),small_low[i].push_back(0),small_high[i].push_back(0);
		}
	}
	for(int i=0;i<n;i++){
		cin>>x>>y>>lg[i];x--,y--;
		low[i]=x,high[(i+1)%n]=y;
	}
}
 
void process(){
	int prev;
	for(int i=0;i<n;i++){
		csg[i][low[i]]=0;
		for(int next=(low[i]+1)%(sg[i].size());next!=low[i];next=(next+1)%(sg[i].size())){
			prev=(next==0)?sg[i].size()-1:next-1;
			csg[i][next]=sg[i][prev]+csg[i][prev];
		}
		small_low[i][low[i]]=0;
		prev=(low[i]==0)?sg[i].size()-1:low[i]-1;
		for(int next=(low[i]+1)%(sg[i].size());next!=low[i];next=(next+1)%(sg[i].size())){
			small_low[i][next]=min(csg[i][next],csg[i][prev]-csg[i][next]+sg[i][prev]);
		}
	}
	for(int i=0;i<n;i++){
		csg[i][high[i]]=0;
		for(int next=(high[i]+1)%(sg[i].size());next!=high[i];next=(next+1)%(sg[i].size())){
			prev=(next==0)?sg[i].size()-1:next-1;
			csg[i][next]=sg[i][prev]+csg[i][prev];
		}
		small_high[i][high[i]]=0;
		prev=(high[i]==0)?sg[i].size()-1:high[i]-1;
		for(int next=(high[i]+1)%(sg[i].size());next!=high[i];next=(next+1)%(sg[i].size())){
			small_high[i][next]=min(csg[i][next],csg[i][prev]-csg[i][next]+sg[i][prev]);
		}
	}
	clg[0]=0;
	for(int i=1;i<n;i++){
		clg[i]=clg[i-1]+lg[i-1];
	}
 
	lh[0]=small_low[0][high[0]];
	hl[0]=small_high[0][low[0]];
	for(int i=1;i<n;i++){
		lh[i]=lh[i-1]+small_low[i][high[i]];
		hl[i]=hl[i-1]+small_high[i][low[i]];
	}
}
 
void solve(){
	int v1,c1,v2,c2;
	int ans1=0,ans2=0;
	cin>>v1>>c1>>v2>>c2;
	v1--,c1--,v2--,c2--;
 
	if(c1==c2){
		int prev=(high[c1]==0)?sg[c1].size()-1:high[c1]-1;
		ans1=(csg[c1][v2]>=csg[c1][v1])?csg[c1][v2]-csg[c1][v1]:csg[c1][prev]+sg[c1][prev]-(csg[c1][v1]-csg[c1][v2]);
		swap(v1,v2);
		ans2=(csg[c1][v2]>=csg[c1][v1])?csg[c1][v2]-csg[c1][v1]:csg[c1][prev]+sg[c1][prev]-(csg[c1][v1]-csg[c1][v2]);
		cout<<min(ans1,ans2)<<endl;
		return;
	}
 
	ans1+=small_low[c1][v1];
	ans1+=(clg[c2]>=clg[c1])?clg[c2]-clg[c1]:clg[n-1]+lg[n-1]-(clg[c1]-clg[c2]);
	ans1+=(lh[c2]>=lh[c1])?lh[c2]-lh[c1]-small_low[c2][high[c2]]:lh[n-1]-(lh[c1]-lh[c2]-small_low[c1][high[c1]]);
	ans1+=small_high[c2][v2];
 
	ans2+=small_high[c1][v1];
	ans2+=(clg[c1]>=clg[c2])?clg[c1]-clg[c2]:clg[n-1]+lg[n-1]-(clg[c2]-clg[c1]);
	ans1+=(hl[c2]>=hl[c1])?hl[c2]-hl[c1]-small_high[c2][low[c2]]:hl[n-1]-(hl[c1]-hl[c2]-small_high[c1][low[c1]]);
	ans2+=small_low[c2][v2];
 
	cout<<min(ans1,ans2)<<endl;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		input();
		process();
		while(q--) solve();
	}
	return 0;
}
