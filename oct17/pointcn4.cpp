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
void optimise(vector<pair<ulli, ulli> >&Carr, ulli maxEdge, ulli currMaxEdge, ulli vectPos){
    Carr[vectPos].first -= maxEdge;
    Carr[vectPos].first += currMaxEdge;
}
 
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
        for(ulli i = 0; i < n; i++){
            for(ulli j = 0; j < n; j++)
                maini[i][j] = 0;
        }

        vector<pair<ulli, ulli> > Carr;
        Carr.resize(n);
        vector<ulli>maxEdge;
        maxEdge.resize(n);
        vector<ulli>vectPos;
        vectPos.resize(n);

        for(ulli i = 0; i < n; i++){
            vector<pair<ulli, ulli> >A;
            lli sum = 0;
            A.resize(n);
            lli ind = i;
            Carr[ind].second = ind;
            Carr[ind].first = 0;
 
            for(ulli j = 0; j < n; j++){
                A[j].first = C[ind][j];
                A[j].second = j;
            }
 
            sort(A.begin(), A.end());
            ulli count = 0;
            
            ulli min = 999999999999;
            for(lli j = 0; j < n; j++){
                if(A[j].second != ind)
                    sum += A[j].first;
                if(sum + H[ind][j] < min){
                    Carr[ind].first = sum + H[ind][j];
                    min = sum + H[ind][j];
                    maxEdge[ind] = A[j].first;
                }
            }
        }
 
        sort(Carr.begin(), Carr.end()); 

        /*for(ulli i = 0; i < n; i++){
            vectPos[Carr[i].second] = i;
        }*/
 
 
        ulli Ccount[n];
        ulli traversed[n];
 
        for(ulli i = 0; i < n; i++){
            traversed[i] = 0;
            Ccount[i] = 0;
        }
 
        for(ulli ind = 0; ind < n; ind++){
            ulli i = Carr[ind].second;
            //ulli i = ind;
            vector<pair<ulli, ulli> >A;
            A.resize(n);
 
            for(ulli j = 0; j < n; j++){
                A[j].first = C[i][j];
                A[j].second = j;
            }
            
            sort(A.begin(), A.end()); 
 
            //This is I am doing to make sure that this office is at least connected
            
            if(traversed[i] != 1){
                ulli trav_flag = 0;
                ulli j = 0;
                while(trav_flag == 0 && ind!=0){
                    dout << "hello for i:" << i << endl;
                    if(maini[i][A[j].second] == 0 && i != A[j].second){ 
                        if(traversed[A[j].second] == 1){
                            maini[i][A[j].second] = 1;
                            maini[A[j].second][i] = 1;
                            Ccount[i] ++;
                            Ccount[A[j].second]++;
                            trav_flag = 1;

                            //This is if by chance the edge connecting is greater than
                            //the maximum of the Carr[i]. 
                            /*dout << "checking whether needs to be optimised" << endl;
                            if(maxEdge[A[j].second] < C[i][A[j].second]){
                                dout << "this needs to be optimised" << endl;
                                optimise(Carr, maxEdge[A[j].second], C[i][A[j].second], vectPos[A[j].second]); 
                                
                                dout << "optimised" << endl;
                                maxEdge[A[j].second]= C[i][A[j].second];
                                sort(Carr.begin(), Carr.end());

                                for(ulli k = 0; k < n; k++){
                                    vectPos[Carr[k].second] = k;
                                }
                            }*/

                        }
                    }
                    j++;
                }
            }
 
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
					if(traversed[A[j].second] == 1 || traversed[A[j].second] == 0){
						sum += A[j].first;
						count++;
						if(sum + H[i][Ccount[i]+count] < min){ 
							min = sum  + H[i][Ccount[i]+count];
							minCount = count;
							flag = 1;
						}
					}
                }
            }
 
 
            //If a minimum combination exists then I will commit the changes
            if(flag == 1){
                ulli tcount = 0;
                ulli j = 0;
 
                while(tcount < minCount && j < n){
 
                    if((maini[i][A[j].second] == 0 && i != A[j].second)){
                        if(traversed[A[j].second] == 1 || traversed[A[j].second] == 0){
                            maini[i][A[j].second] = 1;
                            maini[A[j].second][i] = 1;
                            Ccount[i] ++;
                            Ccount[A[j].second]++;
                            tcount++;
                            traversed[A[j].second] = 1;
                            
                            //This is if by chance the edge connecting is greater than
                            //the maximum of the Carr[i]. 
                            /*if(maxEdge[A[j].second] < C[i][A[j].second]){
                                dout << "this needs to be optimised" << endl;
                                optimise(Carr, maxEdge[A[j].second], C[i][A[j].second], vectPos[A[j].second]); 
                                dout << "optimised" << endl;

                                maxEdge[A[j].second]= C[i][A[j].second];
                                sort(Carr.begin(), Carr.end());

                                for(ulli k = 0; k < n; k++){
                                    vectPos[Carr[k].second] = k;
                                }
                            }*/
                        }
                    }
 
                    j++;
                }
            }
 
            traversed[i] = 2;
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
