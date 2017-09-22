#include<bits/stdc++.h>
#define mp make_pair
typedef long long int lli;
using namespace std;
pair<lli, lli>foo;
class hdd
{
//updated here
	lli hddtype; 
	lli indcon; 
	lli empty;
	map<lli, pair<lli,lli> >clientmap; 
	
	public:
		hdd()
		{
			this->hddtype=0;
			this->indcon=0;
			this->empty=1;
		}
		void getdata(int type) 
		{
			this->hddtype=type;
			this->indcon=0;
			this->empty=0;
		}
		void pushMap(lli clientid, lli startind, lli endind)
		{
			foo=make_pair(startind, endind);
			this->clientmap.insert(pair<lli, pair<lli,lli> >(clientid, foo));
			this->indcon=endind+1;
		}
		lli givePosition(lli clientid, lli diff)
		{
			map<lli, pair<lli,lli> >::iterator itm; 
			itm=clientmap.find(clientid);
			if(itm!=clientmap.end())
			{
				return itm->second.first+diff;	
			}

		}
		int indconEnq(){
			return indcon; 
		}
		int emptyEnq(){
			return empty; 
		}
		int hddTypeEnq()
		{
			return hddtype;
		}
};

class client
{
	map<lli, pair<lli, lli> > hddmap;

	public:
		void getdata(lli start, lli end, lli hddindex)
		{
			foo=mp(end, hddindex);
			this->hddmap.insert(pair<lli, pair<lli, lli> >(start, foo));	
		}
		int hddmapEnq()
		{
			if(hddmap.empty())
			{
				return 1;
			}
			else 
				return 0;
		}
		pair<lli, lli> lowerEnq(lli num)
		{
			map<lli, pair<lli, lli> >:: iterator itm;
			itm=hddmap.upper_bound(num);
			itm--;
			if(itm==hddmap.end() || itm->second.first<num )
			{
				foo=mp(-1,-1);
				return foo;
			}
			else
			{
				 foo=mp(itm->first, itm->second.second);
				 return foo;
			}
		}
		void print()
		{
			map<lli, pair<lli, lli> >:: iterator itm;
			cout<<"map elements"<<endl;
			for(itm=hddmap.begin(); itm!=hddmap.end(); itm++)
			{
				cout<<itm->first<<" "<<itm->second.first<<" "<<itm->second.second<<endl;
			}
		}
};

lli category_det(lli store, lli index, lli crash, lli pos)
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
lli hddSelector(float storeper, float indexper, float crashper, lli H, lli cost[], lli rCost[], lli wCost[], lli capacity[], lli lower_limit, float N, float pos)
{
	map<lli, lli> mymap;
	map<lli, lli> ::iterator itm;
	for(lli i=1; i<=H; i++)
	{
		lli tCost=cost[i]+((crashper*(N-pos)+2)*wCost[i]*storeper*(N-pos))+((crashper*(N-pos)+1)*storeper*(N-pos)*rCost[i])+(indexper*(N-pos)*rCost[i]);

		mymap.insert(pair<lli, lli>(tCost, i));
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
	hdd harr[1051];
	for(int i=1; i<=1050; i++)
	{
		harr[i]=hdd();
	}
	client carr[100001];
	
	cin>>N>>H;
	lli cost[H+1], capacity[H+1], rCost[H+1], wCost[H+1];
	lli maxc=1;
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
	lli empty=1, prev=0, category=0, hddselect, counthdd=1;
	float fiveper=N*(0.05);
	//cout<<"fiveper"<<fiveper<<endl;
	lli type, cid, hid, num;
	for(lli i=1; i<=N; i++)
	{
		count+=1;
		if(empty && counthdd<=1050) 
			{
				category=category_det(store, index, crash, count);
				//cout<<"category"<<category<<endl;
				prev=i;
				float storeper=store/i;
				if(category==1)
				{						
					lli lower_limit=((N)*0.2-store)*1000;
					hddselect=hddSelector(0.2, 0.7, 0.1, H, cost, capacity, rCost, wCost, lower_limit, N, count );   
					
				}
				else if(category==2)
				{
					lli lower_limit=((N)*0.5-store)*1000;
					hddselect=hddSelector(0.5, 0.45, 0.05, H, cost, capacity, rCost, wCost, lower_limit, N, count);
				}
				else if(category==3)
				{
					lli lower_limit=(N*0.6-store)*1000;
					hddselect=hddSelector(0.6, 0.35, 0.05, H, cost, capacity, rCost, wCost, lower_limit, N, count);
				}
				else if(category==4)
				{
					lli lower_limit=(N*0.7-store)*1000;
					hddselect=hddSelector(0.7, 0.20, 0.1, H, cost, capacity, rCost, wCost, lower_limit, N, count);
				}
				else if(category==5)
				{
					lli lower_limit=(N*0.35-store)*100;
					hddselect=hddSelector(0.35, 0.50, 0.15, H, cost, capacity, rCost, wCost, lower_limit, N, count);
				}
				else if(category==6)
				{
					lli lower_limit=(N*0.49-store)*1000;
					hddselect=hddSelector(0.49, 0.50, 0.01, H, cost, capacity, rCost, wCost, lower_limit, N, count);
				}
				if(hddselect!=-1)
				{
					//cout<<"hddselect"<<hddselect<<endl;
					cout<<"p b "<<hddselect-1<<endl;
					cout<<"p b "<<hddselect-1<<endl;
					empty=0;
					harr[counthdd].getdata(hddselect);	
					harr[counthdd+1].getdata(hddselect);	
					//I have to update here so that remaining num gets into a new disc
				}
				else
				{
					cout<<"p b "<<maxc-1<<endl;
					cout<<"p b "<<maxc-1<<endl;
					empty=0;
					harr[counthdd].getdata(maxc);	
					harr[counthdd+1].getdata(maxc);	
					//I have to update here so that remaining num gets into a new disc
					
				}
			}
		map<lli, lli> maprem;
		map<lli, lli> :: iterator itmr;
		cout<<"g"<<endl;
		cin>>type;
		if(type==0)
		{
			//cout<<"hello"<<endl;
			cin>>cid>>num;
			store++;
			if(counthdd<=1050)
			{
				int currind=harr[counthdd].indconEnq();
				int tspace=capacity[harr[counthdd].hddTypeEnq()];
				int available=tspace-currind;
				if(available>=num)
				{
					harr[counthdd].pushMap(cid, currind, currind+num-1); 
					harr[counthdd+1].pushMap(cid, currind, currind+num-1); 
					carr[cid].getdata(0, num, counthdd);
					cout<<"p s "<<counthdd-1<<" "<<currind<<endl;
					cout<<"p cp "<<counthdd-1<<" "<<currind<<" "<<num<<" "<<counthdd<<" "<<currind<<endl;
				}
				else
				{
					cout<<"p s -1 -1"<<endl;
				}
				currind=harr[counthdd].indconEnq();
				available=tspace-currind;
				maprem.insert(pair<lli, lli>(available, counthdd));
				if(available<1000 && capacity[maxc]>=available)
				{
					empty=1;
					counthdd+=2;
				}
			}
			else
			{
				itmr=maprem.lower_bound(num);
				if(itmr==maprem.end())
				{
						
				}
				else
				{
					int currind=harr[itmr->second].indconEnq();
					int tspace=capacity[harr[itmr->second].hddTypeEnq()];
					int available=tspace-currind;
					if(available>=num)
					{
						harr[itmr->second].pushMap(cid, currind, currind+num-1); 
						harr[itmr->second+1].pushMap(cid, currind, currind+num-1); 
						carr[cid].getdata(0, num, itmr->second);
						cout<<"p s "<<itmr->second-1<<" "<<currind<<endl;
						cout<<"p cp "<<itmr->second-1<<" "<<currind<<" "<<num<<" "<<itmr->second<<" "<<currind<<endl;
					}
					currind=harr[itmr->second].indconEnq();
					available=tspace-currind;
					int remind=itmr->second;
					maprem.erase(itmr);
					maprem.insert(pair<lli, lli>(available, remind));
				}
			}
			//carr[cid].print();
		}
		
		else if(type==1)
		{
			cin>>cid>>num;
			if(carr[cid].hddmapEnq())
			{
			//	cout<<"printing up"<<endl;
				cout<<"p i -1 -1"<<endl;
			}
			else
			{
				foo=carr[cid].lowerEnq(num);
				if(foo.first==-1)
				{
			//		cout<<"printing second"<<endl;
					cout<<"p i -1 -1"<<endl;
				}
				else
				{
					lli diff=num-foo.first;			
					int cellpos=harr[foo.second].givePosition(cid,diff); 		
					cout<<"p i "<<foo.second-1<<" "<<cellpos<<endl;
				}
			}
                      //  cout<<"p i -1 -1"<<endl;
			index++;
		}
		else if(type==2)
		{
			cin>>hid;
			crash++;
			if(hid%2==1)
				cout<<"p cp "<<hid-1<<" 0 "<<capacity[harr[hid].hddTypeEnq()]<<" "<<hid<<" 0"<<endl;
			else
				cout<<"p cp "<<hid+1<<" 0 "<<capacity[harr[hid+2].hddTypeEnq()]<<" "<<hid<<" 0"<<endl;
		}
	}	
	cout<<"end"<<endl; 
	return 0;
}
