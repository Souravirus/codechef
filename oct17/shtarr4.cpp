#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
 
int debug = 1;
 
lli binSearch(lli L, vector<vector<lli> >hidden, lli ind, lli s, lli e, lli max){   
    dout << "in binSearch current s and e:" << s << e << endl;
    lli mid = (s+e)/2;
    dout << "hidden[mid]: " << hidden[ind][mid] << endl;
    if(s > e){
        dout << "returning because s > e" << endl;
        return max;
    }
    if(s == e){
        dout << "s became equal to e " << endl;
        if(hidden[ind][s] == L)
            return s;
        else if(hidden[ind][s] < L)
            return max;
        else
            return s;
    }
 
    if(hidden[ind][mid] == L){
        dout << "hidden[mid] became equal to L " << endl;
        return mid; 
    }
    else if(hidden[ind][mid] < L){
        dout << "hidden[mid] became less than to L " << endl;
        return binSearch(L, hidden, ind, mid+1, e, max);
    }
    else{
        dout << "hidden[mid] became greater to L " << endl;
        max = mid; 
        return binSearch(L, hidden, ind, s, mid-1, max);
    }
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
        
        lli root = sqrt(N);
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
        hidden.resize(sqrtdec.size());
        
        for(lli i = 0; i < sqrtdec.size(); i++){
            lli max = -1;
            for(lli j = 0; j < sqrtdec[i].size(); j++){
                if(sqrtdec[i][j] > max){
                    max = sqrtdec[i][j];
                    hidden[i].push_back(max);
                }
            }
        }
 
        char type;
        for(lli i = 0; i < Q; i++){
            cin >> type;
 
            if(type == '?'){
                lli x, L, R;
                cin >> x >> L >> R;
                lli sum = 0;
                ind = (x-1)/root;
                dout << "ind:" << ind << endl;
                lli rem = (x-1)%root;
                dout << "rem:" << rem << endl;
                lli flag = 0;
                
                if(ind < sqrtdec.size()){
                    dout << "In the if stat" << endl;
                    for(lli j = rem; j < hidden[ind].size(); j++){
                        
                        if(hidden[ind][j] >= L){
                            sum ++;
                            L=hidden[ind][j]+1;
                            dout << "found a num greater than L: " << hidden[ind][j] << endl;
                            dout << "L now: " << L << endl;
                            if(L > R){
                                flag = 1;
                                break;
                            }
                        }
                    }
                    ind++;
                }
 
                while(ind < sqrtdec.size() && L<=R && flag == 0){
                    dout << "Now in 2nd loop with ind: " << ind << endl;
                    dout << "curr L before binSearch: " << L << endl;
                    lli index = binSearch(L, hidden, ind, 0, hidden[ind].size()-1, -1); 
                    if(index != -1){
                        dout << "last element of hidden:" << hidden[ind][hidden[ind].size()-1] << " R" << R << endl; 
                       if(hidden[ind][hidden[ind].size()-1] > R){
                            dout << "in if condition where last building is greater that R" << endl;
                           for(lli j = 0; j < hidden[ind].size(); j++){
 
                                if(hidden[ind][j] >= L){
                                    sum++;
                                    L=hidden[ind][j]+1;
                                    dout << " curr L: " << L << endl;
 
                                    if(L > R){
                                        flag = 1;
                                        break;
                                    }
                                }
 
                           }
                       }
 
                       else {
                           dout << "in else condition" << endl;
                           L = hidden[ind][hidden[ind].size()-1] + 1;
                           dout << " curr L: " << L << endl;
                           sum += hidden[ind].size() - index; 
                           dout << " hiden[ind].size(): " << hidden[ind].size() << endl;
                       }
                    }
                    ind++;
                }
 
                cout << sum << endl;
            }
 
            else if (type == '+'){
                lli x, L;
                cin >> x >> L;
                lli ind = (x-1)/root;
                lli rem = (x-1)%root;
                dout << "sqrtdec[ind][rem]:" << sqrtdec[ind][rem] << endl;
                sqrtdec[ind][rem] += L;
                dout << "at changed pos num: " << sqrtdec[ind][rem] << endl;
 
                lli max = -1;
                hidden[ind].clear();
 
                for(lli j = 0; j < sqrtdec[ind].size(); j++){
 
                    if(sqrtdec[ind][j] > max){
                        max = sqrtdec[ind][j];
                        hidden[ind].push_back(max);
                        dout << "at hidden ind pushing: " << max << endl;
                    }
                }
            }
        }
    }
    
	return 0;
}
