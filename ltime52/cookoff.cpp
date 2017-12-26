#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    int t;
    cin >> t;
    while(t--){
        cin >> T;
        int a[6];
        for(int i=0; i< 6; i++)
            a[i]=0;
        string s;
        int count = 0;
        while(T--){
            cin >> s;
            if( s=="cakewalk" && a[0] ==0)
            {
                a[0]=1;
                count ++;
            }
            else if ( s== "easy" && a[1]==0)
            {
                a[1]=1;
                count ++;
            }
            else if (s=="simple" && a[2]==0)
            {
                a[2]=1;
                count ++;
            }    
            else if((s=="easy-medium" || s=="medium") && a[3]==0)
            {
                a[3]=1;
                count ++;
            }
            else if ((s=="medium-hard" || s=="hard" )&& a[4]==0)
            {
                a[4]=1;
                count++;
            }
        }
        if(count==5)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
