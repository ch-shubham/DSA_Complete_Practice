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


// function to find the height of the binary tree
int height(BinaryTreeNode<int> * root) {
  if(root == NULL){
    return 0;
  }
  return 1 + max(height(root->left),height(root->right));
}

// diameter is the maximum difference between two nodes.
// Naive approach (Not very good to use). Here the time complexity depends on the height of the tree that is: O(n*h) so if we have one sided tree it can lead to O(n^2) which is very bad
int diameter(BinaryTreeNode<int>* root){
  if(root == NULL){
    return 0;
  }
  // height function is defined above.
  int option1 = height(root->left) + height(root->right);
  int option2 = diameter(root->left);
  int option3 = diameter(root->right);
  return max(option1, max(option2, option3));
}

// helper function to below mention diameterBetter function
// returns the height and diameter at the same time.
pair<int, int> heightDiameter(BinaryTreeNode<int> * root){
  // we are putting height in first part of pair and diameter on 2nd part.
  if(root == NULL){
    pair<int, int> p;
    p.first = 0; // height = 0
    p.second = 0; // diameter = 0
    return p;
  }
  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);
  int ld = leftAns.second; // left diameter
  int lh = leftAns.first; // left height
  int rd = rightAns.second; // right diameter
  int rh = rightAns.first; // right height

  int height = 1 + max(lh, rh);
  int diameter = max(lh + rh, max(ld, rd));
  pair<int, int> p;
  p.first = height;
  p.second = diameter;
  return p;
}


// This function is a better approach than the above one. This approach takes O(n);
int diameterBetter(BinaryTreeNode<int> * root){
  pair<int, int> ans = heightDiameter(root);
  return ans.second; // diameter from the above returned function
}

BinaryTreeNode<int> * searchInBST(BinaryTreeNode<int>* root, int elementToSearch){
  if(root == NULL){
    return NULL;
  }
  if(root->data == elementToSearch){
    return root;
  }
  if(elementToSearch > root->data){
    return searchInBST(root->right, elementToSearch);
  }
  else{
    return searchInBST(root->left, elementToSearch);
  }
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
  // int in[] = { 4,2,5,1,8,6,9,3,7 }; 
  // int pre[] = { 1,2,4,5,3,6,8,9,7 }; 
  

  BinaryTreeNode<int>* root = takeInputLevelWise();
  // BinaryTreeNode<int>* root = buildTree(in, pre, 9);

  // printTreeRecursively(root);
  printTreeLevelWise(root);
  // inorder(root);
  // cout<<endl;
  // preorder(root);
  // cout<<endl;
  // postorder(root);
  // cout<<endl;
  // cout<<"Number of Nodes: " << numNodes(root)<<endl;
  // cout << diameter(root)<<endl;
  // cout << diameterBetter(root)<<endl;

  // give input as : 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
  BinaryTreeNode<int>* searchedNode = searchInBST(root, 6); // for example we are taking 6 hard code value
  cout<<"After Searching the Node will be something like:"<<endl;
  printTreeLevelWise(searchedNode); // expected is 6: L5R7      5:     7:  
  delete root;
}