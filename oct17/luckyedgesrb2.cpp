#include<bits/stdc++.h>
#define dout if(debugg)cout<<" "
using namespace std;
 
int debugg =1;
typedef long long int ulli;
 
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
    vector<Edge> connected;
    int visited;
    
    Node(){}
    void clear(){
        connected.clear();
    }
}node[100002];
 
bool dfs(int l,int r,int i,int n){
    dout<<"dfs n : "<<n<<endl;
    node[n].visited = 1;
    if(n==edge_list[i].right)
        return true;
    dout << "size:" << node[n].connected.size()<< endl;
    for(Edge edge : node[n].connected){
        dout <<"edge num " <<  edge.num << endl;
        dout <<"edge right " <<  edge.right << endl;
        dout << "edge visited" << node[edge.right].visited << endl;
        if(edge.num <= r && edge.num >=l && edge.num!=i && node[edge.right].visited==0){
            dout << "going through dfs " << endl;
            if(dfs(l,r,i,edge.right))
                return true;
        }
    }
    return false;
}
 
int m;
bool islucky(int l,int r,int i){
    dout<<"starting for "<<l<<" "<<r<<" "<<i<<endl;
    for(int j=1;j<=10002;j++)
        node[j].visited = 0;
    
    return dfs(l,r,i,edge_list[i].left);     
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
        //done input
       
        int l,r; 
        for(int i=1;i<=m;i++){
            ulli ans=0; 
            l=1;r=i;
            while(true){
                dout<<"iteration for "<<l<<" "<<r<<endl;
                if(l > i || r > m)
                    break;
                if(islucky(l,r,i)){
                    ans+=m-r+1;
                    l++;
                    dout<<"yes "<<ans<<endl;
                    if(l>i)break;
                }
                else{
                    r++;
                    dout<<"no"<<endl;
                }
            }             
            cout<<"Here is the answer" << ans<<" " << endl;
        }
        cout<<endl;
    }
}
