#include <bits/stdc++.h> 
using namespace std;
class TrieNode{
    public:
    TrieNode * children[26];
    int IsEnd;
    int count;
    TrieNode(){
        for(int i=0;i<26;i++)children[i]=NULL;
        IsEnd=0;
        count=0;
    }
};
class Trie{
    TrieNode *root;
    public:
    Trie(){
       root=new TrieNode;
    }

    void insert(string &word){
         TrieNode * node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int t=word[i]-'a';
            if(node->children[t]==nullptr){
                TrieNode * ins=new TrieNode;
                node->children[t]=ins;
            }
            node=node->children[t];
            node->count++;
        }
        node->IsEnd++;
        return;
    }

    int countWordsEqualTo(string &word){
         TrieNode * node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int t=word[i]-'a';
            if(node->children[t]==nullptr) return 0;
            node=node->children[t];
        }
        return node->IsEnd;
    }

    int countWordsStartingWith(string &word){
        TrieNode * node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int t=word[i]-'a';
            if(node->children[t]==nullptr) return 0;
            node=node->children[t];
        }
        return node->count;
    }

    void erase(string &word){
        TrieNode * node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            int t=word[i]-'a';
            node=node->children[t];
            node->count--;
        }
        node->IsEnd--;
        return ;
    }
};
