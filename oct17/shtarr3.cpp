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
        lli max = -1; 

        for(lli i = 0; i < sqrtdec.size(); i++){
            lli count = 0;
            for(lli j = 0; j < sqrtdec[i].size(); j++){
                if(sqrtdec[i][j] > max){
                    max = sqrtdec[i][j];
                    hidden[i].push_back(max);
                    count ++;
                }
            }
        }

        /*dout << "Hidden array" << endl;
        for(lli i = 0; i < hidden.size(); i++){
            for(lli j = 0; j < hidden[i].size(); j++)
                dout << hidden[i][j] << " ";
            dout << endl;
        }*/

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
                lli flag1 = 0;
                
                for(lli j = rem; j < sqrtdec[ind].size(); j++){

                    if(sqrtdec[ind][j] >= L){
                        L = sqrtdec[ind][j]+1;
                        dout << "find a building shot " << sqrtdec[ind][j] << endl;
                        sum++;

                        if(L > R){
                            flag = 1;
                            break;
                        }
                        flag1 = 1;
                    }
                }
                ind++;
                
                while(flag1 == 0 && ind < hidden.size()){
                    dout << "in while flag1 loop ind:" << ind << endl;
                    if(hidden[ind].empty()){
                        ind++;
                        continue;
                    }
                    if(L > hidden[ind][hidden[ind].size()-1]){
                        dout << " L was greater than last element" << endl;
                        ind++;
                        continue;
                    }
                    else{
                        dout << "in else condition" << endl;
                        for(lli j = 0; j < hidden[ind].size(); j++){
                            if(hidden[ind][j] >= L){
                                L = hidden[ind][j] + 1;
                                sum++;
                                flag1 = 1;
                                if(L > R){
                                    flag = 1;
                                    break;
                                }
                            }
                        }
                    }
                    ind++;
                }

                while(flag == 0 && ind < hidden.size()){
                    dout << "gone in while loop" << endl;

                    if(hidden[ind].empty()){
                        ind++;
                        continue;
                    }

                    if(hidden[ind][hidden[ind].size()-1] <= R){
                        dout << "here the last came smaller than R" << endl;
                        sum += hidden[ind].size();
                        L = hidden[ind][hidden[ind].size()-1]+1; 
                        dout << "curr L: " << L << endl;
                    }

                    else{
                        dout << "last came greater than R" << endl;
                        for(lli  j = 0; j < hidden[ind].size(); j++){
                            dout << "curr L: " << L << endl;
                                L = hidden[ind][j]+1;
                                sum++;
                                if(L > R){
                                    flag = 1;
                                    break;
                                }
                        }
                    }
                    ind++;
                }
                cout << sum << endl;
            }
            
            else if (type == '+'){
                lli x, L;
                cin >> x >> L;
                ind = (x-1) / root;
                lli rem = (x-1) % root;

                lli j = ind-1;
                lli flag = 0;
                lli prev = 0;
                sqrtdec[ind][rem] += L;

                while( j >= 0){

                    if(hidden[j].empty()){
                        j--;
                        continue; 
                    }

                    else{
                        prev = hidden[j][hidden[j].size()-1];
                        break;
                    }
                }
                
                flag = 0;
                lli last = -1 ;

                for(lli j = rem-1; j >= 0; j--){
                    if(sqrtdec[ind][j] > sqrtdec[ind][rem]){
                        flag = 1;
                        break;
                    }
                }
                
                if(prev > sqrtdec[ind][rem] || flag == 1)
                    continue;

                if(!hidden[ind].empty()){ 
                    lli last = hidden[ind][hidden[ind].size() - 1];
                }

                hidden.clear();
                
                lli max = prev; 
                for(lli j = 0; j < sqrtdec[i].size(); j++){
                    if(sqrtdec[ind][j] > max){
                        max = sqrtdec[ind][j];
                        hidden[ind].push_back(max);
                    }
                }

                lli flag1 = 1;

                if(last != -1){
                    if(hidden[ind][hidden[ind].size()-1] == last)
                        flag1 = 0;
                }

                else
                    last = hidden[ind][hidden[ind].size()];
                
                if(flag1 == 1){
                    ind++;
                    while(ind < hidden.size() && last >= hidden[ind][hidden[ind].size()-1]){
                        hidden[ind].clear();
                        ind++;
                    }

                    for(lli j = 0; j < hidden[ind].size(); j++){
                        if(hidden[ind][j] <= last)
                            hidden[ind].erase(hidden[ind].begin()+j);
                        else
                            break;
                    }
                }
            }
        }
    }
    
	return 0;
}
