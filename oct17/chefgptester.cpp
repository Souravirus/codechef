#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int count = 0;
        string str;

        for(int i = 0; i< str.length(); i++){
            if (str[i] == '*')
                count ++;   
        }

        cout << count << endl; 
    }
    
    return 0;
}
