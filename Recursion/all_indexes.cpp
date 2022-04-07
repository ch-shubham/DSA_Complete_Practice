#include<iostream>

using namespace std;

int all_indexes(int a[], int size, int x, int out[]){
  if(size == 0){
    return -1;
  }

  int smallAns = all_indexes(a, size-1, x, out);
  int finalAnswer = smallAns;
  if(a[size-1] == x){
    if(smallAns == -1){
      out[0] = size-1;
      finalAnswer = 1;
    }else{
    out[smallAns] = size-1; 
    finalAnswer = smallAns + 1;
    }
  }
  return finalAnswer;
}

int main(){
  int a[] ={5,5,6,5,6,4,5,6};
  int out1[20];
  int out2[20];
  int out3[20];
  int ans1 = all_indexes(a, 8, 5, out1);
  int ans2 = all_indexes(a, 8, 6, out2);
  int ans3 = all_indexes(a, 8, 4, out3);

  for(int i = 0; i<ans1 ; i++){
    cout<<out1[i]<<"\t";
  }
  cout<<endl;

  for(int i = 0; i<ans2 ; i++){
    cout<<out2[i]<<"\t";
  }
  cout<<endl;

  for(int i = 0; i<ans3 ; i++){
    cout<<out3[i]<<"\t";
  }
  cout<<endl;

  cout<<ans1<<endl;
  cout<<ans2<<endl;
  cout<<ans3<<endl;
}