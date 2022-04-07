#include<iostream>
#include<cstring>
using namespace std;

#include "Student.cpp"

int main(){
  char name[] = "Shubham";
  Student s1(14, name);
  // cout<<"S1 Before Change: ";
  // s1.display();

  // Student s2(15, name);
  // cout<<"S2 Before Change: ";
  // s2.display();

  // // When we do shallow copy, Change in name affects the objects also.
  // name[3] = 'z';
  // cout<<"S2 After Change of name[3] = 'z': ";
  // s2.display();
  // cout<<"S1 After Change of name[3] = 'z': ";
  // s1.display();

  Student s2(s1);
  s2.name[3] = 'z'; // Change in property of one should not change the change in property of other.. In shallow copy, change in one affects the other while in deep copy change in one does not affect other,
  cout<<"S1: ";
  s1.display();
  cout<<"S2: ";
  s2.display();
}
