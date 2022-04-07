#include<iostream>

using namespace std;

void print(int* p){
  cout<<*p<<endl; // prints the value at address it receives in argument.
}

void increamentPointer(int *p){
  p=p+1; // increases the add of local p and not that of main.
}

void increament(int *p){
  (*p)++; // changes the value at address it receives in the argument.
}


int main(){
  int i = 10;
  int *p = &i;

  print(p);
  cout<<p<<endl;
  increamentPointer(p);
  cout<<p<<endl;

  cout<<*p<<endl;
  increament(p);
  cout<<*p<<endl;
}