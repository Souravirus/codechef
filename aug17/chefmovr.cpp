#include<bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ulli t;
	ulli n, d; 
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		ulli a[n];
		vector<int> nums;
		int flag=0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		ulli ans=0;
		ulli tsum=0;
		ulli flagc=0;
			
		for(int i=0; i<d; i++)
		{
			ulli sum=0;
			ulli cnt=0;
			ulli count=0+i;
			while(1)
			{
				if(count>=n)
					break;
				else{
					sum+=a[count];
				}
				count+=d;
				cnt++;
			}
		//	cout<<"sum"<<sum<<endl;
			if(sum%cnt==0)
				sum=sum/cnt;
			else
			{
				cout<<"-1"<<endl;
				flagc=1;
				break;
			}
			if(ans==0)
				ans=sum;
			else if(ans!=sum)
			{
				cout<<"-1"<<endl;
				flagc=1;
				break;
			}
			vector<pair<ulli, ulli> >shortage;
			vector<pair<ulli, ulli> >excess;
			pair<ulli, ulli>foo;
			count=0+i;	
			while(1)
			{
		//		cout<<"hello"<<endl;
				if(count>=n)
					break;
				else
				{	
					if(a[count]<ans)
					{
						ulli sh=ans-a[count];
		//				cout<<"in sh"<<sh<<endl;
						while(!excess.empty() && sh>0)
						{
							ulli posdiff=(abs(count-excess[0].second))/d;
		//					cout<<"in sh while loop posdiff:"<<posdiff<<endl;
							if(excess[0].first<=sh)
							{
								tsum+=(excess[0].first)*posdiff;
		//						cout<<"tsum1"<<tsum<<endl;
								sh=sh-excess[0].first;
								excess.erase(excess.begin());
							}
							else
							{
								tsum+=(sh)*posdiff;
		//						cout<<"tsum2"<<tsum<<endl;
								excess[0].first=excess[0].first-sh;
								sh=0;
							}
						}
						if(sh>0)
						{
							foo=make_pair(sh, count);	
							shortage.push_back(foo);
		//					cout<<"pushed due to sh> 0"<<"sh:"<<sh<<"count"<<count<<endl;
						}
					}
					else if(a[count]>ans)
					{
						ulli ex=a[count]-ans;		
		//				cout<<"Entered in ex"<<ex<<endl;
						while(!shortage.empty() && ex>0)
						{
							ulli posdiff=(abs(count-shortage[0].second))/d;
		//					cout<<"inside ex while loop posdiff:"<<posdiff<<endl;
							if(shortage[0].first<=ex)
							{
								tsum+=(shortage[0].first)*posdiff;
		//						cout<<"tsum3"<<tsum<<endl;
								ex=ex-shortage[0].first;
								shortage.erase(shortage.begin());	
							}
							else
							{
								tsum+=(ex)*posdiff;
		//						cout<<"tsum4"<<tsum<<endl;
								shortage[0].first=shortage[0].first-ex;
								ex=0;
							}
						}
						if(ex>0)
						{
							foo=make_pair(ex, count);
		//					cout<<"pushed in vector due to excess"<<"ex"<<ex<<"count"<<count<<endl;
							excess.push_back(foo);
						}

					}
				}
				count+=d;
			}
		}
		if(flagc==0)
		{
			cout<<tsum<<endl;
		}
	}
	return 0;
}
