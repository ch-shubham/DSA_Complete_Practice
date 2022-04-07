#include<iostream>

using namespace std;

int main(){
  int i =10;
  int* p=&i;

  cout<<p<<endl;
  p=p+1; // adds 4bytes to p. i.e. (address of i) + 4bytes
  cout<<p<<endl;
  p=p+2; // adds 8 bytes to p
  cout<<p<<endl;
  p=p-3; // subtracts 12 bytes from add of p
  cout<<p<<endl;

  double d = 102.3;
  double* dp = &d;
  cout<<dp<<endl; 
  dp++; // adds 8 bytes to address of dp as its pointing to double variable whuich is 8 bytes generally.
  cout<<dp<<endl;

}