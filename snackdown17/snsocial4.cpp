#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
	int t,n,m,max,et,count=0;
 
	cin >> t;
 
	while(t--){
 
		cin >> n >> m;
 
		int a[n+2][m+2][2];
		memset(a,-1,sizeof(a));
 
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				cin >> a[i][j][1];
			}
		}
 
 
		max=0;
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				if(a[i][j][1]>max){
					max=a[i][j][1];
				}
			}
		}
 
		et=0;
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				if(a[i][j][1]==max){
					a[i][j][2]=1;
					et++;
				}
				else{
					a[i][j][2]=0;
				}
			}
		}		
 
		count = 0;
 
		while(et!=(n*m)){
			for(int i=1;i<n+1;i++){
				for(int j=1;j<m+1;j++){
					if(a[i][j][1]==max){
						if(a[i+1][j+1][2]==0){
							a[i+1][j+1][2]=1;
						}
						if(a[i+1][j][2]==0){
							a[i+1][j][2]=1;
						}
						if(a[i+1][j-1][2]==0){
							a[i+1][j-1][2]=1;
						}
						if(a[i][j+1][2]==0){
							a[i][j+1][2]=1;
						}
						if(a[i][j-1][2]==0){
							a[i][j-1][2]=1;
						}
						if(a[i-1][j+1][2]==0){
							a[i-1][j+1][2]=1;
						}
						if(a[i-1][j][2]==0){
							a[i-1][j][2]=1;
						}
						if(a[i-1][j-1][2]==0){
							a[i-1][j-1][2]=1;
						}
					}
				}
			}
 
 
			for(int i=1;i<n+1;i++){
				for(int j=1;j<m+1;j++){
					if(a[i][j][2]==1 && a[i][j][1]!=max){
						a[i][j][1]=max;
						et++;
					}
				}
			}
 
			count++;
		}
 
		cout << count << endl;
 
	}
 
	return 0;
 
}
