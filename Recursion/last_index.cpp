// we can break the array from end as well, i.e. fun(a,size-1) but for learning purpose we are breaking it from start only in this ques also.

#include<iostream>

using namespace std;

int last_index(int a[], int size, int x){
  if(size == 0){ // BASE
    return -1;
  }

  int smallAns = last_index(a+1, size-1, x);
  if(smallAns == -1){ // SMALL CALCULATION
    return a[0] == x ? 0 : -1;
  }
  return smallAns+1; // FINAL ANSWER
}

int main(){
  int a[] = {5,5,4,5,6};

  cout<<last_index(a,5,5)<<endl; // 3 
  cout<<last_index(a,5,4)<<endl; // 2
  cout<<last_index(a,5,6)<<endl; // 4
  cout<<last_index(a,5,9)<<endl; // -1
}