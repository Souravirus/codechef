#include<bits/stdc++.h>
#define mp make_pair
#define mf myvect[i].first
#define msf myvect[i].second.first
#define mss myvect[i].second.second
using namespace std;
int main()
{
    int T;
    int N, Q;
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        int arr[N+1];
        for(int i=0; i<N; i++)
            arr[i]=-1;
        int tempchk[N+1];
        for(int i=1; i<N; i++)
            tempchk[i]=1;
        vector<pair<int, pair<int, int> > > myvect;
        int m, n, val;
        arr[1]=0;
        int flag=0;
        vector<pair<int, vector<int> > > graph;
        for(int i=1; i<=N; i++)
        {
            vector<int> temp;
            temp.push_back(0);
            graph.push_back(mp(i, temp));
        }
        for(int i=1; i<=Q; i++)
        {
            cin>>m>>n>>val;
            if(m==n)
            {
                if(val!=0)
                    flag=1;
            } 
            else if(m==1)
            {
                arr[n]=val;
                tempchk[n]=0; 
            }
            else if(n==1)
            {
                arr[m]=val;
                tempchk[m]=0;
            }
            else
            {
                myvect.push_back(mp(m,mp(n, val)));     
            }
        }
        sort(myvect.begin(), myvect.end());
        for(int i=0; i<myvect.size(); i++)
        {
           if(tempchk[mf]==1 && tempchk[msf]==1)
           {
                if(arr[mf]!=1 && arr[msf]!=-1)
                {
                    if(arr[mf]-arr[msf]!=arr[mss])
                    {
                        flag=1;
                        break;
                    }
                }
                if(mss==1 && arr[mf]==-1 && arr[msf]==-1)
                {
                    arr[mf]=0;
                    arr[msf]=1;
                    graph[mf].push_back(msf);
                }
                else if(mss==0 && arr[mf]==-1 && arr[msf]==-1)
                {
                    arr[mf]=0;
                    arr[msf]=0;
                    graph[mf].push_back(msf);
                }
                else if(mss==1 )
                {
                    if(arr[mf]==1)
                    {
                        if(arr[msf]!=0)
                        {
                            arr[msf]=0;
                            for
                        }
                    }
                    else if(arr[mf]==0)
                    {
                        if(arr[msf]!=1)
                            arr[msf]=1;
                        //Also change the value of all connections
                    }
                    else if(arr[msf]==0)
                    {
                        if(arr[mf]!=1)
                        {
                            arr[msf]=1;
                        //Also change the value of all connections
                        }   
                    }
                    else if(arr[msf]==1)
                    {
                        if(arr[mf]!=0)
                        {
                            arr[mf]=0;
                            //Also change the value of all connections
                        }
                    }
                }
                else if(mss==0)

           }
        }
    }
    return 0;
}
