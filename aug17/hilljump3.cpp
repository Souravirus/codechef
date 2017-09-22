#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli jumparr[20][100001];
//make the update function and query function of segmented tree
stack <pair<lli, int> >sta; 
pair<lli, int> foo;
void build(lli arr[], lli n, lli logval)
{
//	cout<<"building started"<<endl;
	for(lli i=1; i<=n; i++)
	{
	//	cout<<"building in process"<<endl;
		while(!sta.empty())
		{
	//		cout<<"processing"<<endl;
			if(sta.top().first>=arr[i] )
				break;
			else
			{
				if(i-sta.top().second>100)
				{
					jumparr[0][sta.top().second]=sta.top().second;
				}
				else
				{
					jumparr[0][sta.top().second]=i;
				}
				sta.pop();
			}
		}
		foo=make_pair(arr[i], i);	
		sta.push(foo);
		if(i==n)
		{
			while(!sta.empty())
			{
				jumparr[0][sta.top().second]=sta.top().second;
				sta.pop();
			}
		}
	}
}
 
			//update(start, 0, n, value, seg_tree);
lli seg_query(lli l, lli r, lli s, lli e, lli node_num, lli seg_tree[])
{
	if(s>r|| e<l)
		return 0;
	else if(s>=l && e<=r)
		return seg_tree[node_num];
	else
	{
		lli m=(s+e)/2;
		return seg_query(l, r, s, m , node_num*2, seg_tree) + seg_query(l, r, m+1, e, node_num*2+1, seg_tree);
	}
}
 
void seg_update(lli pos, lli s, lli e, lli value, lli seg_tree[], lli node_num)
{
	if(s==e)
	{
		seg_tree[node_num]+=value;
		return ;
	}
	lli mid=(s+e)/2;	
	if(mid<pos)
	{
		seg_update(pos, mid+1, e, value, seg_tree, node_num*2+1);
	}
	else
		seg_update(pos, s, mid, value, seg_tree, node_num*2);
	seg_tree[node_num]=seg_tree[node_num*2]+seg_tree[node_num*2+1];
//	cout<<"updating at node_num "<<node_num<<" putting value "<<seg_tree[node_num]<<endl;
	return ;
}
 
void update_jump(lli arr[], lli n, lli logval,lli seg_tree[]){ 
	//first loop is to traverse to make different arrays from 1 to logval
	if(logval>=17)
		logval=17;
	for(lli i=1; i<=logval; i++)
	{
		for(lli j=1;j<=n; j++)
		{
			lli index=j;
			jumparr[i][j]=jumparr[i-1][jumparr[i-1][j]];
		}
	}
}
 

void update_jump0(lli arr[], lli start, lli end, lli n, lli logval,lli seg_tree[],lli upni[]){ 
	//first loop is to traverse to make different arrays from 1 to logval
	lli s=start-100;
	if(s<1)
	{
		s=1;
	}
	lli se=start+100;
	lli e=end-100;
	if(se>n)
		se=n;
	if(e<start+1)
		e=start+1;
	lli ee=end+100;
	if(ee>n)
		ee=n;
	int sums=seg_query(1, s-1, 1, n, 1, seg_tree);
	//cout<<"sums"<<sums<<endl;
	int sume=seg_query(1, e-1, 1, n, 1, seg_tree);
	//cout<<"sume"<<sume<<endl;
	for(lli i=s; i<=se; i++)
	{
		sums+=upni[i];
		//cout<<"sums in process"<<sums<<endl;
		while(!sta.empty())
		{
			if(sta.top().first>=arr[i]+ sums)
				break;
			else
			{
				if(i-sta.top().second>100)
				{
			//		cout<<"hello1"<<endl;
					jumparr[0][sta.top().second]=sta.top().second;
			//		cout<<"0 "<<sta.top().second<<":"<<sta.top().first<<endl;
				}
				else
				{
			//		cout<<"hello2"<<endl;
					jumparr[0][sta.top().second]=i;
			//		cout<<"0 "<<sta.top().second<<":"<<i<<endl;
				}
				sta.pop();
			}
		}
		if(i<=start)
		{
			foo=make_pair(arr[i]+sums , i);	
			sta.push(foo);
		}
		if(i==se)
		{
			while(!sta.empty())
			{
			//	cout<<"hello3"<<endl;
				jumparr[0][sta.top().second]=sta.top().second;
				sta.pop();
			}
		}
		if(i>start)
		{
			if(sta.empty())
				break;
		}
	//	sta.clear();
	}
	for(lli i=e; i<=ee; i++)
	{
		sume+=upni[i];
		//cout<<"sume in process"<<sume<<endl;
		while(!sta.empty())
		{
			if(sta.top().first>=arr[i]+sume)
				break;
			else
			{
				if(i-sta.top().second>100)
				{
			//		cout<<"hello3"<<endl;
					jumparr[0][sta.top().second]=sta.top().second;
			//		cout<<"0 "<<sta.top().second<<":"<<sta.top().first<<endl;
				}
				else
				{
				//	cout<<"hello4"<<endl;
					jumparr[0][sta.top().second]=i;
				//	cout<<"0 "<<sta.top().second<<":"<<sta.top().first<<endl;
				}
				sta.pop();
			}
		}
		if(i<=end)
		{
			foo=make_pair(arr[i]+sume , i);
			sta.push(foo);
		}
		if(i==ee)
		{
			while(!sta.empty())
			{
		//		cout<<"hello6"<<endl;
				jumparr[0][sta.top().second]=sta.top().second;
				sta.pop();
			}
		}
		if(i>end)
		{
			if(sta.empty())
				break;
		}
	//	sta.clear();
		
	}
}

lli query(lli index, lli jump, lli n)
{
	lli count=0;
	lli ans=index;
	while(jump!=0)
	{
		lli rem=jump%2;	
		if(rem==1)
		{
			lli temp;
		//	cout<<"count"<<count<<" ans"<<ans<<endl;
			temp=jumparr[count][ans];
			if(temp==n ||temp==ans)
				return temp;
			else 
				ans=temp;
		}
		jump=jump/2;
		count++;
	}
	return ans;
}
 
int  main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n, q, index, type, jump;
	lli ans;
	cin>>n>>q;
	lli arr[n+1];
	lli upni[n+1]={0};
	lli seg_tree[4*n+1]={0};
	for(lli i=1; i<=n; i++)
	{
		cin>>arr[i];
	}
	lli logval=log2(n);
	//memset(jumparr, 0, sizeof(jumparr));
	for(lli i=0; i<=17; i++)
	{
		for(lli j=0; j<=n; j++)
			jumparr[i][j]=0;
	}
		
	build(arr, n, logval);  
/*cout<<"jumparr:"<<endl;
		for(lli i=0; i<=logval; i++)
			{
				for(lli j=1; j<=n; j++)
					cout<<"[ "<<i <<", "<<j<<"]"<<jumparr[i][j]<<" ";
				cout<<endl;
			}*/
	lli count=0;
	lli block=0;
	vector<pair<lli, lli> > arq;
	pair<lli, lli> foo;
	for(lli i=1; i<=q; i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>index;
			cin>>jump;
			foo=make_pair(index, jump);	
			arq.push_back(foo);
			count++;
		}
		if(type==2 || i==q)
		{
			if(count>25)
			{
				update_jump(arr, n, logval,seg_tree);	
				lli m=0;
				while(m<arq.size())
				{
				  ans=query(arq[m].first, arq[m].second, n);
				  cout<<ans<<endl;
				  m++;
				}
				arq.clear();
			}
			else
			{
				lli m=0;
				while(m<arq.size())
				{
					index=arq[m].first;
					//cout<<"index"<<index<<endl;
					lli curr=index;
					jump=arq[m].second;
					//cout<<"jump"<<jump<<endl;
					lli ct=1;
					while(ct<=jump)
					{
						lli temp=jumparr[0][curr];
						if(temp==curr|| temp==n)
						{
							curr=temp;
						//	cout<<"break done"<<endl;
							break;
						}
						else
						{
							curr=temp;
							ct++;
						}
					}
					cout<<curr<<endl;
					m++;
				}
				arq.clear();
			}
			if(i!=q || type==2)
			{
				lli start, end, value;
				cin>>start>>end>>value;
				seg_update(start, 1, n, value, seg_tree, 1);
				if(end!=n)
					seg_update(end+1, 1, n, (-1*value), seg_tree, 1);
				upni[start]+=value;
				upni[end+1]+=(-1*value);
				update_jump0(arr, start, end, n, logval, seg_tree, upni);
			}
			count=0;
		}
		//cout<<"done"<<end
		if(i%500==0)
		{
			lli sum=0;
			for(int i=1; i<=n; i++)
			{
				sum+=upni[i];
				arr[i]+=sum;	
			}
			memset(upni, 0, sizeof(upni));
			memset(seg_tree, 0, sizeof(seg_tree));
		}
	}
	return 0;
}
