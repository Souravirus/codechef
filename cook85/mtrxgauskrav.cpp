#include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	long long int n,q;
    	scanf("%lld%lld",&n,&q);
    	long long int a[n+1][n+1],i,j,p,dp[n+1],x,k;
    	for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
    	scanf("%lld",&a[i][j]);
    	for(i=0;i<=q;i++)
    	{
    	    if(i>0)
    	    {
    	        scanf("%lld",&p);
    	        for(j=1;j<=n;j++)
    	        {
    	            scanf("%lld",&a[p][j]);
    	            a[j][p]=a[p][j];
    	        }
    	    }
    	    dp[1]=0;
    	    for(j=2;j<=n;j++)
    	    {
    	        for(k=j-1;k>0;k--)
    	        {
    	            if(dp[k]!=0)
    	            break;
    	        }
    	        if(k==0)
    	        dp[j]=-a[1][j];
    	        else
    	        {
    	        if(a[1][j]+a[1][k]!=a[k][j])
    	        {
    	            if(dp[k]<0)
    	            dp[j]=-a[1][j];
    	            else
    	            dp[j]=a[1][j];
    	        }
    	        else
    	        {
    	            if(dp[k]<0)
    	            dp[j]=a[1][j];
    	            else
    	            dp[j]=-a[1][j];
    	        }
    	        }
    	      
    	    }
    	    for(j=1;j<=n;j++)
    	    printf("%lld ",dp[j]);
    	    printf("\n");
    	}
    	return 0;
    } 
