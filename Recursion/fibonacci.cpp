#include<iostream>

using namespace std;
// We can use Extended PMI to calculate Fibonacci
//fibo = {0,1,1,2,3,5,8,13,....[(n-1)+(n-2)]}
int fibo(int n){
  //Base
  if(n == 0 || n == 1)  { // 2 base cases needed because we are doing n-2 also
    return n;
  }
   
  //SmallOutput
  int smallOutput1 = fibo(n-1); // using PMI assume it to be true
  int smallOutput2 = fibo(n-2); // using extended PMI assume it to be true

  //finalAnswer
  int finalAnswer = smallOutput1 + smallOutput2;
  return finalAnswer;
}

int main(){
  // int n ; 
  // cin>>n;

  cout<<fibo(7)<<endl; // 13 should be printed
  // cout<<fibo(n)<<endl;
}