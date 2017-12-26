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

    while(T--){
        int a[1001] = {0};
        int marr[100];
        int N;
        cin >> N;
        int max = 0;
        int secMax = 0;
        for(int i = 0; i < N; i++){
            cin >> marr[i];
            if(marr[i] > max){
                secMax = max;
                max = marr[i];
            }
            a[marr[i]]++;
        }

        dout << "max:" << max << endl;
        dout << "secMax:" << secMax << endl;
        dout << "a[max]:" << a[max] << endl;
        dout << "a[secMax]:" << a[secMax] << endl;

        double ans;

        if(a[max] > 1){
            ans = (double(a[max]) *double(a[max]-1))/2;
            dout << "ans:" << ans << endl;
            double total = (N*(N-1))/2;
            dout << "total:" << total << endl;
            double tAns = ans/total;
            cout << tAns << endl;
        }

        else{
            ans = double(a[secMax]);
            double total = (N*(N-1))/2;
            double tAns = ans/total;
            cout << tAns << endl;
        }
    }
	return 0;
}
