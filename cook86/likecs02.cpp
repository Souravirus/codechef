#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int arr[N];
        arr[N/2]=N;
        int count=N-1;
        for(int i=N/2-1; i>=0; i--)
        {
            arr[i]=count;
            count--;
        }
        count=N+1;
        for(int i=N/2+1; i<N; i++)
        {
            arr[i]=count;
            count++;
        }
        for(int i=0; i<N; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
