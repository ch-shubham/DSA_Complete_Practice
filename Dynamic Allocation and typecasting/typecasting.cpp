#include<iostream>

using namespace std;

int main(){
  int i = 65;
  char c = i;

  cout<< c << endl;

  int *p = &i;
  char * pc = (char*)p;

  cout<< p <<endl;
  cout<< pc <<endl;
  
  cout<< *p <<endl;
  cout<< *pc <<endl; // prints A as de referencing is done as little endian
  cout<< *(pc+1) <<endl; // prints null(enter[blank line])
  cout<< *(pc+2) <<endl; // prints null(enter[blank line])
  cout<< *(pc+3) <<endl; // prints null(enter[blank line])
}