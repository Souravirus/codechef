// set_union example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_union, std::sort
#include <vector>       // std::vector

int main () {
  int a[1000000][10];
  for(int i=0;i<1000000;i++){
  	for(int j=0;j<10;j++){
  		a[i][j]=i;
  	}
  }
  return 0;
}
