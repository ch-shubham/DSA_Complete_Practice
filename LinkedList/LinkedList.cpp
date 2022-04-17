#include<iostream>
using namespace std;

#include "Node.cpp"

void print(Node *head){
  Node *temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp -> next;
  }
  cout<<endl;
  
  // We used temp so that the head is not lost.
  // temp = head;
  // while(temp != NULL){
  //   cout<<temp->data<<" ";
  //   temp = temp -> next;
  // }
  // cout<<endl;
}


int main(){
  // STATICALLY
  Node n1(1);
  Node *head = &n1;

  Node n2(2);
  Node n3(3);
  Node n4(4);
  Node n5(5);
  A
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  print(head);
  print(head);

  // // cout << n1.data << " "<< n2.data << endl;
  // cout << head->data << endl; // or we can also write: // cout << (*head).data << endl; both are same

  // DYNAMICALLY
  // Node *n3 = new Node(10);
  // Node *head = n3;
  // Node *n4 = new Node(20);
  // n3 -> next = n4;
  // // cout << head -> data << " " << n3 -> next -> data <<endl; // this also gives the o/p but using n1 is not good as we won't be knowing the names of node and have to work with addresses only. 
  // cout << head -> data << " " << head -> next -> data <<endl;

}