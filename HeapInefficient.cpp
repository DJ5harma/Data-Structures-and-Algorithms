#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void buildHeap(int v[], int &size){
    
    for(int i=0; i<size; ++i){
    int p = (i-1)/2;
    int curr = i;
        while(v[curr]>v[p] && curr>0){
            int temp = v[p];
            v[p] = v[curr]; 
            v[curr] = temp;
            curr = p;
            p = (p-1)/2;
        }
    }
}
void deleteMax(int v[], int &size){
    v[0]=v[size-1];
    size--;
    buildHeap(v, size);
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

printArr(v,size);

deleteMax(v, size);

printArr(v,size);

deleteMax(v, size);

printArr(v,size);

return 0;}
