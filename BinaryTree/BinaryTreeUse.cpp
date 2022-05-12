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

int main(){
  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);

  root -> left = node1;
  root -> right = node2;

  printTreeRecursively(root);

  delete root;
}