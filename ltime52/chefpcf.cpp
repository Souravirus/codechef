#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
int debug = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    while ( T--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i< n; i++)
            arr[i]=0;
        int num, pos;
        for(int i = 0; i < k; i++)
        {
            cin>>pos;
            cin>> num;
            arr[pos-1]=num;
        }
        int count =0;
        for(int i=0; i < n; i++){
            int j=0;
            while(1){
                if(i-j >=0 && i+j <n)
                {
                    dout << "for i"<<i<<endl;
                    dout<<"printing a i +j and a i-j"<<endl;
                    dout << arr[i+j]<<endl;
                    dout << arr[i-j]<<endl;
                    if(arr[i-j]!=arr[i+j])
                        break;
                    else
                    {
                        dout<<"count added"<<endl;
                        count ++;
                    }
                }
                else
                    break;
                j+=1;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}
