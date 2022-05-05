template <typename T>
class Node{
  public:
    T data;
    Node<T> *next;

    Node(T data){
      this->data = data;
      next = NULL;
    }
};

template <typename T>
class QueueUsingLinkedList{
  Node<T> * head;
  Node<T> * tail;
  int size;

  public:
    QueueUsingLinkedList(){
      head = NULL;
      tail = NULL;
      size = 0;
    }

    // get the size of the queue.
    int getSize(){
      return size;
    }

    // returns if the queue is empty or not.
    bool isEmpty(){
      return size == 0;
    }

    // enters the element in queue
    void enqueue(T element){
      Node<T> *newNode = new Node<T>(element);
      if(head == NULL){
        head = newNode;
        tail = newNode;
      }else{
        tail -> next = newNode;
        tail = newNode;
      }
      size++;
    }

    // returns the fist element
    T front(){
      if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return 0;
      }
      return head->data;
    }

    // deletes the element from the queue.
    T dequeue(){
      if(isEmpty()){
        cout<<"Queue is already empty"<<endl;
        return 0;
      }
      T deletedElement = head->data;
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      size--;
      return deletedElement;
    }

};