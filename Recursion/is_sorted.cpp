#include<iostream>

using namespace std;

bool is_sorted(int a[], int size){
  // Base condition
  if(size == 0 || size == 1)  {
    return true;
  }

  // Base condition
  if(a[0] > a[1]){
    return false;
  }

  // smaller output
  bool isSmallerSorted = is_sorted(a+1, size-1);
  
  // final Answer
  return isSmallerSorted;
  /*
    if(isSmallerSorted == true){
      return true;
    } 
    else {
      return false;
    }
  */
}


int main(){
  int a[] = {1,2,3,4};
  int b[] = {1,2,4,3};
  cout<<is_sorted(a,4)<<endl; // true
  cout<<is_sorted(b,4)<<endl; // false
}