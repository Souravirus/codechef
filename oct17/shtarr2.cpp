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

vector<lli>great;

void NGE(lli arr[], lli n, vector<lli> &great){

    stack<pair<int, int> > mystack;
    int  next;
    pair<int, int> element;

    for(int i = 1; i <= n; i++){
        next = arr[i];

        if(!mystack.empty()){
            element = mystack.top();
            mystack.pop();

            while(element.first < next){
                great[element.second] = i;
                if(mystack.empty())
                    break;
                element = mystack.top();
                mystack.pop();
            }
            
            if(element.first >= next)
                mystack.push(element);
        }
        
        mystack.push(mp(next, i));
    }

    while(!mystack.empty()){
        element = mystack.top();
        mystack.pop();
        great[element.second] = -1; 
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli T;
    cin >> T;
    lli N, Q;

    while(T--){
        cin >> N >> Q;
        lli arr[N];
        great.resize(N+1);
        for(lli i = 1; i <= N; i++){
            cin >> arr[i];
        }

        NGE(arr, N, great);
        /*dout << "Showing the greats" << endl;
        for(int i = 1; i<=N; i++)
            dout << great[i] << endl;
            */
        char type;
        lli x, L, R; 

        for(lli i = 1; i <= Q; i++){
            cin >> type;

            if(type == '?'){
                cin >> x >> L >> R;
                lli count = 0, currHeight = L, size = R-L+1, next = x, j=0;

                while(next != -1 && count < size){

                    if(currHeight <= arr[next]){
                        count += arr[next] - currHeight + 1 ;
                        dout << "arr[next] : " << arr[next] << endl;
                        currHeight = arr[next]+1;
                        j++;
                    }
                    
                    next = great[next];
                }
                cout << j << endl;
            }

            if(type == '+'){
                cin >> x >> L;
                arr[x]+=L;
                great.clear();
                NGE(arr, N, great); 
            }
        }

    }
	return 0;
}
