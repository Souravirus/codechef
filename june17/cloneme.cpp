#include<bits/stdc++.h>
using namespace std;
struct seg{
	seg *left;
	seg *right;
	map<int, int> mymap;
};
seg *build( int s, int e, int A[]){
	seg *node=new seg();
	node->right=NULL;
	node->left=NULL;
	map<int, int>:: iterator itm;
	map<int, int>:: iterator itm2;
	if(s==e){
		node->mymap.insert(pair<int, int>(A[s], 1));
		return node;
	}
	int m;
	m=(s+e)/2;
	node->left=build(s, m, A);
	node->right=build(m+1, e, A);
	if(node->left!=NULL){
		node->mymap=node->left->mymap;
	}
	if(node->right!=NULL){
		for(itm=node->right->mymap.begin();itm!=node->right->mymap.end();itm++)
		{
			itm2=node->mymap.find(itm->first);
			if(itm2==node->mymap.end()){
				node->mymap.insert(pair<int, int>(itm->first, itm->second));	
			}
			else
				itm2->second+=itm->second;
		}
	}
	return node;
}

map<int, int> query( int L, int R, int s, int e, seg *link){
	map<int, int>mymap;
	map<int, int>mymap2;
	map<int, int>:: iterator itm1;
	map<int, int>:: iterator itm2;
	if(L>e|| R<s)
		return mymap;
	else if(L<=s && R>=e){
		if(link){
			return link->mymap;
		}
		else
			return mymap;
	}
	else{
		int m=(s+e)/2;
		if(link){
			mymap=query(L, R, s, m, link->left);
			mymap2=query(L, R, m+1, e, link->right);
			if(mymap.empty())
				return mymap2;
			else if(mymap2.empty())
				return mymap;
			else{
				for(itm1=mymap.begin(); itm1!=mymap.end(); itm1++){
					itm2=mymap2.find(itm1->first);
					if(itm2==mymap2.end()){
						mymap2.insert(pair<int, int>(itm1->first, itm1->second));
					}
					else
						itm2->second+=itm1->second;
				}
				return mymap2;
			}
		}
	}
}

int main(){
	int T, N, Q, A[1000001], a1, a2, b1, b2;
	map<int, int> mapq1;
	map<int, int>mapq2;
	map<int, int>:: iterator itm1;
	map<int, int>:: iterator itm2;
	seg *root = NULL;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		for(int i=1;i<=N;i++){
			cin>>A[i];
		}
		root=build(1, N, A);
		for(int i=1;i<=Q;i++){
			cin>>a1>>b1>>a2>>b2;
			mapq1=query(a1, b1, 1, N, root);
			mapq2=query(a2, b2, 1, N, root);
		/*	cout<<"first map details"<<endl;
			for(itm1=mapq1.begin(); itm1!=mapq1.end();itm1++)
			{
				cout<<itm1->first<<" "<<itm1->second<<endl;
			}
			cout<<"2 map det"<<endl;
			for(itm1=mapq2.begin(); itm1!=mapq2.end();itm1++)
			{
				cout<<itm1->first<<" "<<itm1->second<<endl;
			}
			*/
			int flag1=0;
			int flagout=0;
			if(mapq1.size()==mapq2.size()){
				itm1=mapq1.begin();
				itm2=mapq2.begin();
				while(itm1!=mapq1.end() && itm2!=mapq2.end()){
					if(itm1->first==itm2->first){
						if(itm1->second==itm2->second){
							itm1++;
							itm2++;
						}
						else if(itm1->second>itm2->second)
						{
							itm1->second-=itm2->second;
							itm2++;
						}
						else{
							itm2->second-=itm1->second;
							itm1++;
						}
					}
					else{
						if(itm1->second==itm2->second){
							if(itm1->second>=2)
							{
								flagout=1;
								break;
							}
							else if(itm1->second==1 && !flag1)
							{
								flag1=1;
								itm1++;
								itm2++;
							}		
							else if(itm1->second==1 && flag1)
							{
								flagout=1;
								break;
							}
						}
						else if(itm1->second>itm2->second){
							if(itm2->second>=2){
								flagout=1;
								break;
							}
							else if(itm2->second==1 && !flag1)
							{
								flag1=1;
								itm1->second-=itm2->second;
								itm2++;
							}
							else if(itm2->second==1 && flag1){
								flagout=1;
								break;
							}
						}
						else{
							if(itm1->second>=2){
								flagout=1;
								break;
							}
							else if(itm1->second==1 && !flag1)
							{
								flag1=1;
								itm2->second-=itm1->second;
								itm1++;
							}
							else if(itm1->second==1 && flag1){
								flagout=1;
								break;
							}
						}
					}
				}
			}
			else{
				flagout=1;
			}
			if(flagout)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
	return 0;
}
