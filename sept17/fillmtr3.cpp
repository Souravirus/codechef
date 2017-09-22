#include<bits/stdc++.h>
#define mp make_pair
#define mf myvect[i].first
#define msf myvect[i].second.first
#define mss myvect[i].second.second
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int N, Q;
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        int arr[N+1];
        for(int i=1; i<=N; i++)
            arr[i]=-1;
        int arrflag[N+1];
        for(int i=1; i<=N; i++)
            arrflag[i]=-1;
        vector<pair<int, pair<int, int> > > myvect;
        vector<set<int> > vects;
        set<int>:: iterator its;
        int m, n, val;
        //arr[1]=0;
        int flag=0;
        for(int i=1; i<=Q; i++)
        {
            cin>>m>>n>>val;
            if(m==n)
            {
                if(val!=0)
                    flag=1;
            } 
            else
            {
                myvect.push_back(mp(m,mp(n, val)));     
            } 
        }
        if(flag==0)
        {
            //cout<<"flag 0"<<endl;
		    for(int i=0; i<myvect.size(); i++)
		    {
		        int pos=-1, pos2=-1;
		        pos=arrflag[mf];
		        pos2=arrflag[msf];
		        //cout<<"vects size"<<vects.size()<<endl;
		        if(pos==pos2 && pos!=-1)
		        {
		            //cout<<"same"<<endl;
		            if(mss!=abs(arr[mf]-arr[msf]))
		            {
		                flag=1;
		                break;
		            }
		        }
		        else if(pos!=-1 && pos2!=-1)
		        {
		           //cout<<"count>2"<<endl;

		            if(vects[pos2].size()> vects[pos].size())
		            {
                        //checked here
		                for(its=vects[pos].begin(); its!=vects[pos].end(); its++)
		                {
                            //cout<<"*its"<<*its<<endl;
		                    if(mss!=abs(arr[mf]-arr[msf]))
		                    {
		                        if(arr[*its]==0)
		                            arr[*its]=1;
		                        else
		                            arr[*its]=0;
		                    }
		                    vects[pos2].insert(*its);
		                    arrflag[*its]=pos2;
		                }
		                vects[pos].clear();
		            }
		            else
		            {
		                for(its=vects[pos2].begin(); its!=vects[pos2].end(); its++)
		                {
                            //cout<<"*its"<<*its<<endl;
		                    if(mss!=abs(arr[mf]-arr[msf]))
		                    {
		                        if(arr[*its]==0)
		                            arr[*its]=1;
		                        else
		                            arr[*its]=0;
		                    }
		                    vects[pos].insert(*its);
		                    arrflag[*its]=pos;
		                }
		                vects[pos2].clear();
		            }
		        }
		        else
		        {
		            if(pos!=-1 && pos2==-1)
		            {
		             //cout<<"found a single unset number"<<endl;
		                vects[pos].insert(msf);  
		                arr[msf]=(arr[mf]+mss)%2;
		                arrflag[msf]=pos;
		            }
		            else if(pos2!=-1 && pos==-1)
		            {
		             //cout<<"found a second single unset number"<<endl;
		                vects[pos2].insert(mf);  
		                arr[mf]=(arr[msf]+mss)%2;
		                arrflag[mf]=pos2;
		            }
		            else if(pos==-1 && pos2==-1)
		            {
		              //cout<<"found 2 different numbers"<<endl;
		                set<int> s;
		                s.insert(mf);
		                s.insert(msf);
		                vects.push_back(s);
		                arrflag[mf]=vects.size()-1;
		                arrflag[msf]=vects.size()-1;
		                arr[mf]=0;
		                arr[msf]=0+mss;
		                //cout<<"pushed new set"<<endl;
		                //cout<<"ind"<<ind<<endl;
		                //cout<<"indo"<<indo<<endl;
		                s.clear();
		            }
		        }
		        /*cout<<"main arr elements at last"<<endl;
		        for(int i=1; i<=N; i++)
		            cout<<arr[i]<<endl;
               */ 
        	}
        }
        if(flag==1)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
     }
     return 0;
}
