#include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int siz = 1e3 + 2;
    const ll modu = 1e9 + 7;
    int arr[siz][siz];
     
    int mod(int a) {
    	if(a < 0)
    		return -a;
    	return a;
    }
     
    void calc(int n) {
    	int ind = n - 1;
    	for(int i = 1; i < n; i++) {
    		if(arr[0][i]) {
    			ind = i;
    			break;
    		}
    	}
    	for(int i = 0; i < ind; i++)
    		printf("0 ");
    	int x = (-1) * arr[0][ind], val;
    	printf("%d ", x);
    	for(int i = ind + 1; i < n; i++) {
    		int val1 = arr[0][i];
    		int val2 = (-1) * arr[0][i];
    		int diff1 = mod(x - val1), diff2 = mod(x - val2);
    		if(diff1 == arr[ind][i])
    			val = val1;
    		else
    			val = val2;
    		printf("%d ", val);
    	}
    	printf("\n");
    }
     
    int main() {
    	int n, q;
    	scanf("%d%d", &n, &q);
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++)
    			scanf("%d", &arr[i][j]);
    	calc(n);
    	while(q--) {
    		int p;
    		scanf("%d", &p);
    		for(int i = 0; i < n; i++) {
    			int a;
    			scanf("%d", &a);
    			arr[i][p - 1] = a;
    			arr[p - 1][i] = a;
    		}
    		calc(n);
    	}
    	return 0;
    } 
