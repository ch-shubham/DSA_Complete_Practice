#include<iostream>

using namespace std;

// BAD PRACTICE to use global variables.
int a ;

void g(){
  a++;
  cout<<a<<endl;
}

void f(){
  cout<<a<<endl;
  a++;
  g();
}

int main(){
  a=10;
  f();
  f();
  cout<<a<<endl
}