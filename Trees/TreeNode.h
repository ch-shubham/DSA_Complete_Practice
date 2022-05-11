#include<vector> 

using namespace std;

template <typename T>
class TreeNode{
  public:
    T data;
    vector<TreeNode*> children;  // TreeNode* works perfectly fine as it recognises itself about the T type.
    // vector<TreeNode<T>*> children; // above statement and this statement is both same.
    TreeNode(T data){
      this->data = data;
    }

    ~TreeNode(){
        cout<<data<<endl;
      for(int i = 0; i < children.size(); i++){
        delete children[i];
      }
    }
};