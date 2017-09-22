#include<bits/stdc++.h>
using namespace std;
int n;
int t;
class Node
{
    public:
    int val;
    vector<int> family;
    int parent;
    Node()
    {
        val = 0;
        parent = 0;
    }
    void clear()
    {
        val=0;
        parent = 0;
        family.clear();
    }
};
Node node[1000002];
 
void merge(int a,int b,int v)
{
    int i=0;
    while(i<node[b].family.size())
    {
        node[a].family.push_back(node[b].family[i]);
        node[node[b].family[i]].parent=a;
        node[node[b].family[i]].val = node[node[b].family[i]].val ^ v;
        i++;
    }    
    cout<<endl;
    node[b].family.clear();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int z=t-1; z>=0; z--)
    {
        int flag=1,a,b,v,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            node[i].clear();
        while(q--)
        {
            cin>>a>>b>>v;
            if(a==b){
                if(v)
                    flag=-1;
                continue;
            }
            if(node[a].parent==0 && node[b].parent==0)
            {
                node[a].parent=a;
                node[b].parent=a;
                node[a].family.push_back(b);
                node[a].family.push_back(a);
                node[a].val=0;
                node[b].val=v;
            }
            else if(node[a].parent==0)
            {
                node[a].parent=node[b].parent;
                node[a].val=node[b].val ^ v;
                node[node[b].parent].family.push_back(a);
            }
            else if(node[b].parent==0)
            {
                node[b].parent=node[a].parent;
                node[b].val=node[a].val ^ v;
                node[node[a].parent].family.push_back(b);
            }
            else{
                if(node[a].parent==node[b].parent){
                    if(node[a].val ^ node[b].val != v)
                    {
                        flag=-1;
                    }
                }
                else{
                    if(node[node[a].parent].family.size() > node[node[b].parent].family.size())
                    {
                        merge(node[a].parent,node[b].parent,(node[b].val ^ v) ^ node[a].val);  
                    }
                    else
                    {
                        merge(node[b].parent,node[a].parent,(node[a].val ^ v) ^ node[b].val);  
                    }
 
                }
            }
        }
        if(flag!=-1)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
