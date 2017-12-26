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
        string str;
        cin >> str;
        int tol1, tol2;
        cin >> tol1 >> tol2;
        int numa = 0, numb = 0;
        vector<char> finalstring;

        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'a'){
                numa++;
            }
            else
                numb++;
        }

        if(numa < numb){
            for(int i = 0; i < numa; i++){
                finalstring.push_back('b');
                finalstring.push_back('a');
            }
            finalstring.push_back('b');

            for(int i = numa+1; i < numb; i++){
                finalstring.push_back('*');
                finalstring.push_back('b');
            }
        }
        else{
            for(int i = 0; i < numb; i++){
                finalstring.push_back('a');
                finalstring.push_back('b');
            }
            finalstring.push_back('a');

            for(int i = numb+1; i < numa; i++){
                finalstring.push_back('*');
                finalstring.push_back('a');
            }
        }
        for(int i = 0; i < finalstring.size(); i++)
            cout << finalstring[i];
        cout << endl;
    }
            
	return 0;
}
