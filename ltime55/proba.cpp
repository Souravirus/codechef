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
        int days;
        cin >> days;
        string s;
        int first;
        int start;
        cin >> s;
        if(s == "mon"){
            start = 0;
        }

        else if(s== "tues")
            start = 1;
        else if(s== "wed")
            start = 2;
        else if(s== "thurs")
            start = 3;
        else if(s=="fri")
            start = 4;
        else if(s=="sat")
            start = 5;
        else if(s=="sun")
            start = 6;
        int add = days%7;
        int num= days/7;
        int count = 0;
        int ind = start;
        int arr[8];
        for(int i = 0; i < 8; i++){
            arr[i] = 0;
        }
        while(count < add){
            arr[ind] = num+1; 
            ind++;
            count++;
            ind = ind%7;
        }

        for(int i = 0; i < 7; i++){

            if(arr[i] == 0){
                arr[i] = num;
            }
        }

        for(int i = 0; i < 7; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
	return 0;
}
