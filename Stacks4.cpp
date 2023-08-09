#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

void infixToPostfix(string str){
    stack<char>st;
    
    for(int i=0; i<str.length(); i++){
        int count=0;

        if(str[i]=='('){
            i++;
            while(str[i]!=')'){
                if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='^'){
                    st.push(str[i]);
                    count++;
                }
                else{
                    cout<<str[i];
                }
                i++;
            }
            while(count!=0){
                cout<<st.top();
                st.pop();count--;
            }

        }
        else{
            st.push(str[i]);
        }
    }
        while(!str.empty()){
            cout<<st.top();
            st.pop();
        }
}

// !!!!The output is correct but in reverse order it is (tried storing couts in string/stack but an unknown reason prevents that, GO FIGURE C++ basics)
void infixToPrefix(string str){
    stack<char>st;
    
    for(int i=str.length()-1; i>=0; i--){
        int count=0;

        if(str[i]==')'){
            i--;
            while(str[i]!='('){
                if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='^'){
                    st.push(str[i]);
                    count++;
                }
                else{
                    cout<<str[i];
                }
                i--;
            }
            while(count!=0){
                cout<<st.top();
                st.pop();count--;
            }

        }
        else{
            st.push(str[i]);
        }
    }
    while(!str.empty()){
        cout<<st.top();
        st.pop();
    }
}
    
bool checkIfBalancedParanthesis(string str){
    stack<char>st;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            switch (str[i])
            {
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            case '(':
                st.push(')');
                break;
            
            default:
                break;
            }
        }
        else if(str[i]==st.top()){
            st.pop();
        }
        else{return false;}
    }
    return true;
}



int main(){

string s3 = "(a-b/c)*(a/k-d)";

// infixToPostfix(s3);
// cout<<endl;
// infixToPrefix(s3);

// string str1="{[()]}";
// string str2="{[(])}";
// cout<<checkIfBalancedParanthesis(str1)<<endl;
// cout<<checkIfBalancedParanthesis(str2);
    
return 0;}
