nclude<bits/stdc++.h>

#define F0(i,t) for(int i=0; i<t; i++)
#define F1(i,t) for(int i=1; i<=t; i++)
#define Si(x) scanf("%d",&x)
#define Si2(x,y) scanf("%d %d",&x,&y)
#define Sl(x) scanf("%lld",&x)
#define Sl2(x,y) scanf("%lld %lld",&x,&y)
#define dout if(debugg)cout<<" "

   /* * * * * * * * * * * * * * * * * * * * * * * *
    *                                             *
    *            _/_/_/            _/             *
    *         _/        _/  _/_/  _/_/_/          *
    *          _/_/    _/_/      _/    _/         *
    *             _/  _/        _/    _/          *
    *      _/_/_/    _/        _/_/_/             * 
    *                                             *
    * * * * * * * * * * * * * * * * * * * * * * * */

using namespace std;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;

int debugg = 0;

set<int> vrtx;
vector<int> vrtxx;

vector<set<int> > PowerSet(){
    unsigned int pow_set_size = pow(2, vrtx.size());
    int counter;
    vector<set<int> > ret(pow_set_size);
 
    for(counter = 0; counter < pow_set_size; counter++){
      for(int j = 0; j < vrtx.size(); j++){
          if(counter & (1<<j))
            ret[counter].insert(vrtxx[j]);
       }
    }
    dout<<ret.size()<<endl;
    return ret;
}
 
int getans(int k){
    int count;
    vector<set<int> > powset = PowerSet();
    int sum=0;
    for(int i=0;i<powset.size();i++){//traverse all powerset
        count=0;
        dout<<i<<" : ";
        for(auto j : powset[i]){//all elements of a powerset
            dout<<j;
            count = count|j;
        }
        vrtx.insert(count);
        dout<<endl;
    }//travere all powerset
    int j=0,ans=0;
    while(j<k){
        if(vrtx.find(pow(2,j))==vrtx.end())
            ans++;
        j++;
    }
    return ans;
}

int main(){
	int t=1;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vrtx.clear();
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            vrtx.insert(temp);
            vrtxx.push_back(temp);
        }
        cout<<getans(k)<<endl;
	}
}
