#include<bits/stdc++.h>
using namespace std;

void heapify(int v[], int &i, int &size){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l < size && v[l]>v[largest]){
        largest = l;
    }
    if(r < size && v[r]>v[largest]){
        largest = r;
    }

    if(largest != i){
        int temp = v[largest];
        v[largest] = v[i];
        v[i]=temp;

        heapify(v, largest, size);
    }
}

void buildHeap(int v[], int &size){
    
    for(int i = (size-1)/2; i>=0; --i){
        heapify(v, i, size);
    }
}

void printArr(int v[], int &size){
    for(int o=0; o<size; ++o){
        cout<<v[o]<<' ';
    }
    cout<<endl;
}

int main(){

int v[]={1,3,5,4,6,13,10,9,8,15,17};
int size = sizeof(v)/sizeof(int);

buildHeap(v, size);
printArr(v, size);

return 0;}
