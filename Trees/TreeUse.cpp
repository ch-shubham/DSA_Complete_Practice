#include<iostream>

using namespace std;

#include "TreeNode.h"

// Basic version of printing the tree
// No need to write base case explicitly as we are using the for loop. and calling inside the for loop. So if size is zero no call will be made to recursion.
// void printTree(TreeNode<int> *root){
//   if(root == NULL){ // This is a edge case and not the base. Without this also i will work expect one condition where root is NULL.
//     return;
//   }
//   cout<<root->data<<endl;
//   for(int i = 0; i < root->children.size(); i++){
//     printTree(root->children[i]);
//   }
// }


// Improvised version of Tree which prints the children as well.
void printTree(TreeNode<int> *root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<" : ";
 
  for(int i = 0; i < root->children.size(); i++){
    cout<<root->children[i]->data<<", ";
  }
  cout<<endl;
  
  for(int i = 0; i < root->children.size(); i++){
    printTree(root->children[i]);
  }
}

TreeNode<int> * takeInput(){
  cout<<"Enter the data"<<endl;
  int rootData;
  cin>>rootData;

  TreeNode<int> *root = new TreeNode<int>(rootData);

  int n;
  cout<<"enter the number of children";
  cin>>n;

  for(int i = 0; i < n; i++){
    TreeNode<int> *child = takeInput();
    root->children.push_back(child);
  }
  return root;
}

int main(){ 
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);

  // root->children.push_back(node1);
  // root->children.push_back(node2);

  // printTree(root);

  TreeNode<int>* root = takeInput();
  printTree(root);

  // TODO: Delete the tree. 


}