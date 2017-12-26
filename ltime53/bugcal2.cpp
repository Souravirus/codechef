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
    int t;
    cin >> t;
    while(t--){
        lli a, b;
        cin >> a >> b;
        lli i = 10, temp = 0;
        lli total = a + b;
        while( a || b){
            if(((a%10) + (b%10)) > 9){
                temp += i;
            }
            
            a = a/10;
            b= b/10;
            i = i*10;
        }
        cout << total-temp<<endl;
    }
	return 0;
}
