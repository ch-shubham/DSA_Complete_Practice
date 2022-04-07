#include<iostream>

#include "Student.cpp"
using namespace std;

int main(){
  // For every object creation only one constructor is called irrespective of how many constructors are declared.
  Student s1; // As soon as this is written or our Program Counter reaches here. Constructor(Default or user defined) of the class is call
  // s1.display();
  
  Student *s3 = new Student;
  // s3 -> display();

  Student s4(101); // As soon as this is written or our Program Counter reaches here. Constructor(Default or user defined) of the class is call
  s4.display();

  Student *s5 = new Student(102);
  s5 -> display();

  Student *s6 = new Student(24, 103);
  s6 -> display();

  Student s7(25,104);
  cout<<"Address of s7 = "<<&s7<<endl;
}