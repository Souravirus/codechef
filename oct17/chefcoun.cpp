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
    lli mod = pow(2, 32);
    while (T--){
        lli n;
        cin >> n;
        lli div = mod / (n+1);
        lli arr[n];
        lli rem = mod % (n+1);  
        if(rem == 0)
        {
            div--;
            rem = n-2;
            arr[0]=div + 2;
            for(lli i = 1; i < rem; i++ ){
                arr[i] = div + 1;
                cout << arr[i] << " ";
            }
            for(lli i = rem; i < n; i++){
                arr[i] = div;
                cout << arr[i] << " ";
            }
        }
        else if(rem == n-1)
        {
            rem = n-2;
            for(lli i = 0; i < rem; i++ ){
                arr[i] = div + 1;
                cout << arr[i] << " ";
            }
            for(lli i = rem; i < n; i++){
                arr[i] = div;
                cout << arr[i] << " ";
            }
        }
        else
        {
            for(lli i = 0; i < rem-1; i++ ){
                arr[i] = div + 1;
                cout << arr[i] << " ";
            }
            for(lli i = rem-1; i < n; i++){
                arr[i] = div;
                cout << arr[i] << " ";
            }

        }
        cout << endl;
    }

	return 0;
}
