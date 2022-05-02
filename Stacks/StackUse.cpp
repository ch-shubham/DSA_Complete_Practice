#include<iostream>
using namespace std;

#include "stack_using_array.cpp"

int main(){
  // StackUsingArray *stack = new StackUsingArray(5);
  // stack->push(100);
  // cout<<stack->top()<<endl;
  // (*stack).push(200);
  // cout<<stack->top()<<endl;

  StackUsingArray stack(4);
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50); // Stack is full should be printed as size is 4 and we are trying to insert 5 elements here.

  cout<<stack.top()<<endl; // 50
  cout<<stack.pop()<<endl; // 50
  cout<<stack.pop()<<endl; // 40
  cout<<stack.pop()<<endl; // 30
  cout<<stack.top()<<endl; // 20
  cout<<stack.isEmpty()<<endl; // 0
  cout<<stack.pop()<<endl; // 20
  cout<<stack.pop()<<endl; // 10
  cout<<stack.isEmpty()<<endl; // 1
}