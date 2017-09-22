#include<bits/stdc++.h>
typedef unsigned long long ulli;
using namespace std;
int main()
{
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        ulli arr[N];
        ulli barr[N];
        for(int i=0; i<N; i++)
        {
            cin>>arr[i];
            cin>>barr[i];
        }
        ulli max=0;
        ulli num, count=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                num=arr[i]*barr[j];
                if(num>max)
                {
                    max=num;
                    count=0;
                }
                if(num==max)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
