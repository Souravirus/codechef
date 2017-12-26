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

unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%llu %llu", &s[0], &s[1]);
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}
        
        ulli maini[n][n];
        
        ulli Harr[n];
        for(ulli i = 0; i < n; i++){
            ulli min = 0 ;
            for(ulli j = 0; j < n; j++){
                if(H[i][j] < H[i][min]){
                    Harr[i] = j;
                    min = j;
                }
                maini [i][j] = 0;
            }
        }

        ulli Ccount[n];
        for(ulli i = 0; i < n; i++)
            Ccount[i] = 0;

        for(ulli i = 0; i < n; i++){
            ulli min = Harr[i];
            dout << "min" << min << endl;
            vector<pair<ulli, ulli> >A;
            A.resize(n);
            ulli count = 0;

            for(ulli j = 0; j < n; j++){
                A[j].first = C[i][j];
                A[j].second = j;
            }

            sort(A.begin(), A.end()); 

            if(Ccount[i] < min){
                ulli count = 0, size = min - Ccount[i], j = 0, sum = 0, sum1 = 0;
                if(i == 0){
                    for(int j = 0; j < n; j++)
                        sum1+=C[i][j] ;
                    sum1+=H[0][n-1];
                }

                else{
                    sum1 = C[0][i];
                    sum1 += H[i][1];
                }

                while(count < size && j < n){

                    if(maini[i][A[j].second] == 0 && i != A[j].second){
                        sum += C[i][A[j].second];
                        count ++;
                    }
                    
                    j++;
                }
                if(sum + min < sum1){
                    count = 0;
                    j = 0;
                    while(count < size && j < n){

                        if(maini[i][A[j].second] == 0 && i != A[j].second){
                            maini[i][A[j].second] =1;
                            maini[A[j].second][i] = 1;
                            Ccount[i]++;
                            Ccount[A[j].second]++;
                            count ++;
                        }
                        
                        j++;
                    }
                }

                else{

                    if(i == 0){

                        for(ulli j = 0; j < n; j++){

                            if(i != j && maini[i][j] == 0){
                                maini[i][j] = 1;
                                maini[j][i] = 1;
                                Ccount[i]++;
                                Ccount[j]++;
                            }
                        }
                    }

                    else{
                        if(maini[i][0] == 0){
                            maini[i][0] = 1;
                            maini[0][i] = 1;
                            Ccount[i]++;
                            Ccount[0]++;
                        }

                    }
                }
            }

            ulli j = 0;

            while(Ccount[i] == 0 && j < n){
                if(i!= A[j].second){
                    maini[i][A[j].second] = 1;
                    maini[i][A[j].second] = 1;
                    Ccount[i]++;
                    Ccount[A[j].second]++;
                }
                j++;
            }
 
        }
        for(ulli i = 0; i < n; i++){
            for(ulli j = 0; j < n; j++){
                cout << maini[i][j];
            }
            cout << endl;
        }
	}

	
	return 0;
}

