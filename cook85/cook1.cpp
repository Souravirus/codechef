#include<bits/stdc++.h>
#define mp make_pair
typedef long long int lli;
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		float N, v1, v2;
		cin>>N>>v1>>v2;
		float liftans, stairans;
		liftans=(2*N)/v2;
		stairans=(sqrt(2)*N)/v1;
		if(liftans<stairans)
			cout<<"Elevator"<<endl;
		else 
			cout<<"Stairs"<<endl;
	}
	return 0;
}
