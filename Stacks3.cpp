#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int evaluatePrefixExpression(string &str){
    stack<int>st;

    for(int i = str.length()-1; i>=0; i--){    
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}

int evaluatePostfixExpression(string str){

    stack<int>st;

    for(int i=0; i<str.length(); i++){
        
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();

}


int main(){

string s1 = "-+7*45+20";
// cout<<evaluatePrefixExpression(s1)<<endl;

string s2 = "46+2/5*7+";
// cout<<evaluatePostfixExpression(s2);


return 0;}
