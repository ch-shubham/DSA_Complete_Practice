#include<iostream>
#include<unordered_map>
#include<strings>

using namespace std;

int main(){
  // <keyType, valueType>
  unordered_map<string, int> ourmap;

  // Insert or Update
  pair<int, int> p("abc", 1);
  ourmap.insert(p);
  ourmap["def"] = 2; 

  // Find or Access
  cout<<ourmap["abc"]<<endl; // 1
  cout<<ourmap.at("abc")<<endl; // 1
  // cout<<ourmap.at("ghi")<<endl; // Throws Error
  cout<<ourmap.size()<<endl; // 2
  cout<<ourmap["ghi"]<<endl; // 0. this way of accessing inserts the key if does not exist and assign it to 0
  cout<<ourmap.size()<<endl; // 3

  // Check Presence
  if(ourmap.count("aaa") > 0){ // false, as "aaa" key does not exist
    cout<<"Exist"<<endl;
  }

  // Erase
  ourmap.erase("ghi");
  cout<<ourmap.size()<<endl; // 2


  // ITERATOR
  unordered_map<string, int>::iterator it = ourmap.begin();
  while(it != ourmap.end()){
    cout<<it->first<<"--"<<it->second<<endl;
    it++;
  }
}