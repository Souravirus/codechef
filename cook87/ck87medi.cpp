#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K; 
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr+N);
        int sum = N+K;
        int mid = (sum/2);
        cout << arr[mid] << endl;
    }
	return 0;
}
