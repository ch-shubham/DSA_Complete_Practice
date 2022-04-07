#include<iostream>

using namespace std;

int main(){
  int i = 10; 
  int *p = &i; // address of i stored in pointer p
  int *q = p; // value of p, i.e. address of i stored in q

  cout<<sizeof(p)<<endl; // prints the size of pointer type variable. (8 bits generally)
  cout<<i<<endl; 
  cout<<*p<<endl; // same as cout<<i

  i++;

  cout<<i<<endl;
  cout<<*p<<endl;

  int a = *p;
  a++;
  cout<<a<<endl;
  cout<<*p<<endl;

  i=12;
  cout<<i<<endl;
  cout<<*p<<endl;
  *p=23; // similar to i=23
  cout<<i<<endl;
  cout<<*p<<endl;

  (*p)++; // similar to i++

  // we can perform all the opertion on (*p) that can be done on i;
  cout<<i<<endl;
  cout<<*p<<endl;
}