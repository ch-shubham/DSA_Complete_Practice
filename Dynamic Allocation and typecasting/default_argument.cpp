#include<iostream>

using namespace std;

int sum(int a[], int size, int start_index = 0){ // default argument can be given to right most arguments only.
  int ans = 0;
  for(int i=start_index; i<size; i++){
    ans+=a[i];
  }
  return ans;
}

int main(){
  int a[4] = {3,1,1,5};
  cout<<sum(a,4)<<endl; // gives 10 as output
  cout<<sum(a,4,1)<<endl; // gives 7 as output
}