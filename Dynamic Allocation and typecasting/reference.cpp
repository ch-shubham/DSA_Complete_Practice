#include<iostream>

using namespace std;

void increment(int &j){
  j++;
}

// // BAD PRACTICE
// int &f(int n){
//   int a =n;
//   return a;
// }

// // BAD PRACTICE
// int* f2(){
//   int i = 10;
//   return &i;
// }

int main(){
  // int *p = f2();
  int i;
  i=10;

  // int& k1 = f(i);
  increment(i);
  cout<<i<<endl;


  int &j=i; // reference allocation of j to i; i.e. now i and j will point to same add in the symbol table, no new memory is allocated to j and it points to memory of i only.
  i++;
  cout<<j<<endl;
  j++;
  cout<<i<<endl;
  int k=100;
  j=k;
  cout<<i<<endl;
}
