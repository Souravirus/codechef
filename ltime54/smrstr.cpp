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
    ulli T;
    cin >> T;

    while(T--){
        ulli N;
        ulli Q;
        cin >> N >> Q;
        double pro = 1;
        for(int i = 0; i < N; i++){
            double num;
            cin >> num;
            pro = pro * num;
        }

        for(int i = 0; i < Q; i++){
            double num;
            cin >> num;
            ulli ans = num/pro;
            cout << ans << " ";
        }
        cout << endl;
    }

	return 0;
}
