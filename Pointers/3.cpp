#include<iostream>

using namespace std;
 
 int main(){
   int i;
   cout<<i<<endl; // garbage value

   i++; // garbage value increased.
   cout<<i<<endl; 

  //  int *p; //never ever leave the pointer unassigned. If there is nothing to assign at time of declaration, assign it with 0;
  int *p=0;
   cout<<p<<endl;
   cout<<*p<<endl; //shows segmentation fault as address 0 is unreachable.

   (*p)++; 
   cout<<*p<<endl;
 }