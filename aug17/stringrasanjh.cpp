#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int test;
    cin>>test;
 
    while(test--){
 
        int n,m;
        cin>>n>>m;
 
        //final array
        int* arr=new int[n+1];
        memset(arr,0,(n+1)*sizeof(arr[0]));
 
        int* lookup=new int[n+1];
        memset(lookup,0,(n+1)*sizeof(lookup[0]));
 
        vector<int> v[100005];
 
        int x,y;
 
        for(int i=0;i<m;i++){
 
            cin>>x>>y;
            v[x].push_back(y);
        }
 
        int temp=1;
 
        for(unsigned int i=0;i<v[0].size();i++){
 
            arr[v[0][i]]=temp;
            lookup[v[0][i]]=1;
            temp++;
        }
 
        int prev_size=v[0].size(),current_size=0,flag=0;
 
        for(int i=1;i<n;i++){
 
            current_size=v[i].size();
 
            if(prev_size-current_size>1||prev_size-current_size<0){
 
                cout<<"-1"<<endl;
                flag=1;
				//remove this cout
          //      cout<<"breaked at last"<<endl;
                break;
            }
            else if(prev_size==current_size){
 
                for(unsigned int j=0;j<v[i].size();j++){
 
                    if(lookup[v[i][j]]==0){
                    	
 
                        arr[v[i][j]]=arr[i];
                        lookup[v[i][j]]=1;
                        break;
                    }
                }
            }
 
            prev_size=current_size;
		//	cout<<"for "<<i<<" current_size "<<current_size<<endl;
        }
		//I added this
        /*for(int i=1; i<=n; i++)
        {
        	cout<<arr[i]<<" ";
        }
		cout<<endl;*/
        /*if(flag==1)
            continue;
        else{
 
            set<int> s;
 
            for(int i=n;i>0;i--){
 
                s.insert(arr[i]);
 
                if(s.size()!=v[i-1].size()){
 
                    cout<<"-1"<<endl;
                    flag=1;
                    break;
                }
            }
        }
		*/
 
        if(flag==0){
 
            for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
 
            cout<<endl;
        }
 
    }
 
    return 0;
}
