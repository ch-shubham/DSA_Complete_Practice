// Here we are implementing the Min Priority Queue i.e. min heap

#include<vector>

class PriorityQueue{
  vector<int> pq;

  public:
    PriorityQueue(){}

    bool isEmpty(){
      return pq.size() == 0;
    }

    int getSize(){
      return pq.size();
    }

    int getMin(){
      if(isEmpty()){ 
        return 0; // returning zero just to represnt that our pq is empty. 
      }
      return pq[0];
    }

    // Insertion in a Priority Queue
    void insert(int element){
      pq.push_back(element);
      int childIndex = pq.size() - 1; // initially, new element is the child and we need to up-heapify if needed. push_back is done so inserted at the end.
      while(childIndex>0){
        int parentIndex = (childIndex - 1)/2; 
        if(pq[childIndex] < pq[parentIndex]){
          int temp = pq[childIndex];
          pq[childIndex] = pq[parentIndex];
          pq[parentIndex] = temp;
        }
        else{ // it means the inserted element has reached the correct position.
          break;
        }
        childIndex = parentIndex; // new childIndex is now parentIndex because the swapping is done.
      }
    }

    // Remove Minimum from the Priority Queue
    int removeMin(){
      if(isEmpty()){
        return 0; //representing the PQ is empty.
      }

      int ans = pq[0]; // storing the minimum value from the priority queue that is located at the first index.
      pq[0] = pq[pq.size()-1]; // copying the last element to the 1st so that we can pop_back becuase in actual 1st element is min and has to be removed. 
      pq.pop_back(); // removing the last element as we have already replace it with the first element at 0th index.

      // down-heapify
      int parentIndex = 0;
      int leftChildIndex = 2 * parentIndex + 1; // 2i+1
      int rightChildIndex = 2 * parentIndex + 2; // 2i-1

      while(leftChildIndex < pq.size()){
        int minIndex = parentIndex;
        if(pq[minIndex] > pq[leftChildIndex]){
          minIndex = leftChildIndex;
        }
        if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]){
          minIndex = rightChildIndex;
        }
        if(minIndex == parentIndex){
          break;
        }
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
        leftChildIndex = 2*parentIndex + 1; 
        rightChildIndex = 2*parentIndex + 2; 
      }
      return ans;
    }
};