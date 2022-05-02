#include<climits>

class StackUsingArray{
  int *data;
  int nextIndex;
  int capacity;

  public:
    StackUsingArray(){
      data = new int[4];
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
    void push(int element){
      if(capacity == nextIndex){
        // cout<< "Stack is full"<<endl;
        // return;

        int *newData = new int[capacity*2];
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
    int pop(){
      if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;  // return type has to be int so just as an indication we are returning INT_MIN, no particular reason.
      }
      nextIndex--;
      return data[nextIndex];
    }

    // returns the topmost element;
    int top(){  
      if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return INT_MIN;
      }
      return data[nextIndex-1];
    }


};