#include<bits/stdc++.h>
#define vvp vector<vector<pair<int, int> > >
#define vp vector<pair< int, int> >
using namespace std;
pair<int, int> foo;
vvp :: iterator itvvp;
vvp :: iterator itvvp1;
vvp :: iterator itvvp2;
vp::iterator itvp1;
vp::iterator itvp2;
int cnt=0;
void dfs(vvp tree, int pos, int *arr, int *R, vector<pair<int, int> >& E,int level )
{
	//cout<<"hello"<<pos<<endl;
	vp::iterator itvp;
	arr[pos]=1;	
	if(R[pos]==-1)
	{
		R[pos]=cnt;
		//cout<<"Rpos"<<R[pos]<<endl;
	}
	foo=make_pair(pos, level);
	E.push_back(foo);
	//cout<<"pos"<<pos<<endl;
	level++;
	cnt++;
	//cout<<"cnt"<<cnt<<endl;
	int flag=0;
	for(itvp=tree[pos].begin(); itvp!=tree[pos].end(); itvp++)
	{
		//cout<<"itvp->first before loop"<<itvp->first<<endl;
		if(itvp->first>pos)
		{
		//	cout<<"itvp->first"<<itvp->first<<endl;
			dfs(tree, itvp->first, arr, R, E, level);
		//	cout<<"finished of pos"<<pos<<endl;
		//	cout<<"itvp->first after"<<itvp->first<<endl;
			foo=make_pair(pos, level-1);
			E.push_back(foo);
			cnt++;
		//	cout<<"pos"<<pos<<endl;
			arr[pos]+=arr[itvp->first];
			flag=1;
		}
	}
}

void segment(int node, int b, int e, vector<pair<int, int> > E, int *seg) 
{
	if(b==e)
		seg[node]=b;
	else
	{
		int mid=(b+e)/2;
		segment((2*node), b, mid, E, seg);
		segment((2*node)+1, mid+1, e, E, seg);
		if(E[seg[2*node]].second<=E[seg[2*node+1]].second)
		{
			seg[node]=seg[2*node];
		}
		else
			seg[node]=seg[2*node+1];
	}
	//cout<<"seg"<<node<<" "<<seg[node]<<endl;
}
int segquery(int node, int s, int e, int l, int r, int *seg, vector<pair<int, int> >E)
{
	int size=E.size()-1;
	if(s>r || e<l)
	{
	//	cout<<"hello exiting in -1 "<<"s"<<s<<" e"<<e<<" r"<<r<<" l"<<l<<endl;
		return size;
	}
	else if(s>=l && e<=r)
	{
	//	cout<<"entered in second also"<<" s"<<s<<"e "<<e<<" l"<<l<<" r"<<r<<endl;
		return seg[node];
	}
	else
	{
		int m=(s+e)/2;
	//	cout<<"entered in third also"<<" s"<<s<<"e "<<e<<" l"<<l<<" r"<<r<<endl;
		int ans1=segquery(2*node, s, m, l, r, seg, E);
		int ans2=segquery(2*node+1, m+1, e, l, r, seg, E);
		if(E[ans1].second<E[ans2].second)
			return ans1;
		else
			return ans2;
	}
}

void hld(int cur, int chainNo, int *chainHead, int *chainInd, int *chainPos, int *chainSize)
{
	if(chainHead[chainNo]==-1) 
		chainHead[chainNo]=cur;
	chainInd[cur]=chainNo;
	chainPos[cur]=chainSize[chainNo];
}

int main(){
	int T, N, M, U, V, C, K;
	cin>>T;
	while(T--)
	{
		vvp tree;
		cin>>N;
		for(int i=1; i<=N; i++)
		{
			foo=make_pair(-1, -1);
			vector <pair<int, int> > v;
			v.push_back(foo);	
			tree.push_back(v);
		}
		for(int i=0; i<N-1; i++)
		{
			scanf("%d%d%d", &U, &V, &C);
			foo=make_pair(V-1, C);
			tree[U-1].push_back(foo);
			itvp1=tree[U-1].begin()+1;
			itvp2=tree[U-1].end()-1;
			if(itvp1->first>itvp2->first)
			{
				//cout<<"hello"<<endl;
				int first=itvp1->first;
				int second=itvp1->second;
				itvp1->first=itvp2->first;
				itvp1->second=itvp2->second;
				itvp2->first=first;
				itvp2->second=second;
			}
			foo=make_pair(U-1, C);
			tree[V-1].push_back(foo);
			itvp1=tree[V-1].begin()+1;
			itvp2=tree[V-1].end()-1;
			if(itvp1->first>itvp2->first)
			{
				//cout<<"hello"<<endl;
				int first=itvp1->first;
				int second=itvp1->second;
				itvp1->first=itvp2->first;
				itvp1->second=itvp2->second;
				itvp2->first=first;
				itvp2->second=second;
			}
		}	
		/*for(int i=0; i<N; i++)
		{
			cout<<i<<"=>"<<endl;
			for(itvp1=tree[i].begin(); itvp1!=tree[i].end(); itvp1++)
			{
				cout<<itvp1->first<<endl;
			}
		}*/
		int subSize[N+1]={1};
		int R[N];
		for(int i=0; i<N; i++)
			R[i]=-1;
		vector<pair<int, int> > E;
		vector<pair<int, int> >:: iterator itvp;
		dfs(tree, 0 ,subSize, R, E, 0);
		/*for(int i=0; i<N; i++)
		{
			cout<<R[i]<<endl;
		}
		cout<<"E vector"<<endl;
		for(itvp=E.begin(); itvp!=E.end(); itvp++)
		{
			cout<<itvp->first<<" "<<itvp->second<<endl;
		}*/
		int seg[4*E.size()];
		segment(1, 0, E.size()-1, E, seg);
		//int chainNo=0, chainHead[N]={-1}, chainInd[N], chainPos[N], chainSize[N];
		//hld(0, chainNo, chainHead, chainInd, chainPos, chainSize);
		foo=make_pair(0, INT_MAX);
		E.push_back(foo);
		cin>>M;
		for(int i=0; i<M; i++)
		{
			cin>>U;
			cin>>V;
			cin>>K;
			int be=R[U-1];
			int en=R[V-1];
			if(be>en)
			{
				int temp=be;
				be=en;
				en=temp;
			}
			int lca=segquery(1, 0, E.size()-2, be, en, seg, E);
			lca=E[lca].first;
		//	cout<<"lca"<<lca<<endl;
			int start=0;
			int ini=U-1;
			while(ini!=lca)
			{
				itvp1=tree[ini].begin()+1;
				ini=itvp1->first;
		//		cout<<"ini"<<ini<<endl;
				int c=itvp1->second;
		//		cout<<"c"<<c<<endl;
				if(c<=K)
				{
					start=start^c;
				}
			}
			ini=V-1;
			while(ini!=lca)
			{
				itvp1=tree[ini].begin()+1;
				ini=itvp1->first;
				int c=itvp1->second;
		//		cout<<"ini"<<ini<<endl;
		//		cout<<"c"<<c<<endl;
				if(c<=K)
				{
					start=start^c;
				}
			}
		cout<<start<<endl;
		}
	}
	return 0;
}
