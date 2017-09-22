#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli jumparr[20][100001];
//make the update function and query function of segmented tree

void build(lli arr[], lli n, lli logval)
{
	//first loop is to traverse to make different arrays from 1 to logval
	for(lli i=0; i<=logval; i++)
	{
		lli jumpcount=pow(2, i);
		//cout<<"for jumpcount "<<jumpcount<<endl;
		//second loop is to make different elements of that array
		for(lli j=1; j<=n; j++)
		{
			lli cnt=0;
			lli curr=j;
			lli indcnt=j+1;
			lli flag=0;
			while(cnt<jumpcount && indcnt<=n )
			{
				//cout<<"current indcnt "<<indcnt<<endl;
				if(indcnt-curr>=100 || indcnt>n)
				{
				//	cout<<"breaking away"<<endl;
					break;
				}	
				else if(arr[curr]<arr[indcnt])
				{
					jumparr[i][j]=indcnt;
					//cout<<"in correct if"<<endl;
					cnt++;
					curr=indcnt;
					//cout<<"cnt increased to "<<cnt<<endl;
				}
				indcnt++;
			}
			if(jumparr[i][j]==0)
			{
				//cout<<"Putiing some thing here "<<endl;
				jumparr[i][j]=j;
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

void update_jump(lli arr[], lli n, lli logval,lli seg_tree[], lli num){ 
	//first loop is to traverse to make different arrays from 1 to logval
	lli i=num;
		lli jumpcount=pow(2, i);
		for(lli j=1; j<=n; j++)
		{
			lli curr=j;
			lli cnt=0;
			lli indcnt=j+1;
			lli diff=0;
			lli flag=0;
			jumparr[i][j]=0;
//			cout<<"i "<<i<<"j "<<j<<endl;
			while(cnt<jumpcount && indcnt<=n)
			{
				if(indcnt-curr>=100 )
				{
//					cout<<"breaking away"<<endl;
					break;
				}	
				else if(arr[curr]+seg_query(1, curr, 1, n, 1, seg_tree)<arr[indcnt]+seg_query(1, indcnt, 1, n, 1, seg_tree))
				{

//					cout<<"Putiing "<<indcnt<<" at"<<"i "<<i<<"j "<<j<<endl;
					jumparr[i][j]=indcnt;
				//	cout<<"in correct if"<<endl;
					cnt++;
					curr=indcnt;
//					cout<<"cnt increased to "<<cnt<<endl;
				}

				indcnt++;
			}
			if(jumparr[i][j]==0)
			{
//				cout<<"Putiing "<<j<<" at"<<"i "<<i<<"j due to 0"<<j<<endl;
				jumparr[i][j]=j;
			}
		}
		jumparr[i][0]=1;
}

lli query(lli index, lli jump, lli n, lli arr[], lli logval, lli seg_tree[])
{
	lli count=0;
	lli ans=index;
	while(jump!=0)
	{
		lli rem=jump%2;	
		if(rem==1)
		{
			lli temp;
//		cout<<"count"<<count<<" ans"<<ans<<endl;
			if(jumparr[count][0]==0)
			{
				update_jump(arr, n, logval,seg_tree, count); 
			}
			temp=jumparr[count][ans];
			if(temp==n)
				return temp;
			else 
				ans=temp;
		}
		jump=jump/2;
		count++;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n, q, index, type, jump;
	lli ans;
	cin>>n>>q;
	lli arr[n+1];
	lli seg_tree[4*n+1]={0};
	for(lli i=1; i<=n; i++)
	{
		cin>>arr[i];
	}
	lli logval=log2(n);
	//memset(jumparr, 0, sizeof(jumparr));
	for(lli i=0; i<=logval; i++)
	{
		for(lli j=1; j<=n; j++)
			jumparr[i][j]=1;
	}
		
	build(arr, n, logval);  
	for(lli l=0; l<=logval; l++)
	{
		jumparr[l][0]=1;
	}
/*	cout<<"jumparr:"<<endl;
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
		//	cout<<"pushing elements"<<endl;
			arq.push_back(foo);
			count++;
		}
		if(type==2 || i==q)
		{
		//	cout<<"hello"<<endl;
			if(count>20)
			{
				lli m=0;
				while(m<arq.size())
				{
				  ans=query(arq[m].first, arq[m].second, n, arr, logval, seg_tree );
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
					lli k=index+1;
					lli count=0;
					lli diff=0;
					while(count<jump && k<=n)
					{
						//cout<<"seg queries"<<seg_query(1, curr, 1, n, 1, seg_tree)<<" "<<seg_query(1,k, 1, n, 1, seg_tree)<<endl;
						if(arr[curr]+seg_query(1, curr, 1, n, 1, seg_tree)<arr[k]+seg_query(1,k, 1, n, 1, seg_tree))
						{
							curr=k;
							count++;
						}	
						if(k-curr>=100)
						{
							break;
						}
						k++;
					}
					cout<<curr<<endl;
					m++;
				}
				arq.clear();
			}
			if(i!=q)
			{
				lli start, end, value;
				cin>>start>>end>>value;
				seg_update(start, 1, n, value, seg_tree, 1);
				if(end!=n)
					seg_update(end+1, 1, n, (-1*value), seg_tree, 1);
			//	cout<<"update in process"<<endl;
				for(lli l=0; l<=logval; l++)
				{
					jumparr[l][0]=0;
				}
			}
			count=0;
			//cout<<"update done"<<endl;
		}
		
	}
	return 0;
}
