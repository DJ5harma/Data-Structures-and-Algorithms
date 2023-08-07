#include <iostream>
#include <stack>//Last in, first out
using namespace std;


int main(){cout<<endl;

// Create a stack
    stack<int> stack;

// pushing
stack.push(2);
stack.push(4);
stack.push(7);

// Access top element
cout<<stack.top()<<endl;

// popping
stack.pop();
cout<<stack.top()<<endl;

// Check if stack is empty
cout<<stack.empty()<<endl;

// Get the size of stack
cout<<stack.size();

return 0;}
