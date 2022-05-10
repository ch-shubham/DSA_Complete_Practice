#include<iostream>
#include<vector>

using namespace std;

int main(){
  // vector<int> *vp = new vector<int>(); // dynamic
  vector<int> v;  // static
 
  for(int i = 0; i < 100; i++){
    v.push_back(i+1);
    // cout<<v[i]<<" " ;
    cout<<v.size()<<" "; // gives the total number of elements in the array
    cout<<v.capacity()<<endl; // gives the capacity or the total number of elements vector can hold and its different from the size.
  }
 
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);

  v.pop_back(); // removes the last element from the vector
  // cout<<v[0]<<" "<<v.at(0)<<endl;
  // cout<<v[1]<<" "<<v.at(1)<<endl;

  // // Don't use [] to insert the element as it is not safe
  // v[1] = 200;
 
  // cout<<v[1]<<" "<<v.at(1)<<endl;
  // cout<<v[2]<<" "<<v.at(2)<<endl;

  // // [] will be used only to get and update the elements from the vector
  // // to insert to the vector we will be using the push_back() function of the vector  

  // // v[4] = 200; // not possible because vector has pushed back only 3 elements till now that is till 2nd index
  // // cout<<v[4]<<" "<<v.at(4)<<endl;
  // // v[4] = 100;
  // // v[5] = 500;
  // v.push_back(125);
  // v.push_back(225);
  // cout<<v[3]<<" "<<v.at(3)<<endl;
  // cout<<v[4]<<" "<<v.at(4)<<endl;
  // // cout<<v[5]<<endl; // gives garbage value as its out of range of push back
  // // cout<<v.at(5)<<endl; // a bit safer than the [] to get element as it gives the error of out of range instead of printing garbge value.
  // cout<<"Size::"<<v.size()<<endl;

  // for(int i = 0; i < v.size(); i++){ // here we can use [] as we know v.size() will always be in the range and will never go out of range.
  //   cout<<v[i] << " "; // here it is safe to use [] as i will always be in range here.
  // }
  cout<<endl;
}