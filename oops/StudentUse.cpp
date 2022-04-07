#include<iostream>
#include "Student.cpp"

using namespace std;

int main(){
  // Statically creating objects.
  Student s1;
  Student s2;
  Student s3, s4, s5;

  // s1.age = 24;
  s1.rollNo = 101;
  

  // cout<<s1.age<<endl;
  cout<<s1.rollNo<<endl;
  cout<<s1.getAge()<<endl;
  
  s1.display();

  // Dynamically Creating objects.
  Student *s6 = new Student;
  Student *s7 = new Student;
  // (*s6).age = 25; // dereference of the object is must in case of dynamic allocation.
  (*s6).rollNo = 102;


  // Below syntax is preffered.
  // s7 -> age = 26; // This is same as line 22, its dereferencing and using the property of class at the same time.
  s7 -> rollNo = 103;


  // cout<<(*s6).age<<endl;
  cout<<(*s6).rollNo<<endl;
  (*s6).display();
  // cout<<s7 -> age<<endl;
  cout<<s7 -> rollNo<<endl;
  s7 -> display();
}