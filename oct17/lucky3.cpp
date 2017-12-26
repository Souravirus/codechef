#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

struct Path{
    int num; 
    int prev,next; 

    Path(){}
    Path(int l,int r,int n){
        prev = l; next = r; num = n;}
};
vector<Path> edge_list(5002);

struct Node{
    vector<Path> connected;
    int visited;
    
    Node(){}
};
vector<Node> node(10005);

bool moveon(int l,int r,int i,int n){
    node[n].visited = 1;

    for(int edgeno = 0 ; edgeno<node[n].connected.size(); edgeno++){
        Path edge = node[n].connected[edgeno]; 
        if(edge.num <= r && edge.num >=l && edge.num!=i && node[edge.next].visited==0){
            if(edge.next == edge_list[i].next)
                return true;
            if(moveon(l,r,i,edge.next))
                return true;
        }
    }
    return false;
}

int max_nodes;
bool isgood(int l,int r,int i){
    for(int h=0;h<max_nodes;h++){
        node[h].visited = 0; 
    }    

    return moveon(l,r,i,edge_list[i].prev); 
}


    
/*
 * return position of last elem less than or equal to num
 * best is best position till now
 */
int binary_search(int l,int r,int num,int i,int best){
    if(r<l) return best;//search ends

    int m = (l+r)/2;

    if(isgood(num,m,i)){//out of reach ... go back
        best = m;
        return binary_search(l,m-1,num,i,best);
    }
    else{//num is small.. go forward
        return binary_search(m+1,r,num,i,best);//search for bigger
    }
}

int search(int l,int r,int m,int i){
    return binary_search(r,m,l,i,m+1);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++){
        int m,maxx = 0,l,r;
        scanf("%d",&m);

        for(int i=0;i<10002;i++)
            node[i].connected.clear();
        
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            node[a].connected.push_back(Path(a,b,i));
            node[b].connected.push_back(Path(b,a,i));
            edge_list[i] = Path(a,b,i);

            if(maxx < max(a,b) )
                maxx = max(a,b);
        }
        max_nodes = maxx + 4;
       
        for(int i=1;i<=m;i++){
            ulli ans=0; 
            l=1;r=i;
            while(1){
                r = search(l,r,m,i);
                if (r>m) break;
                ans+=m-r+1;
                
                l++;
                if(l>i)
                    break;
            }//end while
            printf("%lld ",ans);
        }
        printf("\n");
    }
}

