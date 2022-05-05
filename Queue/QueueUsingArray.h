// header file is same as cpp file, just that it can never have the main function.
template <typename T>
class QueueUsingArray{
  T *data;
  int size;
  int nextIndex;
  int firstIndex;
  int capacity;
  
  public:
    QueueUsingArray(int totalSize){
      data = new T[totalSize];
      size = 0;
      nextIndex = 0;
      firstIndex = -1;
      capacity = totalSize;
    }

    int getSize(){
      return size;
    }

    bool isEmpty(){
      return size == 0;
    }

    // insert element
    void enqueue(T element){
      if(size == capacity){
        cout<<"Queue is full and no extra elements can be inserted."<<endl;
        return;
      }
      data[nextIndex] = element;
      nextIndex = (nextIndex + 1) % capacity;
      if(firstIndex == -1){
        firstIndex = 0;
      }
      size++;
    }


    // returns the first element of queue;
    T front(){
      if(isEmpty()){
        cout<<"Empty Queue"<<endl;
        return 0;
      }
      return data[firstIndex];
    }

    // delete element
    T dequeue(){
      if(isEmpty()){
        cout<<"Empty Queue"<<endl;
        return 0;
      }
      T ans = data[firstIndex];
      firstIndex = (firstIndex + 1) % capacity;
      size--;
      // the below code is not important but good to have.
      if(size == 0){
        firstIndex = -1;
        nextIndex = 0;
      }
      return ans;
    }
};