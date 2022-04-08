#include<iostream>

using namespace std;

#include "DynamicArray.cpp"

int main(){
  DynamicArray d1;

  d1.add(10);
  d1.add(20);
  d1.add(30);
  d1.add(40);
  // d1.add(50);
  // d1.add(60);

  d1.print();

  // DynamicArray d2(d1); // copy constructor will be called and Copy would be Shallow by default Copy contructor
  // d1.add(0, 100); // Changes are done in d1 but it will reflect in d2 also as shallow copy is done in above line
  // // and hence the address of d1 is copied to d2 so they both are pointing to same address, therefor change in
  // // one gets relected in other also.
  // d1.print(); 
  // d2.print(); // once we create our own copy constructor with deep copy logic, change in one won't reflect in another

  // DynamicArray d3;
  // d3 = d1; // copy constructor will be called and Copy would be Shallow by default Copy contructor
  // d3 goes into "this" and d1 goes into the argument.
  // d1.add(1, 200); // Changes are done in d1 but it will reflect in d2 also as shallow copy is done in above line
  // // and hence the address of d1 is copied to d2 so they both are pointing to same address, therefor change in
  // // one gets relected in other also.
  // d1.print(); 
  // d3.print(); // once we create our own copy constructor with deep copy logic, change in one won't reflect in another

}
