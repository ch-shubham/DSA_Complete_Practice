#include<iostream>
#include "Student.cpp"
using namespace std;

int main(){
  
  Student s1;

  Student *s2 = new Student;

  s1.rollNo = 101;
  s1.setAge(24);
  s1.display();

  s2 -> rollNo = 102;
  s2 -> setAge(25);
  s2 -> display(); 
}