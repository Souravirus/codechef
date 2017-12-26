#include <bits/stdc++.h>
using namespace std;
 
int main(){
		int t;
		cin>>t;
		while(t--){
			long int n,q,a,x;
			cin>>n>>q;
			vector< vector <long int> > nodes(n);
			vector< vector <long int> > cycle(n);
			vector< vector <long int> > sumnodes(n);
			long int sumcycle[n+1];
			for(long int i=0;i<n;i++){
				cin>>a;
				sumnodes[i].push_back(0);
				for(long int j=0;j<a;j++){
					cin>>x;
					nodes[i].push_back(x);
					if(j==0){
						sumnodes[i].push_back(nodes[i][0]);
					}
					else{
						sumnodes[i].push_back(nodes[i][j]+sumnodes[i][j]);
					}
				}
			}
			for(long int i=0;i<n;i++){
				a=3;
				while(a--){
					cin>>x;
					cycle[i].push_back(x);
				}
			}
			sumcycle[0]=0;
			long int nodemin1=0,nodemin2=0;
			for(long int i=1;i<=n;i++){
				if(i==1){
					sumcycle[i]=cycle[i-1][2];
				}
				else{
					nodemin1=abs(sumnodes[i-1][cycle[i-2][1]-1]-sumnodes[i-1][cycle[i-1][0]-1]);
                    cout << "for " << i << " nodemin1: " << nodemin1 << endl;
					nodemin2=abs(sumnodes[i-1][nodes[i-1].size()]-nodemin1);
                    cout << "hello" << endl;
                    cout << "for " << i << " nodemin2: " << nodemin2 << endl;
					if(nodemin2<nodemin1) { sumcycle[i]=sumcycle[i-1]+nodemin2+cycle[i-1][2]; }
					else {
						sumcycle[i]=sumcycle[i-1]+nodemin1+cycle[i-1][2];
					}
				}
			}
			while(q--){
				long int v1,c1,v2,c2,ans1=0,ans2=0;
				cin>>v1>>c1>>v2>>c2;	
				
				if(c1>c2){
					long int temp=c1;
					c1=c2;
					c2=temp;
					temp=v1;
					v1=v2;
					v2=temp;
				}
				
				ans1=sumcycle[c2-1]-sumcycle[c1-1];
				ans2=sumcycle[n]-sumcycle[c2-1];
				
				if(v1!=cycle[c1-1][0]){
					nodemin1=abs(sumnodes[c1-1][v1-1]-sumnodes[c1-1][cycle[c1-1][0]-1]);
					nodemin2=abs(sumnodes[c1-1][nodes[c1-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans1+=nodemin2; }
					else {
						ans1+=nodemin1;
					}
				}
				else{
					if(c1!=1){
					nodemin1=abs(sumnodes[c1-1][nodes[c1-1].size()-(v1-1)%nodes[c1-1].size()]-sumnodes[c1-1][cycle[c1-2][1]-1]);
					nodemin2=abs(sumnodes[c1-1][nodes[c1-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans1-=nodemin2; }
					else {
						ans1-=nodemin1;
					}
					}
				}
				if(v2!=cycle[c2-2][1]){
					nodemin1=abs(sumnodes[c2-1][v2-1]-sumnodes[c2-1][cycle[c2-2][1]-1]);
					nodemin2=abs(sumnodes[c2-1][nodes[c2-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans1+=nodemin2; }
					else {
						ans1+=nodemin1;
					}
				}
 
				if(v1!=cycle[n-1][1]){ //modify later
					nodemin1=abs(sumnodes[c1-1][v1-1]-sumnodes[c1-1][cycle[n-1][1]-1]);
					nodemin2=abs(sumnodes[c1-1][nodes[c1-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans2+=nodemin2; }
					else {
						ans2+=nodemin1;
					}
				}
				
				if(v2!=cycle[c2-2][1]){
					nodemin1=abs(sumnodes[c2-1][nodes[c2-1].size()-(v2-1)%nodes[c2-1].size()]-sumnodes[c2-1][cycle[c2-2][1]-1]);
					nodemin2=abs(sumnodes[c2-1][nodes[c2-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans2-=nodemin2; }
					else {
						ans2-=nodemin1;
					}
					nodemin1=abs(sumnodes[c2-1][nodes[c2-1].size()-1]-sumnodes[c2-1][v2-1]);	
					nodemin2=abs(sumnodes[c2-1][nodes[c2-1].size()]-nodemin1);
					if(nodemin2<nodemin1) { ans2+=nodemin2; }
					else {
						ans2+=nodemin1;
					}			
				}
 
				if(ans1<=ans2) { cout<<ans1<<endl;}
				else { cout<<ans2<<endl; } 
				
			}		
			}
		return 0;
	}
