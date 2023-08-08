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
    




int main(){

string s3 = "(a-b/c)*(a/k-d)";

// infixToPostfix(s3);
// cout<<endl;
// infixToPrefix(s3);

return 0;}
