#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;
int debugg = 0;
bool getans(matrix& mat,vector<int>& ans,int n){
//    cout<<"iteration "<<n<<endl;
    if(n==7) return true;

    int flag=0;
    int i = 1;
    while(i<=6){
        if(ans[i]==-1)
            flag=1;
        i++;
    }
    if(flag==0) return true;
    
    if(ans[n]!=-1){
        if(getans(mat,ans,n+1))
            return true;
        else return false;
    }
     i = 1;
    while(i<=6){
        if(mat[n][i] && mat[i][n] && ans[i]==-1 && ans[n]==-1){
            ans[n]=i;
            ans[i]=n;

            if ( getans(mat,ans,n+1) )
                return true;

            ans[n]=-1;
            ans[i]=-1;
        }
        i++;
    } 

    return false;
}
int main(){
	int t=1;
	cin>>t;
	for(int y = 0; y < t; y++){
        int n,temp=0,a,pflag=0;
        cin>>n;
        matrix mat(7,vector<int>(7,1));
        for(int z = 0; z< n ; z++){
            cin>>a;
            if(temp==a) pflag=1;

            mat[temp][a]=0;
            mat[a][temp]=0;

            temp = a;
        }
        for(int i=1;i<=6;i++){
            mat[i][i]=0; 
        }

        vector<int> ans(7,-1);
        if(pflag!=1){
            if(getans(mat,ans,1)){
                for(int i=1;i<=6;i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
	}
}
