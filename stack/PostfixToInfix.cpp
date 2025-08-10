#include<iostream>
#include<string>
using namespace std;
#include <stack>
bool isoperator(char c){
    return (c=='-' || c=='+' || c=='*' || c=='/' || c=='^');
}
string PostfixToInfix(string input){
    stack<string> res;
    int l=input.size(),i=0;
    while(i<l){
        char ins=input[i];
        if(isoperator(ins)){
            string t=res.top();   res.pop();
            string q=res.top(); res.pop();
            res.push('('+q+ins+t+')');
        }else{
            res.push(string(1,ins));
        }
        i++;
    }
    return res.top();
}
int main(){
    string input;
    getline(cin,input);
    cout<<PostfixToInfix(input);
}