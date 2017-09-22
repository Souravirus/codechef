nclude <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
struct Query
{
    int t, l, r;
    Query(int a, int b, int c)
        :t(a), l(b), r(c){}
    Query(){ t = l = r = 0; }
};
 
long long int Tree[2][4 * 100000];
long long int lazy[2][4 * 100000];
 
void queryUpdate(int T, int st, int en, int l, int r, int x, int p);
long long int queryGet(int T, int st, int en, int l, int r, int p);
 
int n, m;
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        //memset(Tree, 0, sizeof(Tree));
        //memset(lazy, 0, sizeof(lazy));
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 4 * 100000; j++)
                Tree[i][j] = 0, Tree[i][j] = 0;
        scanf("%d %d", &n, &m);
        Query V[100000];
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            b--, c--;
            V[i] = Query(a, b, c);
        }
        for(int i = m - 1; i >= 0; i--)
        {
            queryUpdate(1, 0, m - 1, i, i, 1, 0);
            Query tmp = V[i];
            if(tmp.t == 2)
                queryUpdate(1, 0, m - 1, tmp.l, tmp.r, queryGet(1, 0, m - 1, i, i, 0), 0);
            else
                queryUpdate(0, 0, n - 1, tmp.l, tmp.r, queryGet(1, 0, m - 1, i, i, 0), 0);
        }
        for(int i = 0; i < n; i++)
            printf("%lld ", queryGet(0, 0, n - 1, i, i, 0));
        puts("");
    }
    return 0;
}
 
void queryUpdate(int T, int st, int en, int l, int r, int x, int p)
{
    if(lazy[T][p] != 0)
    {
        Tree[T][p] = (Tree[T][p] % MOD + (lazy[T][p] * (en - st + 1)) % MOD) % MOD;
        if(st != en)
        {
            lazy[T][2 * p + 1] += lazy[T][p];
            lazy[T][2 * p + 1] = lazy[T][2 * p + 1] % MOD;
 
            lazy[T][2 * p + 2] += lazy[T][p];
            lazy[T][2 * p + 2] = lazy[T][2 * p + 2] % MOD;
        }
        lazy[T][p] = 0;
    }
    if(st > en || l > en || r < st)
        return;
    if(l <= st && en <= r)
    {
        Tree[T][p] = (Tree[T][p] % MOD + (x * (en - st + 1)) % MOD) % MOD;
        if(st != en)
        {
            lazy[T][2 * p + 1] += x;
            lazy[T][2 * p + 1] = lazy[T][2 * p + 1] % MOD;
 
            lazy[T][2 * p + 2] += x;
            lazy[T][2 * p + 2] = lazy[T][2 * p + 2] % MOD;
        }
        return;
    }
    queryUpdate(T, st, (st + en) / 2, l, r, x, 2 * p + 1);
    queryUpdate(T, (st + en) / 2 + 1, en, l, r, x, 2 * p + 2);
    Tree[T][p] += Tree[T][2 * p + 1] + Tree[T][2 * p + 2];
    Tree[T][p] %= MOD;
}
 
long long int queryGet(int T, int st, int en, int l, int r, int p)
{
    if(lazy[T][p] != 0)
    {
        Tree[T][p] = (Tree[T][p] % MOD + (lazy[T][p] * (en - st + 1)) % MOD) % MOD;
        if(st != en)
        {
            lazy[T][2 * p + 1] += lazy[T][p];
            lazy[T][2 * p + 1] = lazy[T][2 * p + 1] % MOD;
 
            lazy[T][2 * p + 2] += lazy[T][p];
            lazy[T][2 * p + 2] = lazy[T][2 * p + 2] % MOD;
        }
        lazy[T][p] = 0;
    }
    if(st > en || l > en || r < st)
        return 0;
    if(l <= st && en <= r)
        return Tree[T][p];
    return (queryGet(T, st, (st + en) / 2, l, r, 2 * p + 1) + queryGet(T, (st + en) / 2 + 1, en, l, r, 2 * p + 2)) % MOD;
}
