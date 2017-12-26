//This time I am just doing the minimum sum with c[i] & H[i].
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
        vector<pair<ulli, ulli> > Harr;
        vector<pair<ulli, ulli> > ::iterator itv;
        Harr.resize(n);
        
        for(ulli i = 0; i < n; i++){
            ulli min = 0;
            Harr[i].second = i;
            for(ulli j = 0; j < n; j++){
                if(H[i][j] < H[i][min]){
                    Harr[i].first = H[i][j];
                    min = j;
                }
                maini [i][j] = 0;
            }
        }
        
        sort(Harr.begin(), Harr.end());

        ulli Ccount[n];
        ulli traversed[n];

        for(ulli i = 0; i < n; i++){
            traversed[i] = 0;
            Ccount[i] = 0;
        }

        for(ulli ind = 0; ind < n; ind++){
            ulli i = Harr[ind].second;
            vector<pair<ulli, ulli> >A;
            A.resize(n);

            for(ulli j = 0; j < n; j++){
                A[j].first = C[i][j];
                A[j].second = j;
            }

            sort(A.begin(), A.end()); 

            ulli currsum = 0; 
            //First I am finding the sum of cables in current situation
            for(ulli j = 0; j < n; j++){
                if(maini[i][j] == 1)
                    currsum += C[i][j];
            }

            //Now I am finding the improvised minimum sum for i
            int flag =  0;
            ulli min = currsum + H[i][Ccount[i]];
            ulli travFlag = 0;
            ulli sum = currsum, count = 0, minCount = -1;

            for(ulli j = 0; j < n; j++){

                if((maini[i][A[j].second] == 0 && i != A[j].second)){
                    sum += A[j].first;
                    count++;

                    if(sum + H[i][Ccount[i]+count] < min){ 
                        min = sum  + H[i][Ccount[i]+count];
                        minCount = count;
                        flag = 1;
                    }

                    if(traversed[A[j].second] == 1){
                        travFlag = 1;
                        traversed[A[j].second] = 0;
                    }
                }
            }

            if(travFlag == 0 && ind!=0){
                minCount -=2;
            }
            
            else if(ind != 0)
                minCount--;
            //If a minimum combination exists then I will commit the changes
            if(flag == 1){
                ulli tcount = 0;
                ulli j = 0;

                while(tcount < minCount && j < n){

                    if((maini[i][A[j].second] == 0 && i != A[j].second)){
                        maini[i][A[j].second] = 1;
                        maini[A[j].second][i] = 1;
                        Ccount[i] ++;
                        Ccount[A[j].second]++;
                        tcount++;
                    }

                    j++;
                }
            }

             ulli j = 0;

             while(travFlag == 0 && ind!=0){

                if(i != A[j].second && traversed[A[j].second] == 1){
                    maini[i][A[j].second] = 1;
                    maini[A[j].second][i] = 1;
                    Ccount[i]++;
                    Ccount[A[j].second]++;
                    travFlag = 1;
                    traversed[A[j].second] = 0;
                }
                j++;
             }

            //If  by chance the office is not connected to any node then 
            //just connect it to at least one office 
             j = 0;
             while(Ccount[i] == 0 && j < n){

                if(i != A[j].second){
                    maini[i][A[j].second] = 1;
                    maini[A[j].second][i] = 1;
                    Ccount[i]++;
                    Ccount[A[j].second]++;
                }
                j++;
            }
            traversed[i] = 1;
        }

        //Printing the main double array
        for(ulli i = 0; i < n; i++){
            for(ulli j = 0; j < n; j++){
                cout << maini[i][j];
            }
            cout << endl;
        }
	}

	
	return 0;
}

