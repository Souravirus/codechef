#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,m, n,  A[500][500], B[500][500];
	cin>>T;
	while(T--){
		cin>>m>>n;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++){
				cin>>A[i][j];
				B[i][j]=0;
			}
		}
		int flag=1;
		int count=0;
		while(flag==1){
			flag=0;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					int time=B[i][j];
					int max=A[i][j];
					if(i!=0 && j!=0){
						if(A[i-1][j-1]==max){
								max=A[i-1][j-1];
								if(B[i-1][j]<time)
								time=B[i-1][j-1];
						}
							if(A[i-1][j-1]>max){
								max=A[i-1][j-1];
								time=B[i-1][j-1];
							}		
					}
					if(i!=0){
							if(A[i-1][j]==max){
								max=A[i-1][j];
								if(B[i-1][j]<time)
									time=B[i-1][j];
							}
							if(A[i-1][j]>max){
								max=A[i-1][j];
								time=B[i-1][j];
								//flagc=1;
							}
					}
					if( j!=0){
							if(A[i][j-1]==max){
								max=A[i][j-1];
								if(B[i][j-1]<time)
									time=B[i][j-1];
							}
							if(A[i][j-1]>max){
								max=A[i][j-1];
								time=B[i][j-1];
								//flagc=1;
							}
					}
					if(i!=m-1 && j!=0){
							if(A[i+1][j-1]==max){
								max=A[i+1][j-1];
								if(B[i+1][j-1]<time)
									time=B[i+1][j-1];
							}
							if(A[i+1][j-1]>max){
								max=A[i+1][j-1];
								time=B[i+1][j-1];
								//flagc=1;
							}
						
					}
					
					if(i!=m-1){
						
							if(A[i+1][j]==max){
								max=A[i+1][j];
								if(B[i+1][j]<time)
									time=B[i+1][j];
							}
							if(A[i+1][j]>max){
								max=A[i+1][j];
								time=B[i+1][j];
								//flagc=1;
							}
						
					}
					if(i!=m-1 && j!=n-1){
							if(A[i+1][j+1]==max){
								max=A[i+1][j+1];
								if(B[i+1][j+1]<time)
									time=B[i+1][j+1];
							}
							if(A[i+1][j+1]>max){
								max=A[i+1][j+1];
								time=B[i+1][j+1];
								//flagc=1;
							}
					}

					if( j!=n-1){
							if(A[i][j+1]==max){
								max=A[i][j+1];
								if(B[i][j+1]<time)
									time=B[i][j+1];
							}
							if(A[i][j+1]>max){
								max=A[i][j+1];
								time=B[i][j+1];
								//flagc=1;
							}
						
					}
					if(i!=0 && j!=n-1){
							if(A[i-1][j+1]==max){
								max=A[i-1][j+1];
								if(B[i-1][j+1]<time)
									time=B[i-1][j+1];
							}
							if(A[i-1][j+1]>max){
								max=A[i][j+1];
								time=B[i][j+1];
							}
					}
					if(A[i][j]<max){
						A[i][j]=max;
						B[i][j]=time+1;
						flag=1;
						if(B[i][j]>count)
						{
							count=B[i][j];
						}
					}
					if(A[i][j]==max){
						if(time<B[i][j]){
							B[i][j]=time+1;
						}
					}
				}
			}
		}
		/*cout<<"A"<<endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
			
		}
		cout<<"B"<<endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<B[i][j]<<" ";
			}
			cout<<endl;
			
		}*/
		cout<<count<<endl;
	}
	return 0;
}
