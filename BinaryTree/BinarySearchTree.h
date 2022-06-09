#include "BinaryTreeNode.h"

class BST{

  // template is int for demo but we can use T also.
  BinaryTreeNode<int> * root;
  public:
    BST(){
      root=NULL; // important becuase if not assigned root will be garbage and garbage address is very dangerous
    }  
    ~BST(){
      delete root; // root will delete complete tree itself as root is of type BinaryTreeNode and we have already declared recursive destructor there.
    }

  
  // HASDATA -> to check if given data exist in our tree or not
  private:
    // helper function: recursive calls will be made on smaller segments of trees so thats why we have used this helper function with a slight difference in function signature
    bool hasData(int data, BinaryTreeNode<int> root){
      if(node == NULL)  {
        return false;
      }
      if(root->data == data){
        return true;
      }
      else if(data > root->data){
        hasData(root->right);
      }else{
        hasData(root->left);
      }
    }

  public:
    bool hasData(int data){ // Function to check if the given data exist in our BST or not
      return hasData(data, root); // recursion will be used so helper function is neede that recvs the root also.
    }

  // INSERTION IN A BST
  private:
    // Helper function to insert the node.
    BinaryTreeNode<int> * insert (int data, BinaryTreeNode<int>* node){
      // if we have reached the end or the tree is empty
      if(node == NULL){
        BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
        return newNode;
      }

      if(data < root->data){
        root->left = insert(data, node->left);
      }
      else(
        node -> right = insert(data, node->right);
      )
      return node; // if we are inserting on left or right the root still remains the node we receive, so return node.
    }

  public:
    void insert(int data){
      this->root = insert(data, root); // helper function with different signature defined above. So we are insert to root of our tree. 
    }

  // DELETE In a BST
  // Helper function
  private:
    BinaryTreeNode<int> * deleteData(int data, BinaryTreeNode<int> * node){
      if(node == NULL){
        return NULL;
      }
      if(data > root->data){
        node->right = deleteData(data, node->right); // after deletion its possible that the root of right can change so we need to return the new node i.e. "node" itself
        return node;
      }
      else if(data < node->left){
        node->left = deleteData(data, node->left);
        return node;
      }
      else{
        if(node -> left == NULL && node->right == NULL){
          delete node;
          return NULL;
        }
        else if(node->left == NULL){
          BinaryTreeNode<int> * temp = node -> right;
          node->right = NULL; // if not done our recursive destructor will delete entire tree on right also
          delete node;
          return temp;
        }else if(node->right == NULL) {
          BinaryTreeNode<int>* temp = node->left;
          node->left == NULL;
          delete node;
          return temp;
        }else{
          BinaryTreeNode<int>* minNode = node->right;
          // leftmost element on right side will be minimum on right of tree
          while(minNode -> left != NULL){
            minNode=minNode->left;
          }
          int rightMin = minNode->data; // value is stored in rightMin and not the node.
          node->data = rightMin; // replacing the rightMin with node's data to make it root.
          node->right = deleteData(rightMin, node->right); // after we get the rightMin we replaced it with the node's data and make it root. After making root we also need to delete the m=rightMin from right side which can give new root of right side so that is why assigning node->right to deleteData
          return node; // we just replaced the root->data with minData on right to make it root. The node still remains the same.
        }
      }
    }

  public:
    // delete is reserved keyword so we are using deleteData.
    void deleteData(int data){
      root = deleteData(data, root)
    }
  
  private:
    // Inorder
    void printTree(BinaryTreeNode<int>* root){
      if(root == NULL){
        return;
      }
      cout<<root->data <<" : ";
      if(root->left != NULL){
        cout<<"L"<<root->left->data;
      }
      if(root->right != NULL){
        cout<<"R"<<root->right->data;
      }
      cout<<endl;
      printTree(root->left);
      printTree(root->right);
    }

  public:
    void printTree(){
      printTree(root);
    }
};

// h=height of tree. h can be n so it can be O(n). But we use Balanced BST where the height is of order (logN) so T.C becomes: O(logN) N = number of nodes
// Time Comlexity of Searching: O(h) 
// Time Comlexity of Insertion: O(h)
// Time Comlexity of Deletion: O(h)
