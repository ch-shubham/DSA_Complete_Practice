template <typename T>
class BinaryTreeNode{
  public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
      this->data = data;
      left = NULL;
      right = NULL;
    }

    ~BinaryTreeNode(){
      delete left; // delete NULL will do nothing so no need to check if left or right is NULL or not.
      delete right;  // delete NULL will do nothing so no need to check if left or right is NULL or not.
    }
};