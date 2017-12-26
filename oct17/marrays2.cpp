#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define ulli long long int
#define dout if(debug)cout<<" "
typedef long long int lli;
using namespace std;

int debug = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    
    while (T--){
        lli N,M;
        cin >> N;

        int temp;
        if(N==1){
            cin >> M;
            while(M --)
                cin >> temp;
            cout << 0 <<endl;
            continue;
        }

        vector<vector <lli> > myvect(N);
        vector<vector<lli> >prev(N);
        for(lli i = 0; i < N; i++){
            cin >> M;
            myvect[i].resize(M);
            prev[i].resize(M);
            for(lli j = 0; j < M; j++)
                cin>>myvect[i][j];
        }

        

        lli min=99999999;
        lli max=0;
        for(lli i = 0; i < myvect[0].size(); i++){//On
            if(myvect[0][i]  < min)
                min = myvect[0][i];
            if(myvect[0][i] > max)
                max = myvect[0][i];
        }
        

        lli lmax = 0;
        for(lli i = 0; i < myvect[1].size(); i++){//O n
            lmax = 0;
            lmax = abs(myvect[1][i] - min); 

            if(abs(myvect[1][i] - max) > lmax)
                lmax = abs(myvect[1][i] - max);

            prev[1][i]=(lmax);
        } 
            


        for(lli i = 2; i < N; i++){
            for(lli j = 0; j < myvect[i].size(); j++){
                max = 0;
                int size = myvect[i-1].size()-1;
                lli next;
                for(lli k = 0; k < myvect[i-1].size(); k++){
                    if(k == size)
                       next = 0;
                    else
                       next = k+1;
                    lli prod = abs(myvect[i][j] - myvect[i-1][k])*i + (prev[i-1][next]);
                    if(prod > max)
                        max = prod;
                }//end k
                prev[i][j]=max;
            }
        }
        
        max = 0;
        for(lli i = 0; i < prev[N-1].size(); i++){// O n
            if(prev[N-1][i] > max)
                max = prev[N-1][i];
        }
        cout << max << endl;
    }

	return 0;
}
