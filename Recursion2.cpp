#include <iostream>
// #include <string>
using namespace std;


// Remove character
string rmChar(string str, char Char, string newStr="", int i=0){

    if(i<str.length()){
        if(str[i] == Char){
            return rmChar(str, Char, newStr, i+1);
        }
        else{
            return rmChar(str, Char, newStr+str[i], i+1);
            }
    }
    return newStr;
    
}
// Remove substring
string rmStr(string str, string rm, string newStr="", int i=0){
    if(i<str.length()){
        if(str.substr(i, rm.length())==rm){
            return rmStr(str, rm, newStr, i+rm.length());
        }
        else{
            return rmStr(str, rm, newStr+str[i], i+1);}
    }
    return newStr;

}

// Remove substring which (+ some more indices != another substring)
string rmStrNotSb(string str, string rm, string nott, string newStr="", int i=0){
    if(i<str.length()){
        if(str.substr(i, rm.length())==rm && str.substr(i, nott.length())!=nott){
            return rmStrNotSb(str, rm, nott, newStr, i+rm.length());
        }
        else{
            return rmStrNotSb(str, rm, nott, newStr+str[i], i+1);
        }
    }
    return newStr;
}

int main(){cout<<endl;

// Remove character
    // string str="baccad";
    // cout<<rmChar(str, 'a');

// Remove substring
    // string str="an apple a day, apple keeps apple.";
    // cout<<rmStr(str, " apple");

// Remove substring which (+ some more indices != another substring)
    // string str="an apple a day, doctor keeps applllllkkklkk apple.";
    // cout<<rmStrNotSb(str, "app", "apple");

return 0;}
