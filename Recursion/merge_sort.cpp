#include<iostream>

using namespace std;

// Merging 2 half sorted array ex: {4,5,6,} {1,2,3}
void merge(int arr[], int si, int ei){
  int mid = (si+ei)/2;
  int n1 = mid - si + 1;
  int n2 = ei - mid;
  int a[n1];
  int b[n2];
  for(int i = 0; i < n1; i++){
    a[i] = arr[si+i];
  }
  for(int i = 0; i < n2; i++){
    b[i] = arr[mid + 1 + i];
  }

  int i=0;
  int j=0;
  int k=si;
  while(i < n2 && j < n2){
    if(a[i] < b[j]){
      arr[k] = a[i];
      k++; 
      i++;
    }else{
      arr[k] = b[j];
      k++;
      j++;
    }
  }
  while(i < n1){
    arr[k] = a[i];
    k++;
    i++;
  }
  while(j < n2){
    arr[k] = b[j];
    k++;
    j++;
  }
}

void merge_sort(int a[], int si, int ei){
  if(si >= ei){
    return;
  }
  int mid = (si+ei)/2;
  merge_sort(a,si,mid);
  merge_sort(a,mid+1,ei);
  merge(a,si,ei);
}

int main(){
  int a[] = {5,4,3,2,1,0};
  merge_sort(a, 0, 5);
  for(int i = 0; i < 6; i++){
    cout<<a[i]<<"\t\t";
  }
  cout<<endl;
}



/*
#include <iostream>
using namespace std;

// Function to merge left and right subarrays of arr.
void mergeTwoSortedArray(int leftSubArray[], int rightSubArray[], int arr[], int n, int m)
{
  // i is for leftSubArray, j is for rightSubArray, k is for arr
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < n && j < m) {
    if (leftSubArray[i] <= rightSubArray[j]) {
      arr[k] = leftSubArray[i];
      i++;
    }
    else {
      arr[k] = rightSubArray[j];
      j++;
    }
    k++;
  }

  // copy remaining elements of leftSubArray[] 
  while (i < n) {
    arr[k] = leftSubArray[i];
    i++;
    k++;
  }

  // copy remaining elements of rightSubArray
  while (j < m) {
    arr[k] = rightSubArray[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int size){
	//this is a special case - it means we don't have an array to sort. Mind that the array size can never be less than 0
	if (size == 0) {
		return;
  }

  // if only one element is present in arr then we don't need to divide array further as one element is sorted in itself.
  if(size == 1)
  {
    return;
  }
  // create leftSubArray and rightSubArray - and copy the elements as it is from arr.
  int n  = size / 2;
  int m = size - n;

  int leftSubArray[n];
  int rightSubArray[m];
    
  //pointer for arr
  int k = 0;

  for(int i = 0; i < n; i++)
  {
    leftSubArray[i] = arr[k];
    k++;
  }

  for(int j = 0; j < m; j++)
  {
    rightSubArray[j] = arr[k];
    k++;
  }
  //call mergeSort on left subarray
    mergeSort(leftSubArray, n);

  //call mergeSort on right subarray
    mergeSort(rightSubArray, m);

  //merging the two sorted subarrays back to the original one
    mergeTwoSortedArray(leftSubArray, rightSubArray, arr, n, m);
    return;
}

int main()
{
  int arr[] = { 14, 17, 22, 4, 1, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr,n);
  
  cout<<"Sorted array: ";
  for(int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
*/