#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct TrieNode{
    struct TrieNode *children[26];
    //isEndOfWord is true represents the end of a word
    bool isEndOfWord;
}TrieNode;


//function to create a new trie node
TrieNode* getNode(){
    TrieNode *node = new TrieNode;
    for(int i=0;i<26;i++){
        node->children[i] = NULL;
    }
    node->isEndOfWord = false;
    return node;
}
//function to insert key into trie
//if not present, create a new node and insert key into trie
//if key is prefix of trie node, mark it as leaf node

void insert(TrieNode* root, string key){
    TrieNode *p=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!p->children[index]){
            p->children[index]= getNode();
        }

        p=p->children[index];
    }

    //mark last node as leaf
    p->isEndOfWord=true;
}

bool search(TrieNode* root, string key){
    TrieNode *p=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!p->children[index]){
            return false;
        }
        p=p->children[index];
    }
    return (p && p->isEndOfWord);
}

bool solve(string str, TrieNode* root){
    int size=str.length();
    if(size==0) return true;

    for(int i=0;i<size;i++){
        string temp=str.substr(0,i+1);
        if(search(root,temp)){
            if(solve(str.substr(i+1,size-i-1),root)){
                return true;
            }
        }
    }

    return false;

}
int wordBreak(string A, vector<string> &B) {
    TrieNode* root=getNode();
    for(int i=0;i<B.size();i++){
        insert(root,B[i]);
    }

    return solve(A,root);

}