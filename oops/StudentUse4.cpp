#include<iostream>

#include "Student.cpp"

using namespace std;

int main(){
  Student s1; // Constructor 1 called

  Student s1(10); // Constructor 2 called

  Student s3(11,101); // Constructor 3 called

  Student s4(s1); // Copy Constructor called

  s1 = s2; // No constructor called. Its not object creation. Copy Assignment operator is used here.

  Student s5 = s4; // Internally its calling like s5(s4), i.e copy constructor is called.

  
}