#include<bits/stdc++.h>
#define ui long long int
#define mp pair<int,int> 
using namespace std;
 
ui arr[100002];
ui rem[100002];
ui seg[400002];
 
int roll[17][100002];
int nn;
 
void segupdate(int p,int v,int l=1,int r=nn,int i=1){
    if(l==r){
        seg[i]+=v;
        return;
    }
    int mid = (l+r)/2;
    if(p<=mid)
        segupdate(p,v,l,mid,2*i);
    else
        segupdate(p,v,mid+1,r,2*i+1);
    seg[i]=seg[2*i]+seg[2*i+1];
}
 
ui segquery(int down,int up,int l=1,int r=nn,int i=1){
    if(l==down && r==up){
//        cout<<"returning at "<<i<<" "<<seg[i]<<endl;
        return seg[i];
    }
    int mid=(l+r)/2;
    if(up<=mid)
        return segquery(down,up,l,mid,2*i);
    else 
        return seg[2*i] + segquery(mid+1,up,mid+1,r,2*i+1);
}
 
void rollloop(int l=1,int r=nn,int m=17){
    if(m>17)m=17;
    for(int i=1;i<m;i++)
        for(int j=l;j<=r;j++)//check start of j
            roll[i][j]=roll[i-1][roll[i-1][j]];
}
 
void update(int p){
    stack<pair<int,ui> > stk;
    int l=p>100?p-100:1;
    int r=p+100<=nn?p+100:nn;
    ui sum=0;
    sum=segquery(1,l);
    stk.push(mp(l,sum));
    for(int i=l+1;i<=r;i++){
        sum+=rem[i];
        if(stk.empty() && i>p){
            break;
        }
        else{
            while(!stk.empty() && (arr[stk.top().first]+stk.top().second)<(arr[i]+sum) ){
                if(i-stk.top().first>100)
                    roll[0][stk.top().first]=stk.top().first;
                else
                    roll[0][stk.top().first]=i;
                stk.pop();
            }
            if(i<=p) stk.push(mp(i,sum));
        }
    }
    while(!stk.empty()){
        roll[0][stk.top().first]=stk.top().first;
        stk.pop();
    }
}
 
void create_rollowup(){
    int n=nn;
    stack<int> stk;
    for(int i=1;i<=n;i++){
        if(stk.empty())
            stk.push(i);
        else{
            while(!stk.empty() && arr[stk.top()]<arr[i]){
                if(i-stk.top()>100)
                    roll[0][stk.top()]=stk.top();
                else
                    roll[0][stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    while(!stk.empty()){
        roll[0][stk.top()]=stk.top();
        stk.pop();
    }
}
 
int jump(int p,int n){
    int i=0;
    while(n){
        if(p==roll[i][p]) return p;
        if(n&1)
            p=roll[i][p];
        n=n>>1;
        i++;
    }
    return p;
}
 
int jump2(int p,int n){
    for(int i=1;i<=n;i++){
        if(roll[0][p]==p) return p;
        p=roll[0][p];
    }
    return p;
}
 
int main(){
    int n,q,i,k,l,r,type,ltype=2,left,right,up;
    ui x;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    nn=n;
    create_rollowup();
 
    queue<pair<int,int> > list;
    left=n;right=0,up=0;
    while(q--){
        scanf("%d",&type);
        if(type==1){
            scanf("%d %d",&i,&k);
            list.push(pair<int,int>(i,k));
            ltype=1;
        }
        else{
            if(ltype==1){//list was created in type1
                if(list.size()>22){
                    rollloop(1,nn);
                    while(!list.empty()){
                        printf("%d\n",jump(list.front().first,list.front().second));
                        list.pop();
                    }
                }
                else{
                    while(!list.empty()){
                        printf("%d\n",jump2(list.front().first,list.front().second));
                        list.pop();
                    }
                }
                left=n;right=0;up=0;
            }
            scanf("%d %d %lld",&l,&r,&x);
            rem[l]+=x;
            rem[r+1]-=x;
            segupdate(l,x);
            segupdate(r+1,-1*x);
            update(l);
            update(r);
            ltype=2;
        }
        if(q%100==0){
            int sum=0;
            for(int i=1;i<=nn;i++){
                sum+=rem[i];
                arr[i]+=sum;
            }
            memset(rem,0,sizeof(rem));
            memset(seg,0,sizeof(seg));
        }
    }
    if(ltype==1){//list was created in type1
        if(list.size()>22){
            rollloop(1,nn);
            while(!list.empty()){
                printf("%d\n",jump(list.front().first,list.front().second));
                list.pop();
            }
        }
        else{
            while(!list.empty()){
                printf("%d\n",jump2(list.front().first,list.front().second));
                list.pop();
            }
        }
    }
}
