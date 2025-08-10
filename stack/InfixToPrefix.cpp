#include<iostream>
#include<string>
using namespace std;
#include <stack>
int value(char ch){
    if(ch=='('){
        return 0;
    }else if(ch=='^'){
        return 3;
    }else if(ch=='*' || ch=='/'){
        return 2;
    }else if(ch=='+' || ch=='-'){
        return 1;
    }
}
string reversestring(string input){
    string rev;
    int i=input.size()-1;
    char s=input[i];
    while(i>-1){
        if(s=='('){
            rev+=')';
        }else if(s==')'){
            rev+='(';
        }else{
            rev+=s;
        }
        i--;
        s=input[i];
    }
    return rev;
}
bool isoperator(char c){
   return (c=='-' || c=='+' || c=='*' || c=='/' || c=='^');
}
string infixToPostfix(string s) {
        string res="";
        stack<char> stck;
        int i=0;
        while(s[i]!='\0'){
            char ins=s[i];
            if(ins=='('){
                stck.push(ins);
            }else if(isoperator(ins)){
                if(!stck.empty()){
                    while(!stck.empty() && value(ins)<value(stck.top())){
                    res+=stck.top();
                    stck.pop();
                    }
                }
                stck.push(ins);
            }else if(ins==')'){
                while(stck.top()!='('){
                    res+=stck.top();
                    stck.pop();
                }
                stck.pop();
            }else{
                res+=ins;
            }
            i++;
        }
        while(!stck.empty()){
            res+=stck.top();
            stck.pop();
        }
        res+='\0';
        return res;
    }
int main(){
    string s="";
    getline(cin,s);
    string res=infixToPostfix(reversestring(s));
    cout<<reversestring(res);
}