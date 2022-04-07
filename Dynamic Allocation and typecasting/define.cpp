#include<iostream>
using namespace std;

#define PI 3.14 //this is macro

int main(){

  // int PI = 4.12;  // PI can not be re defined as it is used as MACRO, so this statement gives error.
  int r;
  cin>>r;
  cout<< PI*r*r<<endl;
  
}