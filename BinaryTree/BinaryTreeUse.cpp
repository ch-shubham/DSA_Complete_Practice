#include<iostream>

using namespace std;

#include "BinaryTreeNode.h"

void printTreeRecursively(BinaryTreeNode<int> * root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<" : ";
  if(root->left != NULL){
    cout<<" L"<<root->left->data;
  }
  if(root->right != NULL){
    cout<<" R"<<root->right->data;
  }
  cout<<endl;
  printTreeRecursively(root->left);
  printTreeRecursively(root->right);
}

BinaryTreeNode<int>* takeInputRecursive(){
  int rootData;
  cout<<"Enter the Data"<<endl;
  cin>>rootData;
  if(rootData == -1){
    return NULL;
  }
  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int> * leftChild = takeInputRecursive();
  BinaryTreeNode<int> * rightChild = takeInputRecursive();
  root->left = leftChild;
  root->right = rightChild;
  return root;
}

int main(){
  // BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
  // BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
  // BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);

  // root -> left = node1;
  // root -> right = node2;

  BinaryTreeNode<int>* root = takeInputRecursive();

  printTreeRecursively(root);

  delete root;
}