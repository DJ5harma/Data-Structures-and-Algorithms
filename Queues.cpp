#include<iostream>
using namespace std;

#define n 20

class queue{

    int *arr;
    int front;
    int back;

public:

    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int data){
        if(back==n-1){cout<<"Queue full!, can't add.";return;}
        back++;
        arr[back]=data;

        if(front==-1){front++;}
    }
    void dequeue(){
        if(front>back || front==-1){cout<<"Queue empty!, can't remove.";return;}
        front++;
    }  
    int peek(){
        if(front>back || front==-1){return -1;}
        return arr[front];
    }
    bool empty(){
        if(front>back || front==-1){return true;}
        return false;
    }

};

int main(){

    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();

    cout<<endl<<q.empty();
return 0;}
