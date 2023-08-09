#include<iostream>
using namespace std;

// Queue using LL

class node{
public:
   int data;
   node*next;
   node(){}
   node(int data){
      this->data=data;
      this->next=NULL;
   }
};

class queue{

   node*front=new node();
   node*back=new node();

public:
   queue(){
      front=NULL;
      back=NULL;
   }

   void push(int data){

      node*newNode=new node(data);
      
      if(front==NULL){
         back=newNode;
         front=newNode;
         return;
      }

      back->next=newNode;
      back=newNode;
   }
   void pop(){
      if(front==NULL){
         cout<<"Queue underflow";
         return;
      }
      node*toDelete=front;
      front=front->next;

      delete toDelete;
   }
   int peek(){
      if(front==NULL){
         cout<<"Queue empty!";
         return -1;
      }
      return front->data;  
   }
   bool empty(){
      if(front==NULL){
         return true;
      }
      return false;
   }
};

int main(){

   queue q;

   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();
   cout<<q.peek()<<endl;
   q.pop();


   cout<<endl<<q.empty();

return 0;}
