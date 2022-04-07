// Example of Copy Constructor

#include<iostream>
#include "Student.cpp"

using namespace std;

int main(){

  /// COPY CONSTRUCTOR EXAMPLE
  // Student s1(24, 101);
  // Student s2(s1); // equivalent to s2.Student(s1) i.e. Copy constructor will be called.

  // s1.display();
  // cout<<"========"<<endl;
  // s2.display();

  // Student *s3 = new Student(25, 102);

  // Student s4(*s3);
  
  // Student *s5 = new Student(*s3);
  // Student *s6 = new Student(s1);

  /// COPY ASSIGNMENT OPERATOR EXAMPLE
  Student s1(10, 1001);
  Student s2(20, 2001);

  Student *s3 = new Student(30, 3001);

  s2 = s1;

  *s3 = s1;

  s2 = *s3;
  /*
  Here Destructor is called only 2 times because s3 is created dynamically and it is created in heap memory and not in stack memory.
  So its our responsibility to delete that dynamically created memory from the heap by calling delete s3. As default destructor deletes only Stack memory.
  s3 is just a pointer variable so no need to call the destructor so thats why destructor is called only 2 times
  */


  // Now the destructor will be called again here to delete the heap memory.
  delete s3;


}