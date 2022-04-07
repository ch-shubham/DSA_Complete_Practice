#include<iostream>

using namespace std;

int main(){
  
  int i = 10;
  cout<<i<<endl; // Uses the symbol table and search the add of i then print the value at that address.
  
  cout<<&i<<endl; // prints the address of i

  int *p = &i; // to store the address of variable pointer variable is used which is generally 8bytes but not necessarily.
  cout<<p<<endl; // prints the add of i

  double d = 102.32; // double type variable.
  double *dp = &d; // dp is pointer to double.
  cout<<dp<<endl;

  int **pp = &p; // to store the address of a pointer double pointer i.e (**) is used.
  cout<<pp<<endl; 
  cout<<&p<<endl;

}