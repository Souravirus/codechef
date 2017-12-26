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
    int T;
    cin >> T;

    while (T--){
        int N, P;
        cin >> N >> P;
        int min = P/10;
        int max = P/2;
        int flagmin = 0;
        int flagmax = 0;
        int num;

        for(int i = 0; i < N; i++){
           cin >> num;

           if (num  <= min)
               flagmin++;

           if (num >= max)
               flagmax++;
        }

        if (flagmax == 1 && flagmin == 2)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

	return 0;
}
