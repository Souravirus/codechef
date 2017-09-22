#include<bits/stdc++.h>
#define mp pair<int,int>
using namespace std;
vector<pair<int,int> > edge;

bool sortedg(pair<int,int> a,pair<int,int>b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main(){
    int t,n,m,a,b,flag,l,cnt,lmax;
    int c0;//children of 0
    cin>>t;
    while(t--){
        cin>>n>>m;
        flag=1;
        edge.clear();
        vector<int> ans(n+1,0);

        c0=0;//to start count of children of 0
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(b<=a)flag=0;
            if(a==0)c0++;
            edge.push_back(mp(a,b));
        }
        if(flag==0){//filter out cases with edge from higher to lower node like from 4 to 2
            cout<<-1<<endl;
            continue;
        }

        sort(edge.begin(),edge.end(),sortedg);//sort them in my way
        set<int> usable;
        set<int> used;
        set<int>::iterator it;
        vector<int> lastchild(c0+1,0);//store value of last occurance of given child
        for(int i=1;i<=c0;i++)//insert in used they will be copied to usable
            used.insert(i);
        l=-1;//for checking master branch theorm
        vector<int> collector;
        for(int i=0;i<edge.size();i++){
//            cout<<edge[i].first<<" "<<edge[i].second<<endl;
            if(edge[i].first==l+1){
//                cout<<"started ::::: "<<edge[i].first<<endl;
                l=edge[i].first;
                if(edge[i].first!=edge[i].second-1){//elem k must b cnnected to k+1
                    flag=0;
                    break;
                }
                usable.clear();
                usable=used;
                used.clear();
            }
            else if(edge[i].first>l+1){//skips a particular node
                flag=0;
//                cout<<"skip a node "<<i<<endl;
                break;
            }
            
            if(ans[edge[i].second]==0){//it is its unique
                for(it=usable.begin();it!=usable.end();it++){
                    if(lastchild[*it]<edge[i].second){//if it is applicable
                        usable.erase(*it);
                        used.insert(*it);
                        ans[edge[i].second]=*it;
                        lastchild[*it]=edge[i].second;
                        break;
                    }
                }
                if(it==usable.end()){
//                    cout<<"got no var to insert at "<<edge[i].second<<endl;
                    flag=0;
                    break;
                }
            }
            else{//already filled by someone
                used.insert(ans[edge[i].second]);
                usable.erase(ans[edge[i].second]);
            }
        }
        if(flag==0){
            cout<<-1<<endl;
            continue;
        }

        //check validity against no extra edges
        vector<int> lastoccr(n+1,0);
        int edgesum=0;
        for(int i=1;i<=n;i++){
            edgesum+=i-lastoccr[ans[i]];
            lastoccr[ans[i]]=i;
        }
        if(edgesum>m){
//            cout<<"more edge than in graph : "<<edgesum<<endl;
            cout<<-1<<endl;
            continue;
        }

        //output
//        cout<<"ans"<<endl;//debugg
        for(int i=1;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }//end test while
}

