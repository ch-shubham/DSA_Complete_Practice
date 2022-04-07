#include<iostream>

using namespace std;

// 1 line of code is good for inline. not for more than 1 line
inline int max(int a, int b){ // similar to #define, this code will be replaced inside the call where ever it is called before runtime.
  return (a>b) ? a : b;
}

int main(){
  int a,b;
  a=10;
  b=20;
  int c = max(a,b); // body of the inline code will be copied here during compile time only.

  cout<<c<<endl;

  int x,y;
  x=12;
  y=34;

  int z = max(x,y);
  cout<<z<<endl;
}