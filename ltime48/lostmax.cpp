#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin.ignore();
		int count=0;
		int a[51];
		while(cin.peek()!='\n')
		{
			cin>>a[count];
			count++;
		}
		sort(a, a+count, greater<int>());
		if(a[0]==count-1)
		{
			cout<<a[1]<<endl;
		}
		else
			cout<<a[0]<<endl;
	}
	return 0;
}
