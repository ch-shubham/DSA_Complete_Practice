#include<iostream>

using namespace std;

int main(){
  int *p = new int; // this statement wants 12bytes. 8 in stack for pointer variable and 4 in heap for integer
  delete p; // method to delete heap memory.

  p = new int; // reassignment can be done to pointer if the address it is pointing to has been deleted.
  delete p;

  int *pa=int[12]; 
  delete []pa; // way to release the memory in heap if it is array

  // while(true){
  //   int *p = new int;
  // }

  // while(true){
  //   int i=10;
  // }
}