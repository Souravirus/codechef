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
lli root = 3;
 
lli binSearch(lli L, vector<lli >&hidden, lli s, lli e, lli max){   
    while(s<=e){
        lli mid = (s+e)/2;
        if(hidden[mid] == L){
            return mid; 
        }
        else if(hidden[mid] < L){
            s = mid+1;
        }
        else{
            max = mid; 
            e = mid-1;
        }
    }
    return max;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli T;
    cin >> T;
 
    while(T--){
        lli N, Q;
        cin >> N >> Q;  
        lli arr[N];
 
        for(lli i = 0; i < N; i++){
            cin >> arr[i]; 
        }
        lli ind = 0;
        vector<vector<lli> >sqrtdec;
        vector<lli> vect;
 
        while(ind < N){
 
            if(ind % root == 0 && ind!=0){
                sqrtdec.push_back(vect);
                vect.clear();
                vect.push_back(arr[ind]);
            }
 
            else{
                vect.push_back(arr[ind]);
            }
            
            ind++;
        }
 
        sqrtdec.push_back(vect);
 
        vector<vector<lli> > hidden;
        vect.clear();
        
        for(lli i = 0; i < sqrtdec.size(); i++){
            lli max = -1;
            for(lli j = 0; j < sqrtdec[i].size(); j++){
                if(sqrtdec[i][j] > max){
                    max = sqrtdec[i][j];
                    vect.push_back(max);
                }
            }
            hidden.push_back(vect);
            vect.clear();
        }
 
        dout << "hidden size" << hidden.size() << endl;
        char type;
 
        for(lli i = 0; i < Q; i++){
            cin >> type;
 
            if(type == '?'){
                lli x, L, R;
                cin >> x >> L >> R;
                lli sum = 0;
 
                ind = (x-1)/root;
                lli rem = (x-1)%root;
 
                lli flag = 0;
                
                //if(ind < sqrtdec.size()){
                    for(lli j = rem; j < sqrtdec[ind].size(); j++){
 
                        if(sqrtdec[ind][j] >= L){
                            sum ++;
                            L=sqrtdec[ind][j]+1;
                            if(L > R){
                                flag = 1;
                                break;
                            }
                        }
                    }
                    ind++;
               // }
                lli index, hidsize;
 
                while(ind < hidden.size() && flag == 0){
               // while(flag==0){
 
                    index = binSearch(L, hidden[ind], 0, hidden[ind].size()-1, -1); 
 
                    if(index != -1){
                         hidsize = hidden[ind].size()-1;
 
                       if(hidden[ind][hidsize] >= R){
                           for(lli j = index; j < hidden[ind].size(); j++){
 
                                if(hidden[ind][j] >= L){
                                    sum++;
                                    L=hidden[ind][j]+1;
 
                                    if(L > R){
                                        break;
                                    }
                                }
 
                           }
                           flag = 1;
                       }
 
                        else {
                            L = hidden[ind][hidden[ind].size()-1] + 1;
                           sum += hidden[ind].size() - index; 
                        }
                    }
                    ind++;
                }
 
                 printf("%lld\n", sum);
            }
 
            else if (type == '+'){
                lli x, L;
                cin >> x >> L;
                lli ind = (x-1)/root;
                lli rem = (x-1)%root;
                sqrtdec[ind][rem] += L;
 
                lli max = -1;
                hidden[ind].clear();
 
                for(lli j = 0; j < sqrtdec[ind].size(); j++){
 
                    if(sqrtdec[ind][j] > max){
                        max = sqrtdec[ind][j];
                        hidden[ind].push_back(max);
                    }
                }
            }
        }
    }
    
	return 0;
}
