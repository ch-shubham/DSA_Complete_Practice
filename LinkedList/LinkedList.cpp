#include<iostream>
using namespace std;

#include "Node.cpp"

// If you want to stop at lasst Node the condition should be (temp -> next != NULL) but if you want to stop after last node the condition should be (temp != NULL)


// // NOT FULLY OPTIMIZED AS TIME COMPLEXITY IS O(n^2) here
// Node* takeInput(){
//   int data;
//   cin>>data;
//   Node *head = NULL;
//   // Assuming that -1 is exit point andno more elements need to be inserted ater inserting -1
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
  // Assuming that -1 is exit point andno more elements need to be inserted ater inserting -1
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

// pos is the Index where we want to add the element.
Node* insertAt_ith_Postition(Node *head, int data, int i){
  Node* newNode = new Node(data);
  Node *temp = head;
  // for(int i = 0; i < pos - 1; i++ ){ //  not correct as the pos can be 0 or 1 also that will be skipped by this loop.
  int count = 0;
  if(i == 0){
    newNode->next = head;
    head = newNode;
    return head;  // returns the new Head if node is inserted at the start only.
  }
  while(count < i - 1 && temp !=NULL){
    temp = temp->next;
    count++;
  }
  if(temp != NULL){
    newNode->next = temp->next;
    temp->next=newNode;
  }
  return head;
}

Node* delete_at_ith_pos(Node *head, int pos){
  if(pos == 0){
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  int count = 0;
  Node *temp = head;
  while(count < pos - 1 && temp != NULL ){ // overflow condition also handled and temp will point to a node before node where the deletion has to be done. i.e. temp will point at (pos-1)th node.
    temp=temp->next;
    count++;
  }
  if(temp!=NULL){
    Node* d = temp->next;
    temp->next = temp -> next -> next; //temp -> next -> next; is same as d->next
    delete d;
  }
  return head;
}

// Calculate the length of the linked list using recursion.
int length_of_linked_list_using_recursion(Node* head){
  if(head == NULL){
    return 0;
  }
  int length = length_of_linked_list_using_recursion(head->next) + 1;
  return length;
}

// inserting at i-th position using recursion
Node* insertAt_ith_Postition_using_recursion(Node * head, int data, int pos){
  if(head == NULL){
    return head;
  } 
  if(pos == 0){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
    return head;
  }
  head-> next = insertAt_ith_Postition_using_recursion(head->next, data, pos-1);
  return head;
}

Node* delete_at_ith_pos_using_recursion(Node* head, int pos){
  if(head == NULL){
    return head;
  }
  if(pos == 0) {
    Node* newHead = head->next;
    delete head;
    return newHead;
  }
  head->next = delete_at_ith_pos_using_recursion(head->next, pos -1);
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


// Finding the mid using the length. O(n)
Node* mid_using_length(Node *head){
  int len = length_of_linked_list_using_recursion(head);
  Node* temp = head;
  for(int i = 0; i < (len-1)/2; i++){
    temp = temp->next;
  }
  return temp;
}

// Optimized way to calculate the mid in O(n/2)
Node* mid_without_length(Node *head){
  if(head == NULL){
    return head;
  }
  Node* slow = head;
  Node* fast = head->next;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Merging two sorted linked list using iterative method.
Node* merge_sorted_ll_without_recursion(Node *head1, Node *head2){
  Node dummyNode(-1);
  Node *ptr3 = &dummyNode;
  while(head1 != NULL && head2 != NULL){
    if(head1->data < head2->data){
      ptr3 -> next = head1;
      head1 = head1->next;
    }else{
      ptr3 -> next = head2;
      head2 = head2->next;
    }
    ptr3 = ptr3->next;
  }
  while(head1 != NULL){
      ptr3 -> next = head1;
      head1 = head1->next;
      ptr3 = ptr3->next;
  }

  while(head2 != NULL){
      ptr3 -> next = head2;
      head2 = head2->next;
      ptr3 = ptr3->next;
  }
  return dummyNode.next; // No need to delete as it is made in stack memory and dummyNode is not a pointer so we can access next using dot(.)
}

// Merging two sorted array using recursion
Node* merge_sorted_ll_with_recursion(Node*head1, Node* head2){
  if(head1 == NULL) {
    return head2;
  }
  if(head2 == NULL) {
    return head1;
  }
  Node* result = NULL;
  if(head1->data < head2->data){
    result = head1;
    result->next = merge_sorted_ll_with_recursion(head1->next, head2);
  }else{
    result = head2;
    result->next = merge_sorted_ll_with_recursion(head1, head2->next);
  }
  return result;
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

  // Node* head = takeInput();
  Node* head1 = takeInput();
  Node* head2 = takeInput();

  // print(head);

  // head = insertAt_ith_Postition(head, 120, 2);
  // head = insertAt_ith_Postition(head, 120, 0);
  // head = insertAt_ith_Postition(head, 120, 10);


  // head = insertAt_ith_Postition_using_recursion(head, 120, 2);
  // head = insertAt_ith_Postition_using_recursion(head, 120, 0);
  // head = insertAt_ith_Postition_using_recursion(head, 120, 10);

  // print(head);

  // head = delete_at_ith_pos(head, 2);
  // head = delete_at_ith_pos(head, 0);
  // head = delete_at_ith_pos(head, 10);

  // head = delete_at_ith_pos_using_recursion(head, 2);
  // head = delete_at_ith_pos_using_recursion(head, 0);
  // head = delete_at_ith_pos_using_recursion(head, 10);

  // print(head);

  print(head1);
  print(head2);
  // Node * merged_head_without_recursion = merge_sorted_ll_without_recursion(head1, head2); // WITHOUT RECURSION
  // print(merged_head_without_recursion);
  Node * merged_head_with_recursion = merge_sorted_ll_with_recursion(head1, head2); // WITH RECURSION
  print(merged_head_with_recursion);



  // Node* mid1 = mid_using_length(head);
  // if(mid1 != NULL){
  //   cout<<mid1->data<<endl;
  // }


  // Node* mid2 = mid_without_length(head);
  // if(mid2 != NULL){
  //   cout<<mid2->data<<endl;
  // }
  // int length = length_of_linked_list_using_recursion(head);  
  // cout<<"Length of LL using recursion is: "<<length<<endl;
  // print(head);

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