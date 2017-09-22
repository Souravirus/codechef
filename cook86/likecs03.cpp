#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N, K;
        cin>>N>>K;
        int arr[N+1];
        for(int i=0; i<N; i++)
        {
            cin>>arr[i];
        }
        arr[N]=0;
        N++;
        sort(arr, arr+N);
        map<int, int> div;
        int k=0;
        int arr[21]={0};
        int count=1;
        for(int i=0; i<N; i++)
        {
            if(arr[i]>pow(2, k))
            {
                int lg=log2(arr[i]);
                lg++;
                k=lg;
                arr[k]=count;
            }
            count++;
        }        
        int arry[20]={0};
        int arrchk[20]={0};
        for(int i=0; i<N; i++)
        {
                   
        }
    }
    return 0;
}
