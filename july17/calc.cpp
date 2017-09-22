#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
int main(){
	int T;
	ulli qt;
	double N, B, ans,  q, diff, m;
	double tk,rem, ans1, ans2, diff1, diff2, add2;
	cin>>T;
	while(T--)
	{
		scanf("%lf%lf",&N, &B);
		tk=N/2;
		diff=N-tk;
		q=diff/B;
		qt=diff/B;	
		 m=B*qt;
		if(m==diff)
		{
			ans=q*tk;
			cout<<ans<<endl;
		}
		else{
			ans1=0;
			ans2=0;
			diff1=B*qt;
			ans1=(qt)*(N-diff1);
			add2=(B*(qt+1));
			if(add2<=N){
				ans2=(qt+1)*(N-add2);
			}
			//cout<<"ans1:"<<ans1<<endl<<"ans2:"<<ans2<<endl;
			cout<<max(ans1, ans2)<<endl;
		}
	}
	return 0;
}
