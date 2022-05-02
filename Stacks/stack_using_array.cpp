#include<climits>

template <typename T>
class StackUsingArray{
  T *data;
  int nextIndex;
  int capacity;

  public:
    StackUsingArray(){
      data = new T[4];
      nextIndex = 0;
      capacity = 4;    
    }

    // returns the number of elements;
    int size(){
      return nextIndex;
    }

    // returns if the stack is empty or not.
    bool isEmpty(){
      return nextIndex == 0;
    }

    // insert element at the top
    void push(T element){
      if(capacity == nextIndex){
        // cout<< "Stack is full"<<endl;
        // return;

        T *newData = new T[capacity*2];
        for(int i=0; i<capacity; i++){
          newData[i] = data[i];
        }
        capacity *= 2;
        delete [] data;
        data = newData;
      }
      data[nextIndex] = element;
      nextIndex++;
    }

    // delete the element
    T pop(){
      if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return 0;  // return type has to be int so just as an indication we are returning INT_MIN, no particular reason.
      }
      nextIndex--;
      return data[nextIndex];
    }

    // returns the topmost element;
    T top(){  
      if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
      }
      return data[nextIndex-1];
    }


};