#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
using namespace std;
int main()
{
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        vector<pair<lli, int> >vect;
        lli num=0;
        int check[N]={0};
        for(int i=0; i<N; i++)
        {
            cin>>num;
            vect.push_back(mp(num, i));
        }
        sort(vect.begin(), vect.end());
        lli sum=0;
        for(int i=N-1; i>=0; i--)
        {
            //cout<<"num"<<vect[i].first<<endl;
            //cout<<"second"<<vect[i].second<<endl;
            if(N!=1)
            {
		        if(vect[i].second==0)
		        {
		            //cout<<"in outer first"<<endl;
		            if(check[vect[i].second+1]==0)
		            {
		                //cout<<"in first one"<<endl;
		                sum+=vect[i].first;
		                check[vect[i].second]=1;
		            }
		        }
		        else if(vect[i].second==N-1)
		        {
		            ////cout<<"in outer 2nd one"<<endl;
		            if(check[vect[i].second-1]==0)
		            {
		                //cout<<"in 2nd one"<<endl;
		                sum+=vect[i].first;
		                check[vect[i].second]=1;
		            }

		        }
		        else{
		            //cout<<"in outer third"<<endl;
		            if(check[vect[i].second-1]==0 && check[vect[i].second+1]==0)
		            {   
		                sum+=vect[i].first;
		                check[vect[i].second]=1;
		            }
		        }
            }
        }
        if(N==1)
            cout<<vect[0].first<<endl;
        else
            cout<<sum<<endl;
    }
}
