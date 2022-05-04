#include<iostream>
using namespace std;
#include<stack>
// #include "stack_using_array.cpp"
// #include "stack_using_linkedlist.cpp"

int main(){
  // StackUsingArray *stack = new StackUsingArray(5);
  // stack->push(100);
  // cout<<stack->top()<<endl;
  // (*stack).push(200);
  // cout<<stack->top()<<endl;


  /* // BEFORE optimizing the push operation which do not handle the dynamic array thing
  StackUsingArray stack(4);
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50); // Stack is full should be printed as size is 4 and we are trying to insert 5 elements here.

  cout<<stack.top()<<endl; // 40
  cout<<stack.pop()<<endl; // 40
  cout<<stack.pop()<<endl; // 30
  cout<<stack.pop()<<endl; // 20
  cout<<stack.top()<<endl; // 10
  cout<<stack.isEmpty()<<endl; // 0
  cout<<stack.pop()<<endl; // 10
  cout<<stack.isEmpty()<<endl; // 1
  */

  

  // AFTER optimizing the push operation which do not handle the dynamic array thing
  // StackUsingLinkedList<int> s;
  // s.push(10);
  // s.push(20);
  // s.push(30);
  // s.push(40);
  // s.push(50); 
  // s.push(60); 

  // cout<<s.top()<<endl; // 60
  // cout<<s.pop()<<endl; // 60
  // cout<<s.pop()<<endl; // 50
  // cout<<s.pop()<<endl; // 40
  // cout<<s.top()<<endl; // 30
  // cout<<s.isEmpty()<<endl; // 0
  // cout<<s.pop()<<endl; // 30
  // cout<<s.pop()<<endl; // 20
  // cout<<s.pop()<<endl; // 10
  // cout<<s.isEmpty()<<endl; // 1    

  // StackUsingArray<char> s2;
  // StackUsingLinkedList<char> s2;
  // s2.push(65);
  // s2.push('B');
  // s2.push('C');

  // cout<<s2.isEmpty()<<endl; // 0
  // cout<<s2.pop()<<" " <<s2.pop()<< " " << s2.pop()<<endl; // C B A
  // cout<<s2.isEmpty()<<endl; // 1

  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);

  cout<<s.top()<<endl;
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
  s.pop();
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
  s.pop();
  s.pop();
  cout<<s.size()<<endl;
  cout<<s.empty()<<endl;
}