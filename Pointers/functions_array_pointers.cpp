#include<iostream>

using namespace std;

// int sum(int *a,int size){
int sum(int a[],int size){ // above statement is also same.
  // cout<<sizeof(a)<<endl;
  int ans = 0;
  for(int i=0;i<size;i++){
    ans += a[i];
  }
  return ans;
}

int main(){
  // int a[10]; // garbage value is stored in array.
  int a[10] = {1,1,1,1,1,1,1,1,1,1};
  cout<<sizeof(a)<<endl;
  cout<<sum(a,10)<<endl;
  cout<<sum(a+2,8)<<endl;
}