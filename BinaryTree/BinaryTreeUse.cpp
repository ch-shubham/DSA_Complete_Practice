#include<iostream>
#include<queue>
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

BinaryTreeNode<int> * takeInputLevelWise(){
  int rootData;
  cout<<"Enter Root Data"<<endl;
  cin>>rootData;
  if(rootData == -1){
    return NULL;
  }

  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size() != 0){
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter the left child of: "<< front->data<<endl;
    int leftChildData;
    cin>>leftChildData;
    if(leftChildData != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child); 
    }

    cout<<"Enter the right child of: "<< front->data<<endl;
    int rightChildData;
    cin>>rightChildData;
    if(rightChildData != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child); 
    }
  }
  return root;
}

int numNodes(BinaryTreeNode<int>* root){
  if(root == NULL){
    return 0; 
  }
  return (1 + numNodes(root->left) + numNodes(root->right));
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  // while(!pendingNodes.empty()){
  while(pendingNodes.size() != 0){
    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<front->data<<" : ";
    if(front->left != NULL){
      pendingNodes.push(front->left);
      cout<<"L"<<front->left->data;
    }
    if(front->right != NULL){
      pendingNodes.push(front->right);
      cout<<"R"<<front->right->data;
    }
    cout<<endl;
  }
}

void inorder(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void preorder(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

// inS, inE, preS, preE are all indexes and not the actual array or values
// *in and *pre are the arrays of inorder and preOrder
BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE){
  if(inS > inE){
    return NULL;
  }
  int rootData = pre[preS]; // it should not be pre[0] as in recurive call it will always pick the first element of the array.
  int rootIndex = -1;
  for(int i = inS; i <= inE; i++){
    if(in[i] == rootData){
      rootIndex = i;
      break;
    }
  }
  int lInS = inS;
  int lInE = rootIndex - 1;
  int lpreS = preS + 1;
  int lpreE = lInE - lInS + lpreS;
  int rpreS = lpreE + 1;
  int rpreE = preE;
  int rInS = rootIndex + 1;
  int rInE = inE;

  BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
  root->left = buildTreeHelper(in, pre, lInS, lInE, lpreS, lpreE);
  root->right = buildTreeHelper(in, pre, rInS, rInE, rpreS, rpreE);

  return root;

}

// The only condition is the elements in the array should not be repeated else it will be difficult to find root.
// if elements are repeated then there must be some other condition specified in the ques.
BinaryTreeNode<int> * buildTree(int* in, int * pre, int size){
  return buildTreeHelper(in, pre, 0, size-1, 0, size-1); // returns the tree from the function defined above.
}

// 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1 --> input using recursion sample
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 --> input using queue or level wise sample
int main(){
  // BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
  // BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
  // BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);

  // root -> left = node1;
  // root -> right = node2;

  // BinaryTreeNode<int>* root = takeInputRecursive();
  int in[] = { 4,2,5,1,8,6,9,3,7 }; 
  int pre[] = { 1,2,4,5,3,6,8,9,7 }; 
  

  // BinaryTreeNode<int>* root = takeInputLevelWise();
  BinaryTreeNode<int>* root = buildTree(in, pre, 9);

  // printTreeRecursively(root);
  // printTreeLevelWise(root);
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  // postorder(root);
  // cout<<endl;
  // cout<<"Number of Nodes: " << numNodes(root)<<endl;

  delete root;
}