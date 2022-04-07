#include<iostream>

using namespace std;

int main(){
  int a[10];  // declares the array of size 10 i.e. 40 bytes. and a is pointing to 1st address of array in symbol table.
  cout<<a<<endl; // address of a[0]
  cout<<&a[0]<<endl; // same as above line
  cout<<&a<<endl; // same as above line. & looks in symbol table and in symbol table a pooints to 1sty element of the array so it points to 1st element only.

  a[0] = 5;
  a[1] = 10;
  cout<<*a<<endl; // value at a i.e. value at add of a[0]
  cout<<a[0]<<endl;
  cout<<*(a+1)<<endl; // value at a[1]

  int *p= &a[0]; // p is allocated seperate 8 bytes and in there address of a[0] is stored

  cout<<a<<endl;
  cout<<p<<endl;

  cout<<&p<<endl;
  cout<<&a<<endl;
  
  cout<<sizeof(a)<<endl; // 40 bytes. Because in symbol table array is stored with size 10 
  cout<<sizeof(p)<<endl; // 8 bytes. Because in symbol table add of pointer variable is stored i.e. 8 bytes.
  
  p=p+1; // we can change p as it has its own seperate memory 
  // a=a+1; // this is invalid as array can not be reassigned. Because we can not do changes in symbol table.
}