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
    int M, N;
    cin >> N >> M;

    for(int k = 0; k < M; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int num;
                cin >> num;
            }
        }
    }
    
    int count = 1;
    for(int i = 0; i < M; i++){

        if(i%N != 0 || i == 0){
            cout << (i%N)+1 << " " << count << endl;
        }
        
        else{
            //cout << "hello" << endl;
            count++;
            cout << (i%N)+1 << " " << count << endl; 
        }
        
    }

	return 0;
}
