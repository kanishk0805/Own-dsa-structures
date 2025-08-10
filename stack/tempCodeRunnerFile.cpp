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
                    while(!stck.empty() && value(ins)<=value(stck.top())){
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