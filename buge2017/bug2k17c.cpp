#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    string s;
    int N;
    while(T--)
    { 
        cin>>N;
        cin>>s;
        float num;
        float prev;
        cin>>prev;
        for(int i=0; i<N; i++)
        {
            cin>>num;
            if(s[i]=='+')
                prev=prev+num;
            if(s[i]=='-')
                prev=prev-num;
            if(s[i]=='*')
                prev=prev*num;
            if(s[i]=='/')
                prev=prev/num;
        }
        cout<<prev<<endl;
    }
}
