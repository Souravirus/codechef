#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int min=INT_MAX;
        int num, pos=0;
        for(int i=0; i<N; i++)
        {
            cin>>num;
            if(num<min)
            {
                //cout<<"num"<<num<<endl;
                pos=i+1;
                min=num;
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}
