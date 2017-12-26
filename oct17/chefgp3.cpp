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
    //cout << T << endl;    
    while (T--){
        string str;
        cin >> str;
        int counta = 0, countb = 0;
        //cin >> counta >> countb;
        int x, y;
        cin >> x >> y;
        //scanf("%d%d", &x, &y);
        for (int i = 0; i < str.length(); i++){

            if (str[i] == 'a')
                counta++;
            else if(str[i] == 'b')
                countb++;
        }
        int curra = 0, currb = 0;
        vector<char> finalstring;

        while(counta != 0 || countb != 0){

            if(counta >= countb){

                if(curra < x){
                    finalstring.push_back('a');
                    counta--;
                    curra++;
                    currb = 0;
                }

                else if (countb != 0){
                    finalstring.push_back('b');
                    countb--;
                    curra = 0;
                    currb++;
                }

                else{
                    finalstring.push_back('*');
                    finalstring.push_back('a');
                    counta--;
                    curra = 1;
                    currb = 0;
                }

            }
            else{

                if(currb < y){
                    finalstring.push_back('b');
                    countb--;
                    currb++;
                    curra = 0;
                }

                else if (counta != 0){
                    finalstring.push_back('a');
                    counta--;
                    currb = 0;
                    curra++;
                }

                else{
                    finalstring.push_back('*');
                    finalstring.push_back('b');
                    countb--;
                    currb = 1;
                    curra = 0;
                }

            }

        }

        for(int i =0; i < finalstring.size(); i++)
            cout << finalstring[i];
        cout << endl;
    }

	return 0;
}
