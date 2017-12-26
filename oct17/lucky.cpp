#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
int m;

class Edge{
    public:
        int num;
        int left, right;

        Edge(){}
        Edge(int l, int r, int n){
            left = l;
            right = r;
            num = n;
        }
}edge_list[5002];

class Node{
    public:
        vector<Edge> connected;
        int visited;

       void clear(){
           connected.clear();
       }

        Node(){}
}node[1000002];

bool dfs(int l, int r, int i, int n){
    node[n].visited = 1;
    if(n== edge_list[i].right)
        return true;

    for(Edge edge : node[n].connected){
        if(edge.num <= r && edge.num >= l && edge.num != i && node[edge.right].visited == 0)
            if(dfs(l, r, i, edge.right))
                return true;
    }
    return false;
}

bool islucky(int l, int r, int i){
    if(i < l || i > r) return false;

    int j = 1;
    while(j <= m){
        node[j].visited = 0;
        j++;
    }

    return dfs(l, r, i, edge_list[i].left);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;

    for(int y = 0; y < t; y++){
        cin>>m;
        for(int i=0;i<10002;i++)
            node[i].clear();
        
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            node[a].connected.push_back(Edge(a,b,i));
            node[b].connected.push_back(Edge(b,a,i));
            edge_list[i] = Edge(a,b,i);
        }
       
        for(int i=1;i<=m;i++){
            ulli ans=0; 
            for(int l=1;l<=m;l++)
                for(int r=1;r<=m;r++)
                    if(islucky(l,r,i))//check if i is lucky in interval l,r
                        ans++;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
 
	return 0;
}
