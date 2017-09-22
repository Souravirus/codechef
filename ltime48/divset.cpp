#include<bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
int flag=0;
int binsearch(int s, int e, int dou , vector<ulli> a)
{
	int  mid=(s+e)/2;
	if(dou>a[e-1] && flag==0)
		return -1;
	else if(dou>=a[e-1])
		return	e; 
	else if(dou<=s)
		return s;
	if(a[mid]==dou)
	{
		flag=1;
		return mid;	
	}
	else if(a[mid]>dou)
	{
		flag=1;
		return binsearch(s, mid, dou, a);
	}
	else
	{
		flag=1;
		return binsearch(mid+1, e, dou, a); 
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	ulli n, k, c;
	cin>>t;
	while(t--){
		cin>>n>>k>>c;
		vector<ulli>a;
		for(int i=0; i<n; i++)
		{
			ulli num;
			cin>>num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());	
		ulli count=0;
		ulli index=0;
		ulli dou;
		while(flag!=1)
		{
			dou=a[index]*2;
			flag=0;
			int pos=binsearch(index+1, a.size(),dou,  a);
			if(pos==-1)
			{
				break;	
			}
			cout<<a[pos]<<endl;
			index=pos;
			flag=1;
		}
	}
	return 0;
}
