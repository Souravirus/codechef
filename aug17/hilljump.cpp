#include<bits/stdc++.h>
using namespace std;

int jumparr[17][100001];
//make the update function and query function of segmented tree

void build(int arr[], int n, int logval)
{
	//first loop is to traverse to make different arrays from 1 to logval
	for(int i=0; i<=logval; i++)
	{
		int jumpcount=pow(2, i);
		//cout<<"for jumpcount "<<jumpcount<<endl;
		//second loop is to make different elements of that array
		for(int j=1; j<=n; j++)
		{
			int cnt=0;
			int indcnt=j;
			int diff=0;
			int flag=0;
			while(cnt<jumpcount && indcnt<=n )
			{
				//cout<<"current indcnt "<<indcnt<<endl;
				if(diff>=100 || indcnt>n)
				{
				//	cout<<"breaking away"<<endl;
					break;
				}	
				else if(arr[j]<arr[indcnt])
				{
					jumparr[i][j]=indcnt;
					//cout<<"in correct if"<<endl;
					cnt++;
					//cout<<"cnt increased to "<<cnt<<endl;
					diff=0;
				}
				else
				{
					//cout<<"nothing happened"<<endl;
					diff++;
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
int seg_query(int l, int r, int s, int e, int node_num, int seg_tree[])
{
	if(s>r|| e<l)
		return 0;
	else if(s>=l && e<=r)
		return seg_tree[node_num];
	else
	{
		int m=(s+e)/2;
		return seg_query(l, r, s, m , node_num*2, seg_tree) + seg_query(l, r, m+1, e, node_num*2+1, seg_tree);
	}
}

void seg_update(int pos, int s, int e, int value, int seg_tree[], int node_num)
{
	if(s==e)
	{
		seg_tree[node_num]+=value;
		return ;
	}
	int mid=(s+e)/2;	
	if(mid<pos)
	{
		seg_update(pos, mid+1, e, value, seg_tree, node_num*2+1);
	}
	else
		seg_update(pos, s, mid, value, seg_tree, node_num*2);
	seg_tree[node_num]=seg_tree[node_num*2]+seg_tree[node_num*2+1];
}

void update_jump(int arr[], int upni[], int n, int logval, int s, int e, int seg_tree[]){ 
	int start,  end;
	//first loop is to traverse to make different arrays from 1 to logval
	for(int i=0; i<=logval; i++)
	{
		int jumpcount=pow(2, i);
		 start=(s-jumpcount*100);
		if(start<1)
		{
			start=1;
		}
		 cout<<"start"<<start<<endl;
		end=e-jumpcount*100;
		if(end<s)
		{
			end=s+1;	
		}
		cout<<"end"<<end<<endl;
		//second loop is to make different elements of that array
		for(int j=start; j<=s; j++)
		{
			int numupd=seg_query(0, start, 0, n, 0, seg_tree);
			int jupd=seg_query(0, s, 0, n, 0, seg_tree);
			int cnt=0;
			int indcnt=j;
			int diff=0;
			int flag=0;
			jumparr[i][j]=0;
			cout<<"i "<<i<<"j "<<j<<endl;
			while(cnt<jumpcount && indcnt<=n )
			{
				numupd+=upni[indcnt];
				cout<<"numupd"<<numupd<<endl;
				cout<<"current indcnt "<<indcnt<<endl;
				if(diff>=100 || indcnt>n)
				{
					cout<<"breaking away"<<endl;
					break;
				}	
				else if(arr[j]+seg_query(0, j, 0, n, 0, seg_tree)<arr[indcnt]+seg_query(0, indcnt, 0, n, 0, seg_tree))
				{

				cout<<"Putiing "<<j<<" at"<<"i "<<i<<"j "<<indcnt<<endl;
					jumparr[i][j]=indcnt;
					cout<<"in correct if"<<endl;
					cnt++;
					cout<<"cnt increased to "<<cnt<<endl;
					diff=0;
				}
				else
				{
					cout<<"nothing happened"<<endl;
					diff++;
				}
				indcnt++;
			}
			if(jumparr[i][j]==0)
			{
				cout<<"Putiing "<<j<<" at"<<"i "<<i<<"j "<<j<<endl;
				jumparr[i][j]=j;
			}
		}
		for(int j=end; j<=e; j++)
		{
			int numupd=0;
			int cnt=0;
			int indcnt=j;
			int diff=0;
			int flag=0;
			while(cnt<jumpcount && indcnt<=n )
			{
				numupd+=upni[indcnt];
				//cout<<"current indcnt "<<indcnt<<endl;
				if(diff>=100 || indcnt>n)
				{
				//	cout<<"breaking away"<<endl;
					break;
				}	
				else if(arr[j]+numupd<arr[indcnt]+numupd)
				{
					jumparr[i][j]=indcnt;
					//cout<<"in correct if"<<endl;
					cnt++;
					//cout<<"cnt increased to "<<cnt<<endl;
					diff=0;
				}
				else
				{
					//cout<<"nothing happened"<<endl;
					diff++;
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

int query(int index, int jump, int n)
{
	int count=0;
	int ans=index;
	while(jump!=0)
	{
		int rem=jump%2;	
		if(rem==1)
		{
			int temp;
		//	cout<<"count"<<count<<" ans"<<ans<<endl;
			temp=jumparr[count][ans];
			if(temp==ans || temp==n)
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
	int n, q, index, type, jump, ans;
	cin>>n>>q;
	int arr[n+1];
	int upni[n+1];
	int seg_tree[4*n]={0};
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		upni[i]=0;
	}
	int logval=log2(n);
	memset(jumparr, 0, sizeof(jumparr));
		
	build(arr, n, logval);  
	for(int i=1; i<=q; i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>index;
			cin>>jump;
			ans=query(index, jump, n);
			cout<<ans<<endl;
		}
		else{
			int start;
			int end, value;
			cin>>start>>end>>value;
			seg_update(start, 1, n, value, seg_tree, 0);
			seg_update(end, 1, n, -1*value, seg_tree, 0);
			cout<<"seg tree printing"<<endl;
			for(int i=0; i<=n; i++)
			{
				cout<<seg_tree[i]<<endl;
			}
			update_jump(arr, upni, n, logval, start, end, seg_tree);
			//cout<<"after update"<<endl;
			for(int i=0; i<=logval; i++)
			{
				for(int j=1; j<=n; j++)
					cout<<"[ "<<i <<", "<<j<<"]"<<jumparr[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	return 0;
}
