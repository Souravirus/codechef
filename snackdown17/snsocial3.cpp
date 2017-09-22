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
		int inv=0;
		while(flag==1){
			flag=0;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(inv==0){
						int max=A[i][j];
						if(i!=0 && j!=0){
								if(A[i-1][j-1]>max){
									max=A[i-1][j-1];
								}		
						}
						if(i!=0){
								if(A[i-1][j]>max){
									max=A[i-1][j];
								}
						}
						if( j!=0){
								if(A[i][j-1]>max){
									max=A[i][j-1];
								}
						}
						if(i!=m-1 && j!=0){
								if(A[i+1][j-1]>max){
									max=A[i+1][j-1];
								}
						
						}
					
						if(i!=m-1){
						
								if(A[i+1][j]>max){
									max=A[i+1][j];
								}
						
						}
						if(i!=m-1 && j!=n-1){
								if(A[i+1][j+1]>max){
									max=A[i+1][j+1];
								}
						}

						if( j!=n-1){
								if(A[i][j+1]>max){
									max=A[i][j+1];
								}
						
						}
						if(i!=0 && j!=n-1){
								if(A[i-1][j+1]>max){
									max=A[i-1][j+1];
								}
						}
						if(A[i][j]<max){
							B[i][j]=max;
							flag=1;
							//cout<<"hello";
						}
						else{
							B[i][j]=A[i][j];
						}
					}
					else if(inv==1){
						int max=B[i][j];
						if(i!=0 && j!=0){
								if(B[i-1][j-1]>max){
									max=B[i-1][j-1];
								}		
						}
						if(i!=0){
								if(B[i-1][j]>max){
									max=B[i-1][j];
								}
						}
						if( j!=0){
								if(B[i][j-1]>max){
									max=B[i][j-1];
								}
						}
						if(i!=m-1 && j!=0){
								if(B[i+1][j-1]>max){
									max=B[i+1][j-1];
								}
						
						}
					
						if(i!=m-1){
						
								if(B[i+1][j]>max){
									max=B[i+1][j];
								}
						
						}
						if(i!=m-1 && j!=n-1){
								if(B[i+1][j+1]>max){
									max=B[i+1][j+1];
								}
						}

						if( j!=n-1){
								if(B[i][j+1]>max){
									max=B[i][j+1];
								}
						
						}
						if(i!=0 && j!=n-1){
								if(B[i-1][j+1]>max){
									max=B[i-1][j+1];
								}
						}
						if(B[i][j]<max){
							A[i][j]=max;
							flag=1;
							//cout<<"hello";
						}
						else{
							A[i][j]=B[i][j];
						}
					}
				}
			}
			if(flag==1){
				count++;
				if(inv==1)
				 inv=0;
				else
				 inv=1;
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
