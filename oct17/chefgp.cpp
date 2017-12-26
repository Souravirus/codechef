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

int apos(int currpos, string str){
    if(currpos == str.size())
        return -1;
    for(int i = currpos; i < str.size(); i++){
        if(str[i] == 'a')
            return i;
    }
    return -1;
}

int bpos(int currpos, string str){
    if(currpos == str.size())
        return -1;
    for(int i = currpos; i < str.size(); i++){
        if(str[i] == 'b')
            return i;
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;

    while (T--){
        string str;
        int tol1, tol2;
        cin >> str;
        cin >> tol1 >> tol2;
        int nexta = apos(0, str);
        int nextb = bpos(0, str);
        char prev = str[0]; 
        int checker[str.size()] = {0};
        int currtol1, currtol2;

        if(str[0] == 'a'){
            currtol1 = 0;
            currtol2 = -1;
        }

        else{
            currtol2 = 0;
            currtol1 = -1;
        }
        
        for(int i = 1; i < str.length(); i++){

            if(str[i] == 'a'){
                dout << "currtol a " << currtol1 << endl;
                if(prev == 'a')        
                    currtol1++;

                else{
                    currtol1 = 0;
                }

                if(currtol1 >= tol1){

                    dout << "inside a current tol:"<< currtol1 << endl;

                    if(nextb != -1){
                        dout << "inside nextb != -1" << endl;

                        str.replace(nextb, 1, "a");
                        str.replace(i, 1, "b"); 
                        dout << "curr str:" << str << endl;

                        finalstr.push_back('b');
                        nextb = bpos(nextb+1, str);

                        dout << "next b:" << nextb << endl;

                        currtol1 = -1;
                        currtol2 = 0;
                        prev = 'b';

                    }
                    
                    else{
                        dout << "inside nextb == -1" << endl;

                        finalstr.push_back('*');
                        finalstr.push_back('a');

                        prev = 'a';
                    }

                      
                }

                else{
                    finalstr.push_back('a');
                    prev = 'a';
                }

            }

            else if(str[i] == 'b'){
                
                dout << "currtol b " << currtol2 << endl;
                if(prev == 'b')        
                    currtol2++;

                else
                    currtol2 = 0;

                if(currtol2 >= tol2){
                    dout << "inside a current tol:"<< currtol2 << endl;

                    if(nexta != -1){
                        dout << "inside nexta != -1" << endl;

                        str.replace(nexta, 1, "b");

                        dout << "current str:" << str << endl;

                        finalstr.push_back('a');
                        nexta = apos(nexta+1, str);

                        currtol2 = -1;
                        currtol1 = 0;
                        prev = 'a';
                    }
                    
                    else{
                        dout << "inside nexta == -1" << endl;
                        finalstr.push_back('*');
                        finalstr.push_back('b');
                        prev = 'b';
                    }
                      
                }

                else{
                    finalstr.push_back('b');
                    prev = 'b';
                }

            }
        }
        for(int i = 0; i < finalstr.size(); i++)
            cout << finalstr[i] ;
        cout << endl;
    }

	return 0;
}
