#include<bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
using namespace std;
ulli treecomp(ulli start, ulli n, ulli stage, ulli currpos, ulli num)
{
	lli div=pow(2, stage);
	//cout<<"currpos"<<currpos<<endl;
	if(stage-1==num)
	{
		return currpos;
	}
	else if((n%div)-start==0)
	{
		return treecomp(start, n, stage+1, currpos, num);
	}
	else
	{
		lli divs=(ulli)pow(2, stage);
		return treecomp(start+pow(2, stage-1), n, stage+1, currpos+pow(2,num)/divs, num);
	}
}
int main()
{
	int T;
	ulli num;
	ulli pos;
	cin>>T;
	while(T--)
	{
		cin>>num>>pos;
		ulli ans=treecomp(0, pos,1, 0 , num);
		cout<<ans<<endl;
	}
	return 0;
}
