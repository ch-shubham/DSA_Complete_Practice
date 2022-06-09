#include<iostream>
#include<string>
#include "Ourmap.h"

using namespace std;

int main(){
  ourmap<int> map;
  for(int i =0; i<10;i++){
    char c = '0'+ i; // so that 1,2,3, comes as a char.
    string key = "abc";
    key = key + c;
    int value = i+1;
    map.insert(key, value);
    cout<<map.getLoadFactor()<<endl; // Just to check that it never reaches above 0.7 as we have used rehash.
  }

  cout<<map.size()<<endl;
  map.remove("abc2");
  map.remove("abc7");
  cout<<map.size()<<endl;

  for(int i = 0; i < 10; i++){
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout<<key<<" : "<<map.getValue(key)<<endl;
  }
  // abc2 and abc7 should have value 0 as we have returned 0 by default.
  cout<<map.size()<<endl;

  
}