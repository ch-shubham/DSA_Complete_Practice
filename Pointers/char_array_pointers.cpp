#include<iostream>

using namespace std;

int main(){
  char str[] = "abcde";
  // char *pstr = "abcde"; // Not the right way to use strings.

  int a[] = {1,2,3};
  char b[] = "Hello World";
  cout<<a<<endl;
  cout<<b<<endl; // prints complete Hello World because char pointers are implemented differently in c++. 
  // It prints actual value till it sees null pointer, and since string literal ends with null pointer so it prints complete string

  char *c=&b[0];
  cout<<c<<endl;

  char c1='a';
  char *pc = &c1;
  cout<<c1<<endl;
  cout<<pc<<endl; // unexpected output because it prints till it reaches \o null pointer
}