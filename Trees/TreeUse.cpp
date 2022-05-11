#include<iostream>
#include<queue>

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

TreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout<<"Enter Root Data"<<endl;
  cin>>rootData;
  TreeNode<int> * root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size() != 0){
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter number of children for "<<front->data<<endl;
    int numChild;
    cin>>numChild;
    for(int i = 0; i < numChild; i++){
      int childData;
      cout<<"Enter the data for "<<i<<"th child of" <<front->data<<endl;
      cin>>childData;
      TreeNode<int>* child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }    
  } 
  return root;
}



// Below is just the imput to avoid entering all the inputs again and again.
//  1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
int main(){ 
  // TreeNode<int> *root = new TreeNode<int>(1);
  // TreeNode<int> *node1 = new TreeNode<int>(2);
  // TreeNode<int> *node2 = new TreeNode<int>(3);

  // root->children.push_back(node1);
  // root->children.push_back(node2);

  // printTree(root);

  // TreeNode<int>* root = takeInput();
  TreeNode<int>* root = takeInputLevelWise();
  printTree(root);

  // TODO: Delete the tree. 


}