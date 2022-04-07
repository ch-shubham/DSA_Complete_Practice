#include<iostream>

using namespace std;

#include "Student3.cpp"

int main(){
  Student s1;
  Student s2;
  Student s3;
  
  // cout<<Student::totalStudents<<endl; // public static variables can be used in this way
  
  cout<<Student::getTotalStudents()<<endl;
  
  // Student::totalStudents = 10; // public static variables can be assigned in this way as well.
  cout<<Student::getTotalStudents()<<endl;


}