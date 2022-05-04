template <typename T>
class Node{
  public:
    T data;
    Node<T> *next;
    Node(T data){
      this->data = data;
      next=NULL;
    }
};

template <typename T>
class StackUsingLinkedList{
  Node<T> *head;
  int size;
  
  public:
    StackUsingLinkedList(){
      head = NULL;
      size = 0;
    }
  
    int getSize(){
      return size;
    }

    bool isEmpty(){
      return size == 0;
    }

    void push(T element){
      Node<T> *newNode = new Node<T>(element);
      newNode -> next = head;
      head = newNode;
      size++;
    }

    T pop(){
      if(isEmpty()){
        return 0;
      }
      Node<T>* temp = head;
      head = head-> next;
      T poppedElement = temp->data;
      delete temp;
      size--;
      return poppedElement;
    }

    T top(){
      if(head == NULL){
        return 0;
      }
      return head->data;
    }

};