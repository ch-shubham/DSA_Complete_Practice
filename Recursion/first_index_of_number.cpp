#include<iostream>

using namespace std;

int first_index(int a[], int size, int x){
  // Base Condition
  if(size == 0){
    return -1;
  }

  // Base Condition with small calculation
  if(a[0] == x){
    return 0;
  }

  // Final Answer
  int ans = first_index(a+1, size-1, x);
  return ans == -1 ? ans : ans+1;
}

int main(){
  int a[] = {5,5,6,5,4,3};
  int firstIndex1 = first_index(a,6,5); // 0
  int firstIndex2 = first_index(a,6,6); // 2
  int firstIndex3 = first_index(a,6,4); // 4
  int firstIndex4 = first_index(a,6,9); // -1
  
  cout<<firstIndex1<<endl;
  cout<<firstIndex2<<endl;
  cout<<firstIndex3<<endl;
  cout<<firstIndex4<<endl;
}