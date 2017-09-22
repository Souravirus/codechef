#include<bits/stdc++.h>
#define mp make_pair
typedef long long int lli;
using namespace std;
lli down[4][100100], rightele[4][100100];
lli weight[4][100100];
lli check[4][100100];
lli dist[4][100100];
lli parentx[4][100100];
lli parenty[4][100100];

class Node{
	public:
		ulli dist;
		
}
void dijikstra(lli x1, int y1, int x2, int y2, int upd,  int M, int N)
{
    lli x=x1, y=y1;
    //cout<<"inside djikstra"<<endl;
    vector<pair<lli, int> > vect;
    vect.push_back(mp(x, y)); 
    check[x][y]=1;
    while(x!=x2 || y!=y2)
    {
       lli min=LONG_MAX;
     //  cout<<"checking inf"<<endl;
       lli xt, yt, xmin, ymin, xp, yp;
       for(lli i=0; i<vect.size(); i++) 
       {
           xt=vect[i].first;
           yt=vect[i].second;
           lli distance=dist[xt][yt];
      //     cout<<"parent distance at "<<xt<<" "<<yt<<": "<<dist[xt][yt]<<endl<<endl;
           if(xt!=0)
           {
               if(distance+down[xt-1][yt]<min && check[xt-1][yt]==0)
               {
                  xmin=xt-1;
                  ymin=yt;
                  min=distance+down[xt-1][yt];
           //       cout<<"down[xt-1][yt]"<<down[xt-1][yt]<<endl;
                 // cout<<min<<endl<<endl;
                  xp=xt; yp=yt;
               } 
           }
           if(xt!=M-1)
           {
               if(distance+down[xt][yt]<min && check[xt+1][yt]==0)
               {
                   xmin=xt+1;
                   ymin=yt;
                   min=distance+down[xt][yt];
            //       cout<<"down[xt+1][yt]"<<down[xt][yt]<<endl;
                  //  cout<<min<<endl<<endl;
                   xp=xt; yp=yt;
               }
           }
           if(yt!=0)
           {
               if(distance+rightele[xt][yt-1]<min && check[xt][yt-1]==0)
               {
                  xmin=xt;
                  ymin=yt-1;
                  min=distance+rightele[xt][yt-1];
             //     cout<<"right[xt][yt-1]"<<rightele[xt][yt-1]<<endl;
              //    cout<<min<<endl<<endl;
                  xp=xt; yp=yt;
               } 
           }
           if(yt!=N-1)
           {
               if(distance+rightele[xt][yt]<min && check[xt][yt+1]==0)
               {
                  xmin=xt;
                  ymin=yt+1;
                  min=distance+rightele[xt][yt];
               //   cout<<"right[xt][yt]"<<rightele[xt][yt]<<endl;
                //  cout<<min<<endl<<endl;
                  xp=xt; yp=yt;
               } 
           }
       }
       //cout<<"xmin"<<xmin+1<<" "<<"ymin"<<ymin+1<<endl;
       parentx[xmin][ymin]=xp;
       parenty[xmin][ymin]=yp;
       x=xmin;
       y=ymin;
       check[xmin][ymin]=1;
       dist[xmin][ymin]=min;
       //cout<<"keeping dist:"<<min<<endl;
       vect.push_back(mp(xmin, ymin));
    }
    lli xt=x2, yt=y2;
    weight[x2][y2]+=upd;
    while(xt!=x1 || yt!=y1)
    {
        //cout<<"inside 2nd loop"<<endl;
        weight[parentx[xt][yt]][parenty[xt][yt]]+=upd; 
        lli xa=xt, ya=yt;
        xt=parentx[xa][ya];
        yt=parenty[xa][ya];
        //cout<<"xt at last"<<xt+1<<" yt at last"<<yt+1<<endl;
    }
}

int main()
{
    lli M, N, Q;
    cin>>M>>N>>Q;
    for(lli i=0; i< M-1; i++)
    {
        for(lli j=0; j<N; j++)
            cin>>down[i][j];
    }
    for(lli i=0; i<M; i++)
    {
        for(lli j=0; j<N-1; j++)
        {
            cin>>rightele[i][j];
        }
    }
    lli type;
    for(lli i=0; i<M; i++)
        for(lli j=0; j<N; j++)
            weight[i][j]=0;
    for(lli i=0; i<Q; i++)
    {
        cin>>type;
        lli x1, y1, x2, y2, upd;
        if(type==1)
        {
            cin>>x1>>y1>>x2>>y2>>upd; 
            for(lli i=0; i<M; i++)
            {
                for(lli j=0; j<N; j++)
                {
                    check[i][j]=0;
                    dist[i][j]=0;
                    parentx[i][j]=0;
                    parenty[i][j]=0;
                }
            }
          //  cout<<"calling djikstra"<<endl;
            dijikstra(x1-1, y1-1, x2-1, y2-1, upd, M, N); 
        }
        if(type==2)
        {
            cin>>x1>>y1;
            cout<<weight[x1-1][y1-1]<<endl;
        }
    }
    return 0;
}
