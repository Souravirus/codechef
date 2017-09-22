#include <bits/stdc++.h>
using namespace std;

int value(string str)
{
    int len = str.length();
    int count = 0;
    int countt=1;
       int count1 = 1;
       char curr=str[0];
    for (int i=0; i<len-1; i++)
    {
        if(str[i]=='>')
                curr = '>';
            else if(str[i]=='<')
                curr = '<';
            if(str[i]=='=' && str[i+1]=='=')
                    countt++;
            else if(str[i+1]=='<' && curr=='<')
            {
                     //cout<<"bawa";

                    count1=count1+1;                 
            }
            else if(str[i+1]=='>' && curr=='>')
            {
                    //cout<<"q";
                    //cout<<count1<<" ";
                    count1++;
                    //cout<<count1<<endl;
            } 
            else if((curr=='>' && str[i+1]=='<') || (curr=='<' && str[i+1]=='>'))
            {
                //cout<<"ggg";
                     if(count1 > count)
                    {
                        count = count1;
                    }
                    count1=1;
            }
            else
                continue;
    }
    //cout<<count1;
        if(countt==len)
            return 0;
       	else if(count1>count)
       		return count1;
        return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {string str;
        cin>>str;
    if(str ==">")
        cout<<2<<endl;
    else if (str=="<")
      cout<<2<<endl;
    else
        cout << value(str)+1<<endl;
    }return 0;
}
