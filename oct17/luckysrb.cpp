#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

int m;

class Edge{
    public: 
    int num; 
    int left,right; 

    Edge(){}
    Edge(int l,int r,int n){
        left = l;
        right = r;
        num = n;
    }
}edge_list[5002];

class Node{
    public:
    vector<Edge> connected;//list of edges to this node
    int visited;
    
    Node(){}
    void clear(){
        connected.clear();
    }
}node[10004];

bool dfs(int l,int r,int i,int n){
    node[n].visited = 1;

    if(n==edge_list[i].right)//got the second corner of edge
        return true;

    for(Edge edge : node[n].connected){
        if(edge.num <= r && edge.num >=l && edge.num!=i && node[edge.right].visited==0){
            if(dfs(l,r,i,edge.right))
                return true;
        }
    }
    return false;
}


/*
 * returns true if i is lucky in interval l,r
 */
bool islucky(int l,int r,int i){
    if(i > r || i < l) return false;//just for safety

    for(int j=1;j<=10002;j++)//unvisit all
        node[j].visited = 0;
    
    return dfs(l,r,i,edge_list[i].left);//start from left vertex of edge i
}

int main(){
    int t;
    cin>>t;
    while(t--){
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
    }//end test case
}
