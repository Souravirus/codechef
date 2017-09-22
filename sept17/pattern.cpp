#include<bits/stdc++.h>
#define dout if(debugg)cout<<" -> "
using namespace std;

int debugg=0;
int arr[10000][10000];

/*
 * return 16 on 15
 * return 16 on 16
 * return 32 on 17
 */
int up2pow(int n){
    int count1=0,count_d=0;
    while(n){
        if(n&1)count1++;
        n = n/2;
        count_d++;
    }
    if(count1==1)//in series 2 4 8 16 ... 
        count_d--;          
    return pow(2,count_d);
}
/*
 * return 8 on 15
 * return 8 on 16
 * return 16 on 17
 */
int low2pow(int n){
    int count1=0,count_d=0;
    while(n){
        if(n&1)count1++;
        n = n/2;
        count_d++;
    }
    count_d--;
    if(count1==1)count_d--;
    return pow(2,count_d);
}
bool in_series(int n){//return true if number is in 2 4 8 16 32 ....
    if(n == (n&(-n)))return true;
    else return false;
}
bool fun(int d,int p){
    dout<<d<<" "<<p<<endl;
    if(d==1 or p==1) return true;
    if(d==p)return false;//it is true onlu for 1 1 else false always
    
    //case one is in series
    if(in_series(p)){
        if(d%p==1)return true;
        else return false; 
    }
    if(in_series(d)){
        if(p%d==1)return true;
        else return false;
    }

    if(d+p > up2pow(max(d,p))+1) return false;//lie in triangle of death
    if(d+p == up2pow(max(d,p))+1)return true;//lie on boundary of triangle of life

    if(d<p)return fun(d,p-low2pow(p));
    else if(p<d) return fun(d-low2pow(d),p);
}
int funint(int d,int p){
    if(fun(d,p))return 1;
    return 0;
}

int main(){
    int d,p,flag;
    cin>>d>>p;        
    memset(arr,0,sizeof arr);

    cout<<endl;
    for(int i=1;i<=p;i++){
        arr[1][i]=1;//at day 1 every depth elem is included
    }

    for(int i=2;i<=d;i++){
        flag=0;
        for(int j=1;j<=p;j++){
            if(arr[i-1][j]==1)flag ^= 1;
            arr[i][j]=flag;
        }
    }
    
    for(int i=d;i>0;i--){
        cout<<i<<"\t";
        for(int j=1;j<=p;j++){
            if(funint(i,j)!=arr[i][j])cout<<"\n\n\n\n\n\n\n"<<i<<" "<<j<<" wrong \n";
            if(fun(i,j))cout<<"1 ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    
    cout<<endl<<"\t";
    for(int i=1;i<=p;i++)
        cout<<i/10<<" ";
    
    cout<<endl<<"\t";
    for(int i=1;i<=p;i++)
        cout<<i%10<<" ";
    cout<<endl<<endl;
    
    int a,b;
    debugg=1;
    while(true){
        cin>>a>>b;
        cout<<funint(a,b)<<endl;
    }
}

