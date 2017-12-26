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
    lli T;
    cin >> T;
    while(T--){
        string N, R;
        cin >> N >> R;
        if(N.length()>R.length()){
            swap(N, R);
        }
        reverse(N.begin(), N.end());
        reverse(R.begin(), R.end());
        dout << "N:" << N << "R:" << R << endl;
        string ans; 
        ans.resize(R.length());
        for(lli i = 0; i < R.length(); i++){
            if( i >= N.length()){
                ans[i] = R[i];
                dout << " in i>=N.length()" << endl;
            }
            else{
                ans[i] = (((N[i]-'0') + (R[i] - '0'))%10)+'0'; 
            }
                dout << "ans for:" << i << ans[i] << endl;
        }
        dout << "Printing ans" << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
	return 0;
}
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
	return 0;
}
