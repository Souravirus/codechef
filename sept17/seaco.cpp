#include<bits/stdc++.h>
#define mod 1000000007
typedef unsigned long long int lli;

using namespace std;

void lazy_update(lli s,lli e,lli node_num, lli *seg_tree, lli *lazy)
{
  seg_tree[node_num] = (seg_tree[node_num]+(lazy[node_num]*(e-s+1))%mod)%mod;
  if(e>s)
  {
   lazy[node_num*2+1] = (lazy[node_num*2+1]+(lazy[node_num]%mod))%mod;
   lazy[node_num*2] = (lazy[node_num*2]+(lazy[node_num]%mod))%mod; 
  }
   lazy[node_num] = 0;
}

void set_lazy(lli s,lli e,lli new_val,lli node_num, lli *lazy)
{
   if(e>s)
   {
     lli m = (s+e)/2; 
    lazy[node_num*2+1] = (lazy[node_num*2+1]+(new_val%mod))%mod;
     lazy[node_num*2]= (lazy[node_num*2]+(new_val%mod))%mod;
   }
}

void range_update(lli l,lli r,lli new_val,lli s,lli e,lli node_num, lli *seg_tree, lli *lazy)
{ 
  if(lazy[node_num]>0)
    lazy_update(s,e,node_num, seg_tree, lazy);
  if(s>r || e<l)
    return;
  else if(s>=l && e<= r)
  {
    seg_tree[node_num]=(seg_tree[node_num]+(new_val*(e-s+1))%mod)%mod;
    //cout<<"updated at "<<node_num<<" new val "<<seg_tree[node_num]<<endl;
    set_lazy(s,e,new_val,node_num, lazy);
  }
  else
  {
    lli m = (s+e)/2;
    range_update(l,r,new_val,s,m,node_num*2, seg_tree, lazy);
    range_update(l,r,new_val,m+1,e,node_num*2+1, seg_tree, lazy);
	seg_tree[node_num] = (seg_tree[node_num*2] + seg_tree[node_num*2+1])%mod;
  }
}

lli query(lli l,lli r,lli s,lli e,lli node_num, lli *seg_tree, lli *lazy)
{
 if(lazy[node_num]>0)
    lazy_update(s,e,node_num,seg_tree, lazy);
 if(s>r || e<l) 
   return 0;
 else if(s>=l && e<=r) 
   return seg_tree[node_num];
 else 
 {
   lli m = (s+e)/2;
   return (query(l,r,s,m,node_num*2, seg_tree, lazy) + query(l,r,m+1,e,node_num*2+1, seg_tree, lazy))%mod;
 }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli T, n, m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        lli type[m+1], start[m+1], end[m+1];
        for(lli i=1; i<=m; i++)
        {
            cin>>type[i]>>start[i]>>end[i];
        }
        lli seg_tree[4*m]={0}, lazy[4*m]={0};
        for(lli i=m; i>=1; i--)
        {
           lli upd=query( i, i, 1, m, 1, seg_tree, lazy);
           //cout<<"for "<<i<<" upd "<<upd<<endl;
            if(type[i]==2)
            {
               	range_update(start[i], end[i], (upd+1), 1, m, 1, seg_tree, lazy); 
            }
        }
        lli lazy_arr[4*n]={0}, seg_tree2[4*n]={0};
        for(lli i=1; i<=m; i++)
        {
            if(type[i]==1)
            {
                lli upd=query( i, i, 1, m, 1, seg_tree, lazy);
           //cout<<"for "<<i<<" upd "<<upd<<endl;
               	range_update(start[i], end[i], (upd+1), 1, n, 1, seg_tree2, lazy_arr); 
            }
        }
        for(lli i=1; i<=n; i++)
        {
            lli upd=query( i, i, 1, n, 1, seg_tree2, lazy_arr);
            cout<<upd%mod<<" ";
        }
        cout<<endl;
    }
    return 0;
}
