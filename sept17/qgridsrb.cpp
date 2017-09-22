#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
typedef pair<ulli,ulli> mp; 
typedef pair<mp,ulli> mpp;

ulli down[4][100100], rightele[4][100100];
ulli weight[4][100100];
ulli check[4][100100];
ulli dist[4][100100];
ulli parentx[4][100100];
ulli parenty[4][100100];


class vertex{
    public:
    ulli dist;
    ulli weight;
    ulli parentx,parenty;
    vector<pair<mp,ulli> > next;
    void clear(){
        weight=0;
        dist=LONG_MAX;
        next.clear();
    }
    
    vertex(){
        clear();
    }
    
    void setparent(ulli px,ulli py){
        parentx=px;
        parenty=py;
    }
} vertex[5][100009];
 
struct priority_fxn{
    bool operator() (mp a,mp b){
       return  vertex[b.first][b.second].dist < vertex[a.first][a.second].dist ; 
    }
};
void dijikstra(ulli sx,ulli sy,ulli ex,ulli ey,ulli update){
    priority_queue<mp ,vector<mp >,priority_fxn> q;
    set<mp> dist_sett;
    ulli d,n1,n2;
    mp temp;

    vertex[sx][sy].dist=0;
    vertex[sx][sy].setparent(sx,sy);
    
    q.push(mp(sx,sy));
    dist_sett.insert(mp(sx,sy));
   
    while(!q.empty()){
        n1=q.top().first;
        n2=q.top().second;
        if(n2==ey && n1==ex)
        	break;
        for(ulli i=0;i<vertex[n1][n2].next.size();i++){
            temp=vertex[n1][n2].next[i].first;
            d=vertex[n1][n2].next[i].second;
            if(vertex[n1][n2].dist + d <  vertex[temp.first][temp.second].dist){
                vertex[temp.first][temp.second].dist = vertex[n1][n2].dist + d;
                vertex[temp.first][temp.second].setparent(n1,n2);
                dist_sett.insert(temp);
                q.push(temp);
            }    
        }
        q.pop();
    }//end while loop

    //set dist back to INT_MAX
    for(auto elem : dist_sett){
        vertex[elem.first][elem.second].dist=LONG_MAX;
    }
    dist_sett.clear();

    while(!q.empty())//just to save memory clear the queue
        q.pop();
    
    while(n1!=sx || n2!=sy){
       vertex[n1][n2].weight+=update;
       int na=n1, nb=n2;
       n1=vertex[na][nb].parentx;
       n2=vertex[na][nb].parenty;
    }
    vertex[n1][n2].weight+=update;
}
 
int main(){
    ulli m,n,q,d,type;
    cin>>m>>n>>q;
    for(ulli i=1;i<m;i++){
        for(ulli j=1;j<=n;j++){
            cin>>d;
            vertex[i][j].next.push_back(mpp(mp(i+1,j),d));
            vertex[i+1][j].next.push_back(mpp(mp(i,j),d));
        }
    }
    for(ulli i=1;i<=m;i++){
        for(ulli j=1;j<n;j++){
            cin>>d;
            vertex[i][j].next.push_back(mpp(mp(i,j+1),d));
            vertex[i][j+1].next.push_back(mpp(mp(i,j),d));
        }
    }
    ulli sx,sy,ex,ey,update;
    for(ulli i=1; i<=q; i++){
        cin>>type;
        if(type==1){
        	cin>>sx>>sy>>ex>>ey>>update;
        	if(m!=1)
        	{
            	dijikstra(sx,sy,ex,ey,update);
            }
            else
            {
                if(sy>ey)
                {
                    int temp=sy;
                    sy=ey;
                    ey=temp;
                }
            	//cout<<"hello"<<endl;
            	for(ulli k=sy; k<=ey; k++)
            		vertex[1][k].weight+=update;
            }
        }
        else{
            cin>>sx>>sy;
            cout<<vertex[sx][sy].weight<<endl;
        }
    }
}
