#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, N, K, len,num, count, total;
	cin>>T;
	while(T--){
		cin>>N>>K;
		unordered_map<int, set<int> >mymap;
		unordered_map<int, set<int> >::iterator itm;
		set<int> :: iterator its;
		set<int> :: iterator its2;
		int **arr=new int*[N+1];
		for(int i=1;i<=N;i++){
			arr[i]=new int[K+1];
		}
		for(int i=1;i<=N;i++){
			for(int j=0;j<=K;j++)
				arr[i][j]=0;
		}
		for(int i=1;i<=N;i++){
			//cout<<"hello";
			scanf("%d", &len);
			count=0;
			for(int j=1;j<=len;j++)
			{
				scanf("%d", &num);
				if(arr[i][num]==0)
				{
					arr[i][num]=1;
					count++;
					itm=mymap.find(num);
				//	cout<<"now inserting in map index "<< num<< ":"<<i<<endl;
					if(itm!=mymap.end()){
						itm->second.insert(i);
					}
					else{
						set<int> s;
						s.insert(i);
						mymap.insert(pair<int, set<int> >(num, s));
					}
				}
			}
			arr[i][0]=count;
		}
		
		//next phase
		total=0;
		for(int i=1; i<=N; i++){
			//cout<<"in the main loop"<<endl;
			if(arr[i][0]==K){
			//	cout<<"I am already full"<<endl;
				total+=N-i;		
				continue;
			}
			count=0;
			set<int > myset;
			for(int j=1;j<=K;j++){
			//	cout<<"in the second loop"<<endl;
				if(count==K-arr[i][0])
				{
				//	cout<<"count finished total counted"<<endl;
					if(!myset.empty())
						total+=myset.size();
					myset.clear();
					break;
				}
				else{
				//	cout<<"Count still not finished count:"<<count<<endl;
					if(arr[i][j]==0){
						if(count==0){
						//	cout<<"count now started to increase"<<endl;
							itm=mymap.find(j);
							if(itm==mymap.end())
							{
								//cout<<"there is no entry for this j"<<j<<endl;
								break;
							}
							else{
								
								for(its=itm->second.lower_bound(i);its!=itm->second.end();its++){
								//	cout<<"inserting in myset "<<*its<<endl;
									myset.insert(*its);
								}
							}
						}
						else{
							//cout<<"count still increasing"<<endl;
							itm=mymap.find(j);
							if(itm==mymap.end()){
							//	cout<<"there is no entry for this j"<<j<<endl;
								break;
							}
							else{
								int flag=0;
								for(its=myset.begin();its!=myset.end();its++){
									its2=itm->second.find(*its);
									if(its2!=itm->second.end())
									{
									//	cout<<"Element found in map index:"<<j<<" element:"<<*its;
										flag=1;
									}
									else{
									//	cout<<"This element not found in map index:"<<j<<" element:"<<*its;
										myset.erase(its);
									}
								}
								if(flag==0)
									break;
							}
						}
						count++;
					}
				}
				if(j==K){
					//cout<<"total added due to end of set"<<endl;
					if(!myset.empty())
						total+=myset.size();	
					myset.clear();
				}
			}
		}
		cout<<total<<endl;
	}
	return 0;
}
