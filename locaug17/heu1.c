    #include <stdio.h>
    #define ll long long int
    #define MOD 1000000007
    #define MAX 1e3
    ll fib(ll n)
    {
        ll f[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,1},{0,1}},tmp[2][2]= {{0,0},{0,0}};
        int i,j,k;
        while(n)
        {
            if(n&1)
            {
                memset(tmp,0,sizeof tmp);
                for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                            tmp[i][j]=(tmp[i][j]+ret[i][k]*f[k][j])%MOD;
                for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
            }
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+f[i][k]*f[k][j])%MOD;
            for(i=0; i<2; i++) for(j=0; j<2; j++) f[i][j]=tmp[i][j];
            n/=2;
        }
        return (ret[0][1])%MOD;
    }int main()
    {
        int n;
        scanf("%d",&n);
        long long i,k;
        while(n--){
        ll a; 
        scanf("%lld",&a);
        printf("%d\n",fib(a+1));
        }
        return 0;
    }
