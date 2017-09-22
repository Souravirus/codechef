#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, num;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int arr[26];
        for(int j=0; j<26; j++)
            arr[j]=0;
        int flag[4];
        for(int i=0; i<4; i++)
            flag[i]=0;
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            if(count==4)
                break;
            if(s[i]>='6' && s[i]<='9')
            {
                //cout<<s[i]<<endl
                if(flag[s[i]-48-6]==0)
                {
                    flag[s[i]-48-6]=1;
                    count++;
                    for(int j=0; j<s.length(); j++)
                    {
                        if(j!=i)
                        {
                            if(s[i]=='6')
                            {
                                if(s[j]>='5')
                                {
                                    num=(s[i]-48)*10+s[j]-48;                   
                                    arr[num-65]=1;
                                }
                            }
                            else if(s[i]=='9')
                            {
                                if(s[j]=='0')
                                {
                                    num=(s[i]-48)*10+s[j]-48;                   
                                        arr[num-65]=1;
                                }
                            }
                            else
                            {
                                num=(s[i]-48)*10+s[j]-48;                   
                                    arr[num-65]=1;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<26; i++)
        {
            if(arr[i]==1)
            {
                char c=i+65;
                cout<<c;
            }
        }
        cout<<endl;
    }
    return 0;
}
