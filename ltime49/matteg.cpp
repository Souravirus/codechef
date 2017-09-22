#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	int  R, C, N;
	int Sx, Sy;
	cin>>T;
	while(T--)
	{
		cin>>R>>C>>N;
		int arr[R][C];
		int telx[N], tely[N];
		cin>>Sx>>Sy;
		for(int i=0; i<N; i++)
		{
			cin>>telx[N];
			cin>>tely[N];
		}
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				cin>>arr[i][j];
			}
		}
		int count=0;
		tsum=arr[Sx][Sy];
		int pres[N]=0;
		for(int i=0; i<N; i++)
			pres[i]=0;
		int posx, posy;
		while(count<N)
		{
			int max=0;
			for(int i=0;i<N; i++)
			{
				if(pres[i]==0)
				{
					if(arr[telx][tely]>max)
					{
						posx=telx;
						posy=tely;
					}
					if(arr[-1*telx][tely]>max)
					{
						posx=telx;
						posy=tely;
					}
					if(arr[-1
				}
			}
		}
	}
	return 0;
}
