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

class edge{
    public:
        int source;
        int dest;
        int num;
        edge(){} 
        edge(int s, int e, int num){
            source = s;
            dest = e;
            this -> num = num;
        }
}edgeList[5002];

class node{
    public:
        int visited;
        vector<edge> connected;
        node(){}
}kappa[100005];

int dfs(int l, int r, int i, int n){
    dout << "dfs n:" << n << endl;
    //dout << "for this cycle all visited" << endl;
    kappa[n].visited = 1;
    if(n == edgeList[i].dest)
        return 1;
    
    int j = 0;
    dout << "kappa size:" << kappa[n].connected.size() << endl;

    while(j < kappa[n].connected.size()){
        edge currEdge = kappa[n].connected[j];
        dout << "currEdge.num" << currEdge.num << endl;
        dout << "currEdge.dest" << currEdge.dest << endl;
        dout << "curredge visited " << kappa[currEdge.dest].visited << endl;
        if(currEdge.num <= r && currEdge.num >= l && currEdge.num != i && kappa[currEdge.dest].visited == 0){
            dout << "currEdge.num" << currEdge.num << endl;
            if(dfs(l, r, i, currEdge.dest))
                return 1;
        }
        j++;
    }
    return 0;
    
}

int lucky(int l, int r, int i){
    dout <<"starting for " << l<< " " << r<< " " << i << endl;
    return dfs(l, r, i, edgeList[i].source);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;

    for(int y = 0; y < t; y++){
        int m;
        cin  >> m;
        for(int i = 0; i < 10004; i++)
            kappa[i].connected.clear();
        int s, e;

        int i = 1;
        while(i <= m){
            cin >> s >> e;
            kappa[s].connected.push_back(edge(s, e, i)); 
            kappa[e].connected.push_back(edge(e, s, i));
            edgeList[i] = edge(s, e, i);
            i++;
        }
        
        i = 1;
        int l, r;
        while(i <= m){
            dout << "iteration for " << l << " " << r << endl;
            ulli ans = 0;
            l = 1, r = i;
            int j = 1;


            while(true){
               r = binSearch(l, r, m, i, m+1);
               if(r > m)
               	break;
               ans += m-r+1;
               l++;
               if(l>i)
               	break;
               
            }
            dout << "here is the answer" << endl;
            cout << ans << " ";
            i++;
        }

        cout << endl; 
    }
	return 0;
}
