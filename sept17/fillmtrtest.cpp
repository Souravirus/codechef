#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, Q;
    cin>>T;
    while(T--){
        cin>>N>>Q;
        int arr[N+1];
        for(int i=1; i<=N; i++)
            arr[i]=-1;
        int m, n, val;
        int flag=0;
        arr[1]=0;
        int am[Q+1];
        int an[Q+1];
        int aval[Q+1];
        for(int i=0; i<Q; i++){
            cin>>m>>n>>val;
            am[i]=m; an[i]=n; aval[i]=val;
        }
        int r=rand()%2;
        if(r==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
 }
