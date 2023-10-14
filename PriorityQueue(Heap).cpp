#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    vector<int>v;

public:
    
    int left(int i){return i*2 + 1;}
    int right(int i){return i*2 + 2;}
    int parent(int i){return (i-1)/2;}
    int getMin(){return v[0];}

    void insert(int val){
        v.push_back(val);
        
        if(v.size()==1){return;}

        int i=v.size()-1;
        while(v[parent(i)] > v[i] && i>0){
            
            int temp = v[i];v[i] = v[parent(i)];v[parent(i)] = temp;

            i = parent(i);
        }
    }

    void minHeapify(int i){
        int smallest = i;
        if(right(i) < v.size()){            
            if(v[i]>v[right(i)]){smallest = right(i);}
        }
        if(left(i) < v.size()){            
            if(v[smallest]>v[left(i)]){smallest = left(i);}
        }
        if(smallest == i){return;}

        int temp = v[smallest];v[smallest] = v[i];v[i] = temp;

        minHeapify(smallest);
    }

    void deleteMin(){
        v[0]=v[v.size()-1];
        v.pop_back();
        minHeapify(0);
    }

    void decreaseAt(int i, int val){
        v[i]=val;
        while(v[parent(i)] > v[i] && i>0){
            
            int temp = v[i];v[i] = v[parent(i)];v[parent(i)] = temp;

            i = parent(i);
        }
    }

    void deleteAt(int i){
        decreaseAt(i, INT_MIN);
        deleteMin();
    }

    void printLOT(){
        for(int i=0; i<v.size(); ++i){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main(){

    MinHeap hp;
    hp.insert(3);
    hp.insert(7);
    hp.insert(2);
    hp.insert(4);
    hp.insert(1);
    hp.insert(14);
    hp.insert(22);
    hp.insert(12);
    hp.insert(11);

    hp.printLOT();

    cout<<hp.getMin()<<endl;
    hp.deleteMin();
    cout<<hp.getMin()<<endl;

    hp.deleteAt(6);
    hp.deleteAt(1);

    hp.printLOT();


cout<<endl;return 0;}
