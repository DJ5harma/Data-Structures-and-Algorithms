#include<iostream>
#include<stack>
using namespace std;

// Queue using stacks
class queue{
 
   stack<int>st1;
   stack<int>st2;

public:

   queue(){}

   void enqueue(int data){
      st1.push(data);
   }
   void dequeue(){

      if(st1.empty()){
         cout<<"Queue is empty!";
         return;
      }

      while(!st1.empty()){
         st2.push(st1.top());
         st1.pop();
      }
      st2.pop();
      while(!st2.empty()){
         st1.push(st2.top());
         st2.pop();
      }
      return;
      
   }
   int peek(){
      if(st1.empty()){
         cout<<"Queue is empty!";
         return -1;
      }

      while(!st1.empty()){
         st2.push(st1.top());
         st1.pop();
      }
      int peekValue = st2.top();
      
      while(!st2.empty()){
         st1.push(st2.top());
         st2.pop();
      } 
      return peekValue;
   }
   bool empty(){
      if(st1.empty()){return true;}
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

   cout<<q.empty()<<endl;
   q.dequeue();
   cout<<q.empty();


return 0;}
