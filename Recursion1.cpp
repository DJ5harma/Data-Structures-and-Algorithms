#include <iostream>
using namespace std;

// Fibonacci

int Fibo(int n) {

  if (n <= 1) {
    return 1;
  } else {
    return Fibo(n - 1) + Fibo(n - 2);
  }
}

int BinarySearch(int arr[], int key, int end, int start = 0) {
  int mid = (start - end) / 2 + end;

  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] > key) {
    return BinarySearch(arr, key, mid, start);
  } else if (arr[mid] < key) {
    return BinarySearch(arr, key, end, mid);
  } else {
    return -1;
  }
}

// Nto1
void Nto1(int n) {
  cout << n << endl;
  if (n == 1) {
    return;
  }
  Nto1(n - 1);
}

// OneToN
void OneToN(int n) {

  if (n > 1) {
    OneToN(n - 1);
  }
  cout << n << endl;
}

// n!
int nFact(int n, int fact = 1) {

  if (n >= 2) {
    return nFact(n - 1, fact * n);
  }
  return fact;
}

// nto1Sum
int nto1Sum(int n, int sum = 0) {

  if (n == 0) {
    return sum;
  }
  return nto1Sum(n - 1, sum + n);
}

// Sum of digits
int sumOfDigits(int n, int sum = 0) {

  if (n < 10) {
    return sum + n;
  }
  return sumOfDigits(n / 10, sum + n % 10);
  // return sumOfDigits((n-n%10)/10, sum+n%10); will work the same because in
  // int data type, the fractional no. is rounded off
}

// Product of digits
int productOfDigits(int n, int product = 1) {

  if (n < 10) {
    return product * n;
  }
  return productOfDigits(n / 10, product * (n % 10));
}

// Reverse a number
int reverseTheNum(int n, int reversed = 0) {
  if (n <= 0) {
    return reversed;
  }
  return reverseTheNum(n / 10, reversed * 10 + n % 10);
}

// Check if palindrome
bool isPalindrome(int n) { return n == reverseTheNum(n); }

// Count no. of zeroes in a number
int numberOfZeroes(int n, int zeroes = 0) {

  if (n <= 0) {
    return zeroes;
  }

  if (n % 10 == 0) {
    return numberOfZeroes(n / 10, zeroes + 1);
  } else {
    return numberOfZeroes(n / 10, zeroes);
  }
}

// Count the no. of steps required for reducing a number to zero, reducing as :
// if the number is even, divide by 2, if it is odd, subtract 1 form it
int stepsForReducingToZero(int n, int steps = 0) {

  if (n == 0) {
    return steps;
  }

  if (n % 2 == 0) {
    return stepsForReducingToZero(n / 2, steps + 1);
  }
    return stepsForReducingToZero(n - 1, steps + 1);
  
}


// Linear search
int LSearch(int arr[], int key, int n){
    if(arr[n]==key){return n;}
    else if(n==0){return -1;}
    return LSearch(arr, key, n-1);
}

// Linear search (Multiple recuurences)
// M1 
void LSearchMultipleM1(int arr[], int key, int n){
    if(arr[n]==key){cout<<n<<endl;}
    if(n==0){return;}
    return LSearchMultipleM1(arr, key, n-1);
}

// M2 : returning the array itself
int* m2(int arr1[], int key, int n, int indexes[], int i=0){
    
    if(n==-1){return indexes;}
    if(arr1[n]==key){
        indexes[i]=n;
        return m2(arr1, key, n-1, indexes, i+1);
        }
    // else{*(indexes + n)=-1;}
    return m2(arr1, key, n-1, indexes, i);
}

// Returning without an additional array argument
int* m3(int arr1[], int key, int n){
    
    if(n==-1){return arr1;}
    if(*(arr1 + n)==key){*(arr1 + n)=n;}
    else{*(arr1 + n)=-1;}
    return m3(arr1, key, n-1);
}

// Rotated binary search
int rBinarySearch(int arr[], int key, int end, int start=0){
  int mid=(start-end)/2 + end;
  if(arr[mid]==key){return mid;}

  else if(arr[mid]<key<arr[end]){return rBinarySearch(arr, key, end, mid);}
  else if(arr[start]<key<arr[mid]){return rBinarySearch(arr, key, end, mid);}

  else return -1;
}

// Triangle patterns
void p1(int n, int i){
    
    if(n==0){return;}
    else if(i<=n){
        cout<<"*";
        p1(n, i+1);
    }
    cout<<endl;
    if(i>n){p1(n-1,1);}
}
void p2(int n, int i=1, int k=1){
    
    if(k>n){return;}
    else if(i<=k){
        cout<<"*";
        p2(n,i+1,k);
    }cout<<endl;
    if(i>k){p2(n,1,k+1);}
}


// Bubble sort
int* bubbleSort(int arr[], int checkSize, int i=0){

    if(checkSize==0){return arr;}

    else if(i==checkSize){return bubbleSort(arr, checkSize-1, 0);}

    else if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    return bubbleSort(arr, checkSize, i+1);

}

// Selection sort
int* selectionSort(int arr[], int end, int i=0, int max=0){

    if(end==0){return arr;}

    if(i>end){
        int temp=arr[end];
        arr[end]=arr[max];
        arr[max]=temp;
        return selectionSort(arr, end-1, 0, 0);}
   
    if(arr[i]>arr[max]){
        return selectionSort(arr, end, i+1, i);
    }

    return selectionSort(arr, end, i+1, max);
}

// Merge 2 sorted arrays
void merge(int arr[], int s1, int mid, int e2){
    
    int arr3[e2-s1+1];
    int i=s1;
    int j=mid+1;

    int k=0;
    while (i<=mid && j<=e2)
    {
        if(arr[i] < arr[j]){arr3[k]=arr[i]; i++;}
        else{arr3[k]=arr[j]; j++;}
        k++;
    }
    while(i<=mid){ arr3[k]=arr[i]; i++; k++;}
    while(j<=e2){ arr3[k]=arr[j]; j++; k++;}

    for(int i=s1, j=0; i<=e2; ++i, ++j){
        arr[i]=arr3[j];
    }
}

void mergeSort(int arr[], int s, int e){

    if(e==s){return;}

    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid, e);
}


// Put elements > pivot at right and others at its left before the pivot( the pivot won't move first, it will later exchange it's position with the element it is smaller to in order to get all the elements smaller at the left and bigger at the right)
int partition(int arr[], int start, int pivot){

    for(int i=start+1; i<pivot; i++){
        if(arr[i-1]>arr[i]){
            int temp = arr[i-1];
            arr[i-1]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=start; i<pivot; i++){
        if(arr[i]>arr[pivot]){
            int temp = arr[i];
            arr[i]=arr[pivot];
            arr[pivot]=temp;
            pivot=i;   
        }
    }
        return pivot;

}

// Quick Sort
void quickSort(int arr[], int start, int end){
    
    if(start>=end){return;}
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
    
}


int main() {
  cout << endl;

  // Fibonacci
  // cout << Fibo(5);

  // BinarySearch
  // int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  // int key = 13;
  // int size = sizeof(arr) / sizeof(int);
  // cout << BinarySearch(arr, key, size - 1);

  // Nto1
  // Nto1(8);

  // 1toN
  // OneToN(8);

  // n!
  // cout<<nFact(5);

  // nto1Sum
  // cout<<nto1Sum(6);

  // Sum of digits of a number
  // cout<<sumOfDigits(1469);

  // Product of digits of a number
  // cout<<productOfDigits(1234);

  // Reverse a number
  // cout<<reverseTheNum(12345);

  // Check if the no. is palindrome (n==reverse of n)
  // cout<<isPalindrome(12266221);

  // Count no. of zeroes in a number
  // cout<<numberOfZeroes(22100320);

  // Count the no. of steps required for reducing a number to zero, reducing as
  // : if the number is even, divide by 2, if it is odd, subtract 1 form it
  // cout<<stepsForReducingToZero(13);

  // Is the array sorted?
    // int arr[]={1,2,4,8,9,12};
    // int size=sizeof(arr)/sizeof(int);
    // cout<<isSorted(arr, size);

  // Linear search
    // int arr[]={3,2,1,18,9,24};
    // int size=sizeof(arr)/sizeof(int);
    // cout<<LSearch(arr, 18, size-1);

    // Linear search (Multiple recuurences)
    // int arr[]={3,2,18,1,18,9,24};
    // int size=sizeof(arr)/sizeof(int);
    // LSearchMultipleM1(arr, 18, size-1);

  // // M2 : returning the array itself
  //   int* m2(int arr1[], int key, int n, int indexes[], int i=0){

  //   if(n==-1){return indexes;}
  //   if(arr1[n]==key){
  //       indexes[i]=n;
  //       return m2(arr1, key, n-1, indexes, i+1);
  //       }
  //   // else{*(indexes + n)=-1;}
  //   return m2(arr1, key, n-1, indexes, i);
  //   }

  // // Returning without an additional array argument
  //   int* m3(int arr1[], int key, int n){
    
  //     if(n==-1){return arr1;}
  //     if(*(arr1 + n)==key){*(arr1 + n)=n;}
  //     else{*(arr1 + n)=-1;}
  //     return m3(arr1, key, n-1);
    
  // Rotated binary search
  // int arr[]={5,6,7,8,9,1,2,3};
  // int key=2;
  // int size=sizeof(arr)/sizeof(int);
  // cout<<rBinarySearch(arr, key, size-1);
    
  // Triangle patterns
      // p1(4);
    // p2(4);

  // Bubble sort
    // int arr[]={9,2,7,5,4,1};
    // int size=sizeof(arr)/sizeof(int);
    // for(int i=0;i<size;i++){cout<<bubbleSort(arr,size-1)[i]<<" ";}

  // Selection sort
    // int arr[]={9,2,7,1,4,5};
    // int size=sizeof(arr)/sizeof(int);
    // for(int i=0;i<size;i++){cout<<selectionSort(arr,size-1)[i]<<" ";}

  // Merge 2 sorted arrays
    // int arr1[] = {1, 3, 5, 7};
    // int n1 = sizeof(arr1) / sizeof(int);
 
    // int arr2[] = {2, 4, 6, 8};
    // int n2 = sizeof(arr2) / sizeof(int);
 
    // int arr3[n1+n2];

    // for(int i=0; i<n1+n2; i++){
    //     cout<<mergeArrays(arr1, arr2, n1, n2, arr3)[i]<<endl;
    // }

  // Merge sort
    // int arr[]={12,11,13,5,6,7};
    // int n=sizeof(arr)/sizeof(int);
    // mergeSort(arr, 0, n-1);
    // for(int i=0; i<n; i++){cout<<arr[i]<<endl;}

  //Quick sort  
    // int arr[]={10, 80, 30, 90, 40, 50, 70};
    // int size=sizeof(arr)/sizeof(int);
    // quickSort(arr, 0, size-1);
    // for(int i=0;i<size;i++){cout<<arr[i]<<" ";}

  return 0;
}
