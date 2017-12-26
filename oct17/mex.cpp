#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
int debug = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;

    while (T--){
        int N, K;
        cin >> N >> K;
        int arr[N], max = 0, num;
        set <int> myset;
        set <int> :: iterator its;

        for (int i = 0; i < N; i++){
            cin >> num;
            myset.insert(num);
            if (num > max)
                max = num;
        }

        int count = 0;  
        dout << "max" <<max << endl;
        int flag = 0;
        its = myset.begin();

        while (count <= max){
            //dout << "curr arr element " << arr[arrcount] << endl;
            dout << "curr count  " << count << endl;
            if (*its == count){
                dout << "found in arr " << count << endl;
                its++;
                count++;
            }

            else{
                if(K == 0){
                    flag = 1;
                    break;
                }

                else{
                    K--;
                    count++;
                }
            }

        }
        if(flag == 1){
            cout << count << endl;
        }
        else 
            cout << count + K   << endl;
    }

	return 0;
}
