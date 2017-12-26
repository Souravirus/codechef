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
        lli root, num;
        cin >> num; 
        lli count = 0;
        root = sqrt(num);
        dout << "root:" << root << endl;
        lli sqr = root*root;
        while(num - sqr <= 700 && root != 0){
            dout << "sqr now:" << sqr << endl;  
            if(num-sqr <= 700){
                count += (num - sqr);
            }
            root--;
            dout << "root now:" << root << endl;
            sqr = root * root;
        }

        count+= root * 700;
        cout << count << endl;
    }
	return 0;
}
