#include<string>
using namespace std;

template<typename V>
class MapNode{
  public:
    string key; // not using template for the key for the simplification
    V value;
    MapNode* next;

    MapNode(string key, V value){
      this->key = key;
      this->value = value;
      next = NULL;
    }

    ~MapNode(){ // destructor, // deletes entire LL recursively 
      delete next;
    }
};

template<typename V>
class ourmap{
  MapNode<V> ** buckets; // buckets will be dynamically created and every element in this array holds the head of the LL as we are using seperate chaining for collision handling
  int count; // total number of elements inserted in entire ourmap
  int numBuckets; // size of buckets array

  public:
    ourmap(){
      count = 0;
      numBuckets = 5; // initially taking it to be of size 5;
      buckets = new MapNode<V>*[numBuckets];
      for(int i =0; i<numBuckets; i++){
        buckets[i] = NULL;
      }
    }

    ~ourmap(){
      for(int i = 0; i<numBuckets;i++){
        delete buckets[i]; // it will delete all the LL recursively 
      }
      delete[] buckets; // after all the buckets are deleted we will delete the array also.
    }

    // returns the total elements in ourmap
    int size(){
      return count; 
    }

    private:
      // This is a hashfunction that returns the index for the element in the bucket array 
      
      // 1st part of HashFunction. i.e: hashCode generation
      int getBucketIndex(string key){
        int hashcode = 0;
        int currCoeff = 1;
        for(int i=key.size()-1;i>0;i--){
          hashcode+=key[i] * currCoeff;
          hashcode = hashcode%numBuckets; // To keep within the limits of our numBuckets
          currCoeff*= 37; // any prime number is valid.
          currCoeff = currCoeff%numBuckets; // To keep within the limits of our numBuckets
        }

        // 2nd part of the hashfunction, i.e: compression function which compresses the hashcode within the limits of the numBuckets
        return hashcode%numBuckets;
      }

    private:
      void rehash(){
        MapNode<V> ** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i = 0; i<2*numBuckets; i++){
          buckets[i] = NULL; // so that garbage address are not stored.
        }
        int oldBucketCount = numBuckets;
        numBuckets = 2 * numBuckets;
        count = 0;

        for(int i = 0; i<oldBucketCount; i++){
          MapNode<V> * head = temp[i];
          while(head != NULL){
            string key = head->key;
            V value = head->value;
            insert(key, value); // again insertion is needed for all elements as numBuckets are changed so there positions in ourmap will also change
            head = head->next;
          }
        }

        // deletion of oldBucket
        for(int i =0; i<oldBucketCount; i++){
          MapNode<V> * head = temp[i];
          delete head;
        }
        delete [] temp;
      }

    public:
      void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
          if(head->key == key){
            head->value = value;
            return;
          }
          head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        // loadFactor check
        double loadFactor = (1.0*count)/numBuckets; // 1.0 because if not done int/int gives int but we want double.
        if(loadFactor > 0.7){
          rehash();
        }
      }
    
      double getLoadFactor(){
        return (1.0*count)/numBuckets;
      }

      V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>*head = buckets[bucketIndex];
        MapNode<V>*prev = NULL;
        while(head != NULL){
          if(head -> key == key){
            if(prev==NULL){
              buckets[bucketIndex] = head->next;
            }else{
              prev->next = head->next;
            }
            V value = head->value;
            head->next = NULL; // We have recursive destructor so that is why this line is needed.
            delete head;
            count--;
            return value;
          }
          prev = head;
          head = head->next;
        }
        return 0; // if key not found in our complete map.
      }

      V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>*head = buckets[bucketIndex];
        while(head != NULL){
          if(head -> key == key){
            return head->value;
          }
        }
        return 0; // key not found;
      }
};