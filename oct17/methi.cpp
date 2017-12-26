#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	cin>>test;
	while(test--){
	  int num , k , dup=0;
	  int check=0 , j=0 , ans=0;
	  cin>>num>>k;
	  int arr[num];
	  for(int i=0;i<num;i++){
	    cin>>arr[i];
	  }
      sort(arr , arr+num);

     if(k>=0){
      dup=k;
      while(1){
      	if(dup==0||j==num)
      		break;
        if(arr[j]!=check)
          dup--;
        else
          j++;
        check++;
      }
      if(j==num){
      ans=check+k;
  }
      else{
      	while(arr[j]==check){
      		j++;
      		check++;
      	}
      	ans=check;
      }
      cout<<ans<<endl;
  }
	}
	return 0;
}
