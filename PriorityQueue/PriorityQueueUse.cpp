#include<iostream>

using namespace std;

#include "PriorityQueue.h"

int main(){
  PriorityQueue pq;
  pq.insert(100);
  pq.insert(10);
  pq.insert(15);
  pq.insert(4);
  pq.insert(17);
  pq.insert(21);
  pq.insert(67);

  cout<<pq.getSize()<<endl; // 7
  cout<<pq.getMin()<<endl; // 4
  int i = 1;
  while(!pq.isEmpty()){
    cout<<i<<"th element to be removed : "<<pq.removeMin()<<endl; // as removeMin returns the element that is getting returned. { it should be sorted output in increasing order}
    i++;
  }
  cout<<pq.getSize()<<endl; // 0 

}