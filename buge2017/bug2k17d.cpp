#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main()
{
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        lli ansev=0, num, ansod=0;
        for(int i=1; i<=N; i++)
        {
            cin>>num;
            if(i%2==1)
                ansod+=num;
            else
                ansev+=num;
        }
        if(N%2==0)
        {
            if(ansod>ansev)
                cout<<ansod<<endl;
            else
                cout<<ansev<<endl;
        }
        else
            cout<<ansod<<endl;
    }
    return 0;
}
