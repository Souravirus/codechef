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

lli retSum(lli num){
    string s = to_string(num);
    lli sum = num;
    while(s.length() >= 2){
        sum = 0;
        for(lli i = 0; i < s.length(); i++){
            sum += s[i] - 48;
        }
        s= to_string(sum);
    }

    return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        lli num, power;
        cin >> num;
        cin >> power;
        lli dsum = retSum(num);
        dout << dsum << endl;
        if(power == 1)
            cout << dsum << endl;
        else{
            if(dsum == 1){
                cout << "1" << endl;
            }

            if(dsum == 2){
                power = power %6;
                lli num = pow(2, power);
                cout << retSum(num) << endl;
            }

            if(dsum == 3 || dsum == 6 || dsum== 9){
                if(power == 1){
                    cout << "1" << endl;
                }

                else{
                    cout << "9" << endl; 
                }
            }

            if(dsum == 4){
                power = power%3;
                lli num = pow(4, power);
                cout << retSum(num) << endl;
            }

            if(dsum == 8){
                power = power %2;
                lli num = pow(8, power);
                cout << retSum(num) << endl;
            }

            if(dsum == 5){
                power = power %6;
                lli num = pow(5, power);
                cout << retSum(num) << endl;

            }

            if(dsum == 7){
                power = power %3;
                lli num = pow(7, power);
                cout << retSum(num) << endl;
            }
        }

    }
	return 0;
}
