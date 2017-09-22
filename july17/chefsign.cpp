#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, count, max, prev;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		count=1;
		max=1;
		prev=0;
		for(int i=0; i<s.length(); i++)
		{
			if(i!=0)
			{
				if(s[i]!='=')
				{
					if(s[i]==s[prev])
					{
						count++;
						if(count>max)
							max=count;
						prev=i;
					}
					else
					{
						count=2;
						if(count>max)
							max=count;
						prev=i;
					}
				}
			}
			else{
				if(s[i]!='=')
				{
					count++;
					if(count>max)
						max=count;
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
