#include<bits/stdc++.h>
#define ulli long long int
using namespace std;
ulli binsearch(ulli s, ulli e, ulli N, ulli B){
	ulli mid=(s+e)/2;
	ulli val=(N*mid)-(mid*mid*B);
	ulli  diff=N-(2*mid*B);
	if(s>=e)
		return val;
	else if(diff<0)
		return max(val, binsearch(s, mid, N, B));
	else if(diff>0)
		return max(val, binsearch(mid+1, e, N, B));
	else
		return val;
}
int main(){
	int T;
	ulli N, B, div;
	ulli ans;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&N, &B);
		 div=N/B;
		//cout<<"div"<<div<<endl;
		ans=binsearch(0, div, N, B);
		cout<<ans<<endl;
	}
	return 0;
}
