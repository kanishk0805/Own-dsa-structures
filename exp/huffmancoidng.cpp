#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    char c;
    Node* left;
    Node* right;
    Node(int val, char c){
        this->val = val;
        this->c = c;
        left = NULL;
        right = NULL;
    }
};
class MainNode{
    public:
    Node* parent;
    unordered_map<char,string> codes;
    string enc;
    string dec;
    MainNode(Node *parent){
        this->parent=parent;
    }
    void generatecodes(Node * root,string s){
        if(root==NULL) return;
        if((root->c)!='#'){
             codes[root->c]=s;
            //  cout<<s<<endl;
        }
        generatecodes(root->left,s+"0");
        generatecodes(root->right,s+"1");
        return ;
    }
    void printcodes(){
        for(auto &i:codes){
        // cout<<char(i+'a')<<' '<<codes[i]<<endl;
            cout<<i.first<<' '<<i.second<<endl;
        }
    }
    string decode(){
        string ret; 
        string find;    
        Node *root=parent;
        for(auto &i:enc){
            find+=i;
            if(root->c=='#'){
                if(i=='0') root=root->left;
                else root=root->right;
            }
            if(root->c!='#'){
                cout<<find<<endl;
                find="";
                ret+=root->c;
                root=parent;
            }
        }
        return ret;
    }
    string encode(string s){
        dec=s;
      
        for(auto &i:s){
            enc+=codes[i];
        }
        return enc;
    }


};
struct comp{
    bool operator()(auto a,auto b){
        return a->val > b->val;
    }
};
int main(){
    string s="erertet";
    // cin>>s;
    vector<int> freq(26);
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    priority_queue<Node *,vector<Node *>,comp> pq;
    for(int i=0;i<26;i++){
        if(freq[i] > 0){
            // cout<<(char)(i+'a')<<' '<<freq[i]<<endl;
            Node* ins=new Node(freq[i],i+'a');
            pq.push(ins);
        }
    }
    while(pq.size() > 1){
        Node* right=pq.top();
        
        pq.pop();
        Node * left=pq.top();
        pq.pop();
        Node* parent = new Node(left->val+right->val,'#');
        parent->left = left;
        parent->right = right;
        // cout<<parent->val<<' '<<left->val<<' '<<right->val<<' '<<right->c<<' '<<left->c<<endl;
        pq.push(parent);
    }
    Node* parent = pq.top();
    MainNode ourHuffman(parent);
    ourHuffman.generatecodes(parent,"");
    ourHuffman.printcodes();
    string enc=ourHuffman.encode(s);
    cout<<enc<<endl;
    string dec=ourHuffman.decode();
    cout<<dec<<endl;
    return 0;

}