#include<iostream>
using namespace std;

#include "Node.cpp"

// If you want to stop at lasst Node the condition should be (temp -> next != NULL) but if you want to stop after last node the condition should be (temp != NULL)


// // NOT FULLY OPTIMIZED AS TIME COMPLEXITY IS O(n^2) here
// Node* takeInput(){
//   int data;
//   cin>>data;
//   Node *head = NULL;
//   // Assuming that -1 is exit point andno more elements need to be entered ater entering -1
//   while(data != -1){
//     Node *newNode = new Node(data); // Dynamic allocation is important as scope and Node gets deleted automatically if created in stack memory.
//     if(head == NULL){ // Initializing the Head pointer for the firest time.
//       head = newNode;
//     }
//     else{
//       Node *temp = head; 
//       // used to traverse the LL and stop at last node so that we can connect newNode with the last Node  
//       while(temp->next != NULL){ // We want to stop temp at last node so that is why we used (temp->next !=NULL)
//         temp = temp -> next;
//       }
//       temp -> next = newNode;
//     }
//     cin>>data;
//   }
//   return head;
// }


// OPTIMIZED AS TIME COMPLEXITY IS O(n) here
Node* takeInput(){
  int data;
  cin>>data;
  Node *head = NULL;
  Node *tail = NULL;
  // Assuming that -1 is exit point andno more elements need to be entered ater entering -1
  while(data != -1){
    Node *newNode = new Node(data); // Dynamic allocation is important as scope and Node gets deleted automatically if created in stack memory.
    if(head == NULL){ // Initializing the Head pointer for the firest time.
      head = newNode;
      tail = newNode;
    }
    else{
      tail->next = newNode;
      tail=newNode;
    }
    cin>>data;
  }
  return head;
}


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
  // Node n1(1);
  // Node *head = &n1;

  // Node n2(2);
  // Node n3(3);
  // Node n4(4);
  // Node n5(5);
  // n1.next = &n2;
  // n2.next = &n3;
  // n3.next = &n4;
  // n4.next = &n5;

  Node* head = takeInput();

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