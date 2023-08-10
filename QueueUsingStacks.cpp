#include<iostream>
#include<stack>
using namespace std;

// Queue using stacks

class queue{
   int size;
   stack<int>st1;
   stack<int>st2;

public:

   queue(){size=0;}

   void push(int data){
      if(st1.empty()){
         while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
         }
      }
      st1.push(data);
      size++;
   }     
   void pop(){
      if(size==0){cout<<"Queue underflow!";return;}

      if(!st1.empty()){
         while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
         }
      }
      st2.pop();
      size--;return;
   }
   int top(){
      if(size==0){cout<<"Queue underflow!";return -1;}
      
      if(!st1.empty()){
         while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
         }
      }
      return st2.top();
   }
   bool empty(){
     if(size==0){return true;}
     return false;
   }
   int getSize(){
      return size;
   }


};

int main(){

   queue q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);

   cout<<q.top()<<endl;
   q.pop();
   cout<<q.top()<<endl;
   q.pop();
   cout<<q.top()<<endl;
   q.pop();
   cout<<q.top()<<endl;
   q.pop();
   cout<<q.top()<<endl;
   q.pop();
   cout<<q.empty()<<endl;

   cout<<q.getSize()<<endl;
   



return 0;}
