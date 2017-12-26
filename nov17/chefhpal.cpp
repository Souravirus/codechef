#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int N, A;
        cin >> N >> A;
        
        if(A == 1){
            cout << N << " ";
            
            for(int i = 0; i < N; i++){
                cout << "a";
            }

            cout << endl;
        }

        else if (A == 2){
            //cout << "Hello I am here" << endl; 
            if (N==1){
                cout << "1 " << "a" << endl; 
            }

            else if(N==2){
                cout << "1 " << "ab" << endl;
            }

            else if(N==3){
                cout << "2 " << "abb" << endl;
            }

            else if(N==4){
                cout << "2 " << "aabb" << endl;
            }

            else if(N == 5){
                cout << "3 " << "aaaba" << endl;
            }

            else if(N == 6){
                cout << "3 " << "aaabab" << endl;
            }

            else if(N == 7){
                cout << "3 " << "aaababb" << endl;
            }

            else if(N == 8){
                cout << "3 " << "aaababbb" << endl;
            }

            else{
                char arr[6];
                arr[0] = 'a'; arr[1] = 'a'; arr[2] = 'b'; arr[3] = 'a';
                arr[4] = 'b'; arr[5] = 'b';
                cout << "4 ";

                for(int i = 0; i < N; i++){
                    int num = i % 6;    
                    cout << arr[num];  
                }

                cout << endl;
            }

        }

        else{
            cout << "1 ";
            for(int i = 0; i < N; i++){
                int num = i%A;
                char alpha = 'a' + num;
                cout << alpha;
            }
            cout << endl;
        }
    }
    return 0;
}
