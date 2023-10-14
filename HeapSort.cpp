#include<bits/stdc++.h>
using namespace std;

void heapify(int v[], int &i, int &size){
    int smallest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l < size && v[l]<v[smallest]){
        smallest = l;
    }
    if(r < size && v[r]<v[smallest]){
        smallest = r;
    }

    if(smallest != i){
        int temp = v[smallest];
        v[smallest] = v[i];
        v[i]=temp;

        heapify(v, smallest, size);
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

while (size){
    buildHeap(v, size);
    cout<<v[0]<<' ';
    v[0]=v[size-1];
    size--;
}

return 0;}
