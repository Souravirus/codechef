#include<bits/stdc++.h>
#define mp make_pair
typedef long long int lli;
using namespace std;
pair<lli, lli>foo;
class hdd
{
	lli capacity;
	lli	cost;
	lli rCost;
	lli wCost;
	
	public:
		void getdata( lli cost, lli rCost, lliwCost, llicap)
		{
			this->capacity=cap;
			this->cost=cost;
			this->rCost=rCost;
			this->wCost=wCost;
		}
};

class client
{
	map<lli, pair<lli, lli> > hddmap;

	public:
		void getdata(lli hddindex, lli start, lliend)
		{
			foo=mp(start, end);
			this->hddmap.insert(pair<lli, pair<lli, lli> >(hddindex, foo));	
		}
};

lli category_det(llistore, lli index, llicrash, lli pos)
{
	if(store/pos>=0.7)
	{
		return 4;
	}
	else if((store/pos)>=0.6)
	{
		return 3;
	}
	else if(store/pos>=0.5 && index<=0.45)
		return 2;
	else if(store/pos>=0.4 && index>=0.5)
		return 6;
	else if(store/pos>=0.35)
		return 5;
	else
		return 1;	
}
lli hddSelector(float storeper, float indexper, float crashper, lli H, lli cost[], lli wCost[], lli capacity[], lli lower_limit, lli N, lli pos)
{
	map<lli, lli> mymap;
	map<lli, lli> ::iterator itm;
	for(lli i=1; i<=H; i++)
	{
		lli tCost=cost[i]+((crashper*(N-pos)+2)*wCost[i]*storeper*total)+((crashper*(N-pos)+1)*storeper*total*rCost[i])+(indexper*(N-pos)*rCost[i]);

		map.insert(pair<lli, lli>(tcost, i));
	}
	for(itm=mymap.begin(); itm!=mymap.end(); itm++)
	{		
		if(capacity[itm->second]*1050>lower_limit)
			return itm->second;
	}
	return -1;
}
					
int main()
{
	lli  H, penalty;
	float N;
	hdd harr[1050];
	client carr[100000];
	lli cost[H], capacity[H], rCost[H], wCost[H];
	cin>>N>>H;
	lli maxc=0;
	for(lli i=1; i<=H; i++)		
	{
		cin>>cost[i];
		cin>>rCost[i];
		cin>>wCost[i];
		cin>>capacity[i];
		if(i!=0 && capacity[i]>capacity[maxc])
		{
			maxc=i;	
		}
	}	
	cin>>penalty;
	float  store=0, index=0,crash=0, count=0;	
	lli empty=1, prev=0, category=0, hddselect;
	float fiveper=N*(0.05);
	//cout<<"fiveper"<<fiveper<<endl;
	lli type, cid, hid, num;
	for(lli i=1; i<=N; i++)
	{
		count+=1;
		cin>>type;
		if(type==0)
		{
			cin>>cid>>num;
			store++;
			if(empty) 
			{
				category=category_det(store, index, crash, count);
				//cout<<"category"<<category<<endl;
				prev=i;
				float storeper=store/i;
				if(category==1)
				{						
					lli lower_limit=((N)*0.2-store)*1000;
					hddselect=hddSelector(0.2, 0.7, 0.1, H, cost, capacity, rCost, wCost, lower_limit, N, i );   
					
				}
				else if(category==2)
				{
					lli lower_limit=((N)*0.5-store)*1000;
					hddselect=hddSelector(0.5, 0.45, 0.05, H, cost, capacity, rCost, wCost, lower_limit, N, i);
				}
				empty=0;
				else if(category==3)
				{
					lli lower_limit=(N*0.6-store)*1000;
					hddselect=hddSelector(0.6, 0.35, 0.05, H, cost, capacity, rCost, wCost, lower_limit, N, i);
				}
				else if(category==4)
				{
					lli lower_limit=(N*0.7-store)*1000;
					hddselect=hddSelector(0.7, 0.20, 0.1, H, cost, capacity, rCost, wCost, lower_limit, N, i);
				}
				else if(category==5)
				{
					lli lower_limit=(N*0.35-store)*100;
					hddselect=hddSelector(0.35, 0.50, 0.15, H, cost, capacity, rCost, wCost, lower_limit, N, i);
				}
				else if(category==6)
				{
					lli lower_limit=(N*0.49-store)*1000;
					hddselect=hddSelector(0.49, 0.50, 0.01, H, cost, capacity, rCost, wCost, lower_limit, N, i);
				}
				if(hddselect!=-1)
				{
					cout<<"p b "<<hddselect-1<<endl;
				}
				else
				{
					cout<<"p b "<<maxc<<endl;
				}
			}
		}
		if(type==1)
		{
		}
		if(type==2)
		{
		}
	}
	return 0;
}
