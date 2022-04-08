class DynamicArray {
  int *data;
  int nextIndex;
  int capacity; // Total Size of array

  public: 
    DynamicArray(){
      data = new int[5]; // Assuming starting array to be of size 5;
      nextIndex = 0;
      capacity = 5; // size of the array
    }

    void add(int element) {
      if(nextIndex == capacity){
        int *newData = new int[2 * capacity];
        for(int i = 0; i < capacity; i++){
          newData[i] = data[i];
        }
        delete [] data;
        data = newData;
        capacity *= 2;
      }
      data[nextIndex] = element;
      nextIndex++;
    }

    int get(int i) const{
      if(i < nextIndex){
        return data[i];
      }
      return -1;
    }

    void add(int i, int element){
      if(i < nextIndex){
        data[i] = element;
      }
      else if(i == nextIndex){
        add(element);
      }
      else{
        return;
      }
    }

    void print() const{
      for(int i =0; i < nextIndex; i++){
        cout<<data[i]<<" ";
      }
      cout<<endl;
      cout<<capacity<<endl;
    }

    // Custom Copy Constructor
    DynamicArray(DynamicArray const &d){
      // this -> data = data; // Shallow Copy

      // Deep Copy
      this->data=new int[d.capacity];
      for(int i = 0; i < d.nextIndex; i++){
        this->data[i] = d.data[i];
      }
      this->nextIndex=d.nextIndex;
      this->capacity=d.capacity; 
    }

    void operator=(DynamicArray const &d){
      // this -> data = data; // Shallow Copy

      // Deep Copy
      this->data=new int[d.capacity];
      for(int i = 0; i < d.nextIndex; i++){
        this->data[i] = d.data[i];
      }
      this->nextIndex=d.nextIndex;
      this->capacity=d.capacity; 
    }
};