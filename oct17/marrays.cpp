#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

int debug = 1;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;
        vector<vector<int> > myvect;
        vector<vector<int> > tminvect;
        vector<vector<int> > tmaxvect;

        for (int i = 0; i < N; i++){
            int M;
            cin >> M;
            int num; 
            vector<int>vect;
            vector<int> minvect;
            vector<int> maxvect;
            int max = 0;
            int min = INT_MAX;
            for (int i = 0; i < M; i++){
                cin >> num;
                if (num > max)
                {
                    maxvect.clear();
                    maxvect.push_back(i);
                    max = num;
                }

                else if(num == max)
                    maxvect.push_back(i);

                if(num < min)
                {
                    minvect.clear();
                    minvect.push_back(i);
                    min = num;
                }

                else if(num == min)
                    minvect.push_back(i);

                vect.push_back(num); 
            }
             
            tmaxvect.push_back(maxvect);
            tminvect.push_back(minvect);
            myvect.push_back(vect);
        }
        
        int index;
        int count = 0;
        int chooser = 0;
        int max = 0;
        int tempIndex;

        dout << "myvect[N-1][tminvect[N-1][0]:" << myvect[N-1][tminvect[N-1][0]] << endl; 
        dout << "myvect[N-1][tmaxvect[N-1][0]:" << myvect[N-1][tmaxvect[N-1][0]] << endl; 
        dout << "myvect[N-2][tminvect[N-2][0]:" << myvect[N-2][tminvect[N-2][0]] << endl; 
        dout << "myvect[N-2][tmaxvect[N-2][0]:" << myvect[N-2][tmaxvect[N-2][0]] << endl; 
        int minmax = abs(myvect[N-1][tminvect[N-1][0]] - myvect[N-2][tmaxvect[N-2][0]]);
        int maxmin = abs(myvect[N-1][tmaxvect[N-1][0]] - myvect[N-2][tminvect[N-2][0]]);

        dout << "minmax:" << minmax << endl;
        dout << "maxmin:" << maxmin << endl;

        if(minmax > maxmin){

           count = minmax * (N-1);
           dout << "current count:"<< count << endl;

           if( N >= 3){ 
               for(int i = 0; i < tmaxvect[N-2].size(); i++){
                    dout << "tmaxvect[N-2][i]:" << tmaxvect[N-2][i] << " myvect[N-2].size():" << myvect[N-2].size() << endl;
                   tempIndex = (tmaxvect[N-2][i] + 1) % myvect[N-2].size();

                   dout << "current tempIndex in minmax > maxmin " << tempIndex << endl;
                   int maxsub = abs(myvect[N-2][tempIndex] - myvect[N-3][tmaxvect[N-3][0]]); 
                   int minsub = abs(myvect[N-2][tempIndex] - myvect[N-3][tminvect[N-3][0]]); 

                   if(minsub > max){
                       max = minsub;
                       index = tempIndex;
                       chooser = 1;
                   }

                   if(maxsub > max){
                       max = maxsub;
                       index = tempIndex;
                       chooser = 0;
                   }

               }
           }
        }
        
        else{

           count = maxmin * (N-1);
           dout << "current count:"<< count << endl;

           if(N >= 3){
               for(int i = 0; i < tminvect[N-2].size(); i++){
                   dout << "tminvect[N-2][i]:" << tminvect[N-2][i] << " myvect[N-2].size():" << myvect[N-2].size() << endl;
                   tempIndex = (tminvect[N-2][i] + 1) % myvect[N-2].size();
                   dout << "current tempIndex in maxmin > minmax " << tempIndex << endl;

                   int maxsub = abs(myvect[N-2][tempIndex] - myvect[N-3][tmaxvect[N-3][0]]); 
                   int minsub = abs(myvect[N-2][tempIndex] - myvect[N-3][tminvect[N-3][0]]); 

                   dout << " maxsub:" << maxsub << " minsub:" << minsub << endl;
                   if(minsub > max){
                       max = minsub;
                       index = tempIndex;
                       chooser = 1;
                   }

                   if(maxsub > max){
                       max = maxsub;
                       index = tempIndex;
                       chooser = 0;
                   }

               }
           }
        }

        for(int i = N-3; i > 0; i--){

            if(chooser == 0){
               count += max * (i+1);
               dout << "current count:" << count << endl;
               max = 0;
               for(int j = 0; j < tmaxvect[i].size(); j++){

                   tempIndex = (tmaxvect[i][j] + 1) % myvect[i].size();
                   dout << "current tempIndex in chooser = 0 " << tempIndex << endl;

                   int maxsub = abs(myvect[i][tempIndex] - myvect[i-1][tmaxvect[i-1][0]]); 
                   int minsub = abs(myvect[i][tempIndex] - myvect[i-1][tminvect[i-1][0]]); 

                   if(maxsub > max){
                       max = maxsub;
                       index = tempIndex;
                       chooser = 0;
                   }

                   if(minsub > max){
                       max = minsub;
                       index = tempIndex;
                       chooser = 1;
                   }
               }
            }
            
            else{
               count += max * (i+1);
               dout << "current count:" << count << endl;
               max = 0;
               for(int j = 0; j < tminvect[i].size(); j++){
                   tempIndex = (tminvect[i][j] + 1) % myvect[i].size();
                   dout << "current tempIndex in chooser = 1 " << tempIndex << endl;

                   int maxsub = abs(myvect[i][tempIndex] - myvect[i-1][tmaxvect[i-1][0]]); 
                   int minsub = abs(myvect[i][tempIndex] - myvect[i-1][tminvect[i-1][0]]); 

                   if(maxsub > max){
                       max = maxsub;
                       index = tempIndex;
                       chooser = 0;
                   }

                   if(minsub > max){
                       max = minsub;
                       index = tempIndex;
                       chooser = 1;
                   }

               }
            }
        }
        
        count += max;
        dout << "current count:" << count << endl;
        cout << count << endl;
    }

	return 0;
}
