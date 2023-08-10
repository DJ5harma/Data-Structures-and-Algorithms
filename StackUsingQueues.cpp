#include<iostream>
#include<queue>
using namespace std;

// Stack using queues

class stack{
   int size;
   queue<int>q1;
   queue<int>q2;

public:

   stack(){size=0;}

   void push(int data){
      if(q1.empty()){
         q2.push(data);
      }
      else{q1.push(data);}
      size++;
   }     
   void pop(){

      if(size==0){cout<<"Stack underflow!";return;}

      if(q1.empty()){
         while(q2.back()!=q2.front()){
            q1.push(q2.front());
            q2.pop();
         }q2.pop();
      }
      else{
         while(q1.back()!=q1.front()){
            q2.push(q1.front());
            q1.pop();
         }q1.pop();
      }
      size--;
      return;
   }
   int top(){

      if(size==0){cout<<"Stack underflow!";return -1;}

      if(q1.empty()){
         return q2.back();
      }
      return q1.back();
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

   stack st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);

   cout<<st.top()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   st.pop();
   cout<<st.top()<<endl;
   st.pop();
   cout<<st.empty()<<endl;

   cout<<st.getSize()<<endl;
   



return 0;}
