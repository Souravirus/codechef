#include<bits/stdc++.h>
#define mod 1000000007
#define mp make_pair
typedef long long int lli;
using namespace std;
lli calc(lli i)
{
    lli sum=0;
    while(i!=0)
    {
        sum+=i&1;
        i>>=1;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli T;
    cin>>T;
    vector<pair<lli, lli> >vect;
    lli arr[T]; 
    lli num;
    for(lli i=0; i<T; i++)
    {
        cin>>num;
        vect.push_back(mp(num, i)); 
    }
    sort(vect.begin(), vect.end());
    lli prevnum=1;
    lli sum=0;
    for(lli i=0; i<vect.size(); i++)
    {
        while(prevnum<=vect[i].first)
        {
            sum=sum+(prevnum*calc(prevnum)%mod)%mod; 
            prevnum++;
        }
        arr[vect[i].second]=sum%mod;
    }
    for(lli i=0; i<T; i++)
        cout<<arr[i]<<endl;
}
