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
        int a[256]={0};
        string s;
        cin>>s;
        int flag=0;
        for(int i=0; i<s.length(); i++)
        {
            if(a[s[i]]==0)
            {

                a[s[i]]++;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
