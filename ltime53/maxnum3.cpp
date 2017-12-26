#include<bits/stdc++.h>
#include<string>
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
        lli num;
        string s;
        cin >> s; 
        dout << "s:" << s << endl;
        lli flag = 0;
        lli sum = 0;
        for (int i = 0; i < s.length(); i++){
            sum+=s[i]-'0'; 
        }
        int pos;
        string max ="";
        
        for(int i = 0; i < s.length(); i++){
            int int_sum = sum - (s[i] -'0');
            if(int_sum%3 != 0)
                continue;

            dout << "Here i is:"<< i << " and I have passed 3 test" << endl;
            if(i != s.length() - 1){

                if(s[s.length()-1] %2 ==0){
                    flag = 1;
                    if(s[i+1] > s[i]){
                        pos = i;
                        break;
                    }
                    pos = i;
                }
            }

            else{
                if(s[s.length()-2] %2 == 0){
                    flag = 1;
                    pos = i;
                }
            }
        }

        string last="";
        if(flag == 1){
            for(int i = 0; i < s.length(); i++){
                if(i!=pos){
                    cout << s[i];
                }
            }
            cout << endl;
        }

        if(flag == 0)
            cout << "-1" << endl;

    }
	return 0;
}
