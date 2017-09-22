#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string s;
	string::iterator its;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		getline(cin,s);
		vector<char>vfirst;
		vector<char>vsecond;
		vector<char>vthird;
		vector<char>:: iterator itv;
		int count=0;
		string::iterator its2=s.begin();
		for(its=s.begin();its!=s.end();its++)
		{
			
			if(count==0)
			{
				if(!isspace(*its))
				{
					if(its==its2)
					{
						vfirst.push_back(toupper(*its));
					}
					else
						vfirst.push_back(tolower(*its));
				}
				else{
					vfirst.clear();
					vfirst.push_back(toupper(*its2));
					vfirst.push_back('.');
					vfirst.push_back(' ');
					its2=its;
					count++;
				}
			}
			else if(count==1){
				if(!isspace(*its))
				{
					if(its==its2+1)
					{
						vsecond.push_back(toupper(*its));
					}
					else
						vsecond.push_back(tolower(*its));
				}
				else{
					vsecond.clear();
					vsecond.push_back(toupper(*(its2+1)));
					vsecond.push_back('.');
					vsecond.push_back(' ');
					its2=its;
					count++;
				}

			}
			else{
				if(its==its2+1)
				{
					vthird.push_back(toupper(*its));
				}
				else
					vthird.push_back(tolower(*its));
			}
		}
		if(!vfirst.empty())
		{
			for(itv=vfirst.begin();itv!=vfirst.end(); itv++)
			{
				cout<<*itv;
			}
		}
		if(!vsecond.empty())
		{
			for(itv=vsecond.begin();itv!=vsecond.end(); itv++)
				cout<<*itv;
		}
		if(!vthird.empty()){
			for(itv=vthird.begin(); itv!=vthird.end(); itv++)
				cout<<*itv;
		}
		cout<<endl;
	}
	return 0;
}
