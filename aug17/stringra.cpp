#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >:: iterator itvp;
map<int, int >mymap;
map<int, int >mymap2;
map<int, int >::iterator itm;
int linear_chk(vector <pair<int, int> >vp, int n)
{
	int tflag=0;
	itvp=vp.begin();
	for(int i=0; i<n; i++)
	{
		int flag=0;
			while(itvp!=vp.end() && itvp->first==i )
			{
			//	cout<<"itvp first "<<itvp->first<<"itvp->second "<<itvp->second<<endl;
				if(itvp->second==i+1)
				{
					flag=1;
					break;
				}
				itvp++;
			}
		if(flag==0)
		{
		//	cout<<"flag exe for"<<" "<<i<<endl;
			tflag=1;
			break;
		}
	}
	if(tflag==1)
		return 0;
	else 
		return 1;
}

int master(vector<pair<int, int> >vp,int  n, int *arr)
{
	int turn=0;
	itvp=vp.begin();
	int count=0;
	while(count<n)
	{
		int flag=0;
		if(count==0)
		{
			int countnum=1;
			if(!vp.empty())
			{
				while(itvp!=vp.end() && itvp->first==count )		
				{
					mymap.insert(pair<int, int >(itvp->second, countnum));
					arr[(itvp->second)-1]=countnum;
					countnum++;			
					itvp++;
					if(itvp==vp.end())
						break;
				}
			}
		}
		else{
			if(turn%2==0)
			{
				while(itvp!=vp.end() && itvp->first==count)	
				{
					itm=mymap.begin();
					if(arr[itvp->second-1]==0 && itm!=mymap.end())
					{
						if(itvp->second>itm->first)
						{
							int countnum=itm->second;
							mymap.erase(mymap.begin());
							mymap2.insert(pair<int, int>(itvp->second, countnum));
							arr[(itvp->second)-1]=countnum;
						}
						else
						{
							flag=1;	
							return -1;
						}
					}
					else
					{
						itm=mymap.find(itvp->second);
						if(itm!=mymap.end())
						{
							mymap.erase(itm);
							mymap2.insert(pair<int, int>(itm->first, itm->second));
						}
					}
					itvp++;	
					if(itvp==vp.end())
						break;
				}
				mymap.clear();
			}
			if(turn%2==1)
			{
				while(itvp!=vp.end() && itvp->first==count )	
				{
					itm=mymap2.begin();
					if(arr[itvp->second-1]==0 && itm!=mymap2.end())
					{
						if(itvp->second>itm->first)
						{
							int countnum=itm->second;
							mymap2.erase(mymap2.begin());
							mymap.insert(pair<int, int>(itvp->second, countnum));
							arr[(itvp->second)-1]=countnum;
						}
						else
						{
							flag=1;	
							return -1;
						}
					}
					else
					{
						itm=mymap2.find(itvp->second);
						if(itm!=mymap2.end())
						{
							mymap.insert(pair<int, int>(itm->first, itm->second));
						}
					}
					itvp++;	
					if(itvp==vp.end())
						break;
				}
				mymap2.clear();
			}
			turn++;
		}
		if(flag==1)
			return -1;
		count++;
	}
	return 1;
}

int filter(int *chk, int arr[], int n, int m)
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=i+1-chk[arr[i]];
		chk[arr[i]]=i+1;
	}
	//cout<<"sum"<<sum<<endl;
	if(sum==m)
		return 1;
	else
		return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;
	cin>>t;
	while(t--)
	{
		mymap.clear();
		mymap2.clear();
		vector<pair<int, int> >vp;
		pair<int, int> foo;
		cin>>n>>m;
		int arr[n];
		for(int i=0; i<n; i++)
			arr[i]=0;
		int flag=0;
		int flag1=0;
		int x, y;
		for(int i=0; i<m; i++)
		{
			cin>>x>>y;
			if(x>=y)
			{
				flag=1;
			}
			foo=make_pair(x, y);	
			vp.push_back(foo);
		}
		if(flag==1)
			cout<<"-1"<<endl;
		else
		{
			sort(vp.begin(), vp.end());
			//cout<<"printing the pairs sorted"<<endl;
		/*	for(int i=0; i<m; i++)
			{
				cout<<vp[i].first<<" "<<vp[i].second<<endl;
			}*/
			//int check=linear_chk(vp, n);
			int ans;
			//cout<<"chk"<<chk<<endl;
			//if(check==0)
			//	flag1=1;
			//else
			//{
				ans=master(vp, n, arr);		
			//}
			if(ans==-1)
				flag1=1;
			else if(ans==1)
			{
				int approve;
				int chk[2*n]={0};
				 approve=filter(chk, arr, n, m);	
				if(approve==1)
				{
					for(int i=0; i<n; i++)
						cout<<arr[i]<<" ";
				}
				else
					flag1=1;
			}
			if(flag1==1)
			{
				cout<<"-1";
			}
			cout<<endl;
		}
	}
	return 0;
}
