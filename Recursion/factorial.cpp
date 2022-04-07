#include<iostream>

using namespace std;

// Every Recursion question can be done with PMI(principle of mathematical indusction)
int factorial(int n){
  if(n==0){ // base case
    return 1;
  }
  int smallOutput = factorial(n-1); // dont question this line, just assume factorial(n-1) is correct and store in variable.
  int finalAnswer = smallOutput * n; // n * smallerProblemOutput
  return finalAnswer;
}

int main(){
  int n;
  cin>>n;
  cout<<factorial(n)<<endl;
}