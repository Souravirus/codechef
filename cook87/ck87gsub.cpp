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
    string s;
    cin >> T;
    while(T--){
        cin >> s;
        int count = 0;
        if(s.length() > 1){
            lli sum = 0;
            lli state = 0, count = 0, pos1 = 0, pos2 = 0;
            while(count < s.length()){
                if(state == 0){
                    if(s[count] == s[count+1]){
                        state = 1;
                        pos1 = count;
                        count+=2;
                    }
                    
                    else{
                        state = 2;
                        pos1 = count;
                        pos2 = count+1;
                        count+=2;
                    }
                }

                else if(state == 1){
                    lli tpos = pos1, n;
                    while(state == 1 && count < s.length()){

                        if(s[count] == s[pos1]){
                            count++;
                        }

                        else{
                            state = 2;
                            pos1 = count-1;
                            pos2 = count;
                            n = count-tpos; 
                            count++;
                        }
                    } 
                    if(count < s.length()){
                        sum += (((n)*(n-1))/2); 
                    }
                    else{
                        n=count - tpos;
                        sum += (((n)*(n-1))/2);
                    }
                }

                else if(state == 2){
                    lli flag = 0, n, tpos1 = pos1, tpos2 = pos2;
                    while(state == 2 && count < s.length()){
                        if(s[count] == s[pos1]){
                            flag = 1; 
                            pos1 = count-1;
                            pos2 = count;
                            n = count - tpos2;
                            count++;
                            break;
                        }

                        else if(s[count] == s[pos2]){
                            count++; 
                            continue;
                        }

                        else{
                            flag = 2;
                            pos1 = count-1;
                            pos2 = count;
                            n = count - tpos2;
                            count++;
                            break;
                        }
                    }

                    if(flag == 1){
                        sum+=(((n)*(n-1))/2) + 1;
                    }

                    else if(flag ==2){
                        sum+=(((n)*(n-1))/2);
                    }
                    
                    else{
                        n = count - tpos2;    
                        sum+=(((n)*(n-1))/2);
                    }
                }
            }
            cout << sum << endl;
        }
        else
            cout << "0" << endl;
    }
	return 0;
}
