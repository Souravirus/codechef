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
    while(T--){
        dout << " inside T"<<endl;
        map<int, int> mymap;
        int arr[7][7];
        for(int i=1; i <= 6; i++)
        {
            if(i%2==1)
                mymap[i]=i+1;
            else
                mymap[i]=i-1;
        }
        for(int i=0; i<= 6; i++)
            for(int j=0; j<= 6; j++)
                arr[i][j]=0;
        int n;
        cin >> n;
        int num;
        int prev = 0;
        int flag = 0;
        for(int i=0; i < n; i++)
        {
            dout << "inside n"<<endl;
            cin >> num;
            if(prev != 0){
                if(prev == num)
                {
                    flag =1;
                }
                arr[prev][num]=1;
                arr[num][prev]=1;
            }
            prev = num;
        }
        if(flag != 1){
            for(int i=1; i <=6; i++)
            {
                dout << "inside for loop at "<< i <<endl;
                if(arr[i][mymap[i]]==1){
                    int flag1=0;
                    for( int j = 1; j <= 6; j++){
                        if(i != j)
                        {
                            if(arr[i][j]==0)
                            {
                                dout << "match found at i"<< j<<endl;
                                dout << "here mymap i"<<mymap[i]<<endl;
                                dout << "here mymap j"<<mymap[j]<<endl;
                                if(arr[mymap[j]][mymap[i]] == 0)
                                {
                                    dout << "match valid"<<endl;
                                    int conn1=mymap[i];
                                    int conn2 = mymap[j];
                                    mymap[conn1] = conn2;
                                    mymap[conn2] = conn1;
                                    mymap[i]=j;
                                    mymap[j]=i;
                                    dout << "breaking away"<<endl ;
                                    flag1 = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if(flag1 == 0)
                    {
                        dout << "flag1 for "<<i << endl;
                        flag =1 ;
                        break;
                    }
                }
            }
        }
        if( flag == 1)
            cout << "-1" << endl;
        else
        {
            for(int i=1; i <= 6; i++)
                cout << mymap[i]<<" ";
            cout << endl;
        }
    }
	return 0;
}
#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
