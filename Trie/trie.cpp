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

int main(){
    string keys[]={"the","a","there","answer","any","by","bye","their"};
    int n=sizeof(keys)/sizeof(keys[0]);

    TrieNode *root=getNode();
    //construct a trie
    for(int i=0;i<n;i++){
        insert(root,keys[i]);
    }

    //search for different keys
    cout<<"\nSearch for different keys: ";
    for(int i=0;i<n;i++){
        if(search(root,keys[i])){
            cout<<"\n"<<keys[i]<<" found";
        }
        else{
            cout<<"\n"<<keys[i]<<" not found";
        }
    }

}