#include<iostream>

using namespace std;

int main(){
  int *p = new int;
  *p=10;
  cout<<*p<<endl;

  double *pd = new double;

  char *c = new char;

  int *pa = new int[50]; // this statement wants total 208bytes. 200bytes in heap for array and 8 bytes for the pointer in stack.

  int n;
  cin>>n;
  int *pa2 = new int[n]; // this dynamic array is ok as it creates the memory for the array in heap.

  for(int i =0; i<n;i++){
    cin>>pa2[i];
  }

  int max = -1;
  for(int i = 0; i<n; i++){
    if(max < pa2[i]){
      max = pa2[i];
    }
  }
  cout<<max<<endl;
}