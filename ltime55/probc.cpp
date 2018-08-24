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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int> > > connections; 
    connections.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int from, to, cost; 
        cin >> from >> to >> cost;
        
        connections[from].push_back(mp(to, cost));
        connections[to].push_back(mp(from, cost));
    }

    /*for(int i = 1; i < n+1; i++){
        dout << "for i:" << i << endl;
        for(int j = 0; j < connections[i].size(); j++){
            dout << "first:" << connections[i][j].first << " second:" << connections[i][j].second << endl;
        }
    }*/

    int last = 0;

    for(int i = 0; i < q; i++){
        int in[8];
        for(int j = 0; j < 8; j++){
            cin >> in[j]; 
        }
        
        int U = last + in[0];
        int V = last + in[1];
        int X1 = last + in[2];
        int Y1 = last + in[3];
        int X2 = last + in[4];
        int Y2 = last + in[5];
        int X3 = last + in[6];
        int Y3 = last + in[7];

        stack<int> mystack;
        vector<int> visited;
        stack<int > store;
        visited.resize(n+1);
        for(int j = 0; j < n+1; j++){
            visited[j] = 0;
        }
        int vectInd = 0;
        mystack.push(U);

        while(!mystack.empty()){
            int node = mystack.top();
            dout << "node:" << node << endl;
            if(node == V){
                break;
            }
            int flag = 0;

            for(int j = 0; j < connections[node].size(); j++){
                if(visited[connections[node][j].first] == 0){
                    mystack.push(connections[node][j].first);
                    flag = 1;
                    store.push(connections[node][j].second);
                    dout << "pushing" << store.top() << endl;
                }
           	}

            visited[node] = 1;

            if(flag == 0){
                mystack.pop();
                store.pop(); 
            }
        }

        int tCost = 0;

        while(!store.empty()){
            int flag = 0;
            int flagNP = 0;
            int mini, maxi;
            if(store.top()%2 == 0){
                flag = 1;
                mini = min(X1, Y1);
                maxi = max(X1, Y1);
                if(store.top() < mini || store.top() > maxi)
                    flagNP = 1;
           }
            if(store.top()%3 == 0){
                flag = 1;
                mini = min(X2, Y2);
                maxi = max(X2, Y2);
                if(store.top() < mini || store.top() > maxi)
                    flagNP = 1;
           }
            if(store.top()%5 == 0){
                flag = 1;
                mini = min(X3, Y3);
                maxi = max(X3, Y3);
                if(store.top() < mini || store.top() > maxi)
                    flagNP = 1;
           }

            if(flag == 1 && flagNP == 0){
                tCost += store.top();
            }

            store.pop();
        }

        cout << tCost <<  endl;
        last = tCost%100000;
    }
	return 0;
}
