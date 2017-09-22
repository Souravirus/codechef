#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, N, K, len,num, count, total;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int v[N][K+1];
		int arr[K+1];
		for(int i=0;i<N;i++){
			scanf("%d", &len);
			for(int j=0;j<=K;j++){
				arr[j]=0;
			}
			int count=1;
			for(int j=0;j<len;j++){	
				scanf("%d", &num);
				if(arr[num]==0){
					arr[num]=1;
					v[i][count]=num;
					count++;
				}
			}
			sort(&v[i][1], &v[i][1]+count-1);
			v[i][0]=count;
		}
		/*cout<<"sorted array:"<<endl;
		for(int i=0;i<N;i++){
			for(int j=1;j<v[i][0];j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}*/ 

		//next phase	
		int total=0;
		for(int i=0;i<N;i++){
			if(v[i][0]==K+1)
			{
				total+=N-i-1;
				//cout<<"in continue 1st"<< total <<endl;
				continue;
			}
			for(int j=i+1;j<N;j++){
				if(v[j][0]==K+1)
				{
					total++;
				//	cout<<"in continue 2nd "<<total<<endl;
					continue;
				}
				count=1;
				int counti=1;
				int countj=1;
				int flag=1;
				while(flag==1){
					flag=0;
					if(counti<v[i][0]){
						if(v[i][counti]==count){
							flag=1;
							counti++;
						}
					}
					if(countj<v[j][0]){
						if(v[j][countj]==count){
							flag=1;
							countj++;
						}
					}
					if(flag==1)
						count++;
				}
				if(count==K+1){
					total++;
				//	cout<<"increasing total due to count=K+1 "<<total<<endl;
				}
			}
		}
		cout<<total<<endl;
	}
	return 0;
	
}
