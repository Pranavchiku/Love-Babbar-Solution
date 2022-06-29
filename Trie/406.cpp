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

vector<vector<string> > Anagrams(vector<string>& string_list) {
    map<string,vector<string>> m;
    for(int i=0;i<string_list.size();i++){
        string str=string_list[i];
        sort(str.begin(),str.end());
        m[str].push_back(string_list[i]);
    }

    vector<vector<string> > ans(m.size());
    int idx=0;
    for(auto x: m){
        auto v = x.second;
        for(int i=0;i<v.size();i++){
            ans[idx].push_back(v[i]);
        }
        idx++;
    }

    return ans;
}