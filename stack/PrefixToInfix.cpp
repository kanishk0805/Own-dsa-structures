#include<iostream>
#include<string>
using namespace std;
#include <stack>
bool isoperator(char c){
    return (c=='-' || c=='+' || c=='*' || c=='/' || c=='^');
}
string PrefixToInfix(string input){
    stack<string> res;
    int l=input.size()-1;
    while(l>-1){
        char ins=input[l];
        cout<<ins<<endl;
        if(isoperator(ins)){
            string t=res.top();   res.pop();
            string q=res.top(); res.pop();
            res.push('('+t+ins+q+')');
        }else{
            res.push(string(1,ins));
        }
        l--;
        
    }
    return res.top();
}
int main(){
    string input;
    getline(cin,input);
    cout<<PrefixToInfix(input);
}