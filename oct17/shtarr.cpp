#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
int debug = 1;

vector<lli> great;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli T;
    cin >> T;
    lli N, Q;

    while(T--){
        cin >> N >> Q;
        lli arr[N+1];
        great.clear();
        great.resize(N+1);
        
        for(lli i = 1; i <= N; i++){
            cin >> arr[i];  
        }
         
        lli max = -1;
        for(lli i = N; i > 0; i--){
           if(arr[i] > max) {
               max = arr[i];
               great[i] = -1;
           }
           else
               great[i] = max;
        }
    
        char type;
        lli x, L, R; 

        dout << "printing greats" << endl;
        for(int i = 1; i <= N; i++){
            dout << great[i] << endl;
        }

        for(int i = 1; i <= Q; i++){
            cin >> type;

            if(type == '?'){
                cin >> x >> L >> R;
                x = floor(x-0.5);
                dout << "x:" << x << endl; 
                lli rays = R-L+1;
                dout << "rays:" << rays << endl;
                lli comp = great[x];
                lli diff = comp - L;

                if(diff > 0){
                    if(rays - diff > 0)
                        cout << rays - diff << endl;
                    else
                        cout << "0" << endl;
                }
                else
                    cout << "0" << endl;
            }
        }
    }

	return 0;
}
