#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
struct seg{
	seg *left;
	seg *right;
	map<int, int> umap;
};

struct seg *build(int s, int e, int sp[],int A[]){
	seg *node=new seg();
	node->right=NULL;
	node->left=NULL;
	//cout<<"inserting at "<<s<<" "<<e<<endl;
	map<int, int> :: iterator itm;
	map<int, int> :: iterator itm2;
	if(s==e){
		//cout<<" they are equal"<<endl;
		int B=A[s];	
		node->umap.insert(pair<int, int>(sp[B], 1));
		/*while(B!=1){
			if(sp[B]==0)
				sp[B]=B;
			itm=node->umap.find(sp[B]);
			if(itm==node->umap.end()){
				
			}
			else
				itm->second++;
			B/=sp[B];		
		}*/
		return node;
	}
	int m;
	m=(s+e)/2;
	node->left=build(s, m, sp, A);
	node->right=build(m+1, e, sp, A); 
	if(node->left!=NULL)
		node->umap.insert(node->left->umap.begin(),node->left->umap.end());
	if(node->right!=NULL)
		for(itm=node->right->umap.begin();itm!=node->right->umap.end();itm++){
			itm2=node->umap.find(itm->first);
			if(itm2==node->umap.end())
				node->umap.insert(pair<int, int>(itm->first, itm->second));
			else
				itm2->second+=itm->second;	
		}
	return node;
}
void traverse(seg *link){
	if(link){
		//cout<<"traversing"<<endl;
		map<int, int> :: iterator itm;
		for(itm=link->umap.begin();itm!=link->umap.end();itm++){
			cout<<itm->first<<" "<<itm->second<<endl;
		}
		cout<<endl;
		traverse(link->left);
		traverse(link->right);
	}
	else if(link==NULL)
		cout<<"breaking because of no element"<<endl;
}

int query(int L, int R, int s, int e, seg *temp, int X){
	//cout<<"hello"<<endl;
	if(L>e || R<s){
		return 0;
	}
	else if(L<=s && R>=e){
		if(temp){
			//cout<<"in second else if stmt"<<endl;
			map<int, int> :: iterator itm;
			itm=temp->umap.find(X);
			if(itm!=temp->umap.end())
				return itm->second;	
			else return 0;
		}
		else
			return 0;
	}	
	else 
	{
		//cout<<"in last else stmt"<<endl;
		int m=(s+e)/2;
		//if(temp){
			//cout<<"hey there is some temp"<<endl;
			return query(L, R, s, m, temp->left, X)+ query(L, R, m+1, e, temp->right, X);
			//}
		//else
			//return 0;
			
	}
}


int main(){
	int N, Q, L, R, X, Y, lar=2, A[100001], sp[1000001]={0};
	bool prime[1000001];
	seg *root=NULL;
	memset(prime, true, sizeof(prime));
	while(sqrt(1000000)>=lar){
		if(prime[lar]){
			//cout<<lar<<" is prime"<<endl;
			sp[lar]=lar;
			//cout<<"sp[lar]="<<lar<<endl;
			for(int i=lar*2;i<=1000000;i+=lar)
			{
				prime[i]=false;	
				if(sp[i]==0)
				{
							//cout<<"sp["<<i<<"]"<<lar<<endl;
					sp[i]=lar;
				}
			}
		}
		lar++;
	}
	cin>>N;
	for(int k=1;k<=N;k++){
		scanf("%d", &A[k]);	
	}
	root=build(1, N, sp, A);
	//traverse(root);
	// next phase
	cin>>Q;
	while(Q--){
		int sum=0;
		scanf("%d", &L);
		scanf("%d", &R);
		scanf("%d", &X);
		scanf("%d", &Y);
		while(X<=Y){
			if(prime[X]){
				sum+=query(L, R, 1, N, root, X);
			}
			X++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
