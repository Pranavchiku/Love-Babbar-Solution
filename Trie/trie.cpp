#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// typedef struct TrieNode{
//     struct TrieNode *children[26];
//     //isEndOfWord is true represents the end of a word
//     bool isEndOfWord;
// }TrieNode;


// //function to create a new trie node
// TrieNode* getNode(){
//     TrieNode *node = new TrieNode;
//     for(int i=0;i<26;i++){
//         node->children[i] = NULL;
//     }
//     node->isEndOfWord = false;
//     return node;
// }
// //function to insert key into trie
// //if not present, create a new node and insert key into trie
// //if key is prefix of trie node, mark it as leaf node

// void insert(TrieNode* root, string key){
//     TrieNode *p=root;
//     for(int i=0;i<key.length();i++){
//         int index=key[i]-'a';
//         if(!p->children[index]){
//             p->children[index]= getNode();
//         }

//         p=p->children[index];
//     }

//     //mark last node as leaf
//     p->isEndOfWord=true;
// }

// bool search(TrieNode* root, string key){
//     TrieNode *p=root;
//     for(int i=0;i<key.length();i++){
//         int index=key[i]-'a';
//         if(!p->children[index]){
//             return false;
//         }
//         p=p->children[index];
//     }
//     return (p && p->isEndOfWord);
// }

class TrieNode {
    public: 
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode *root;

        Trie(){
            root=new TrieNode('\0');
        }
        
        void insertUtil(TrieNode *root, string word){
            //word length 0 i.e. all elements of word are inserted
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            //get index of current character

            //assumption word will be in lowercase
            int index=word[0]-'a';

            //if current character is not present in children, create a new node
            if(root->children[index]==NULL){
                root->children[index]=new TrieNode(word[0]);
            }
            //if the element is present, insert the remaining elements
            //recursive call to insert rest of the word
            insertUtil(root->children[index],word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root, string word){
            //if all elements are seen and the last element is terminal, return true
            if(word.length()==0){
                return root->isTerminal;
            }

            //get index of current character
            int index=word[0]-'a';
            //if current character is not present in children, return false
            if(root->children[index]==NULL){
                return false;
            }
            //recursive call to search rest of the word
            return searchUtil(root->children[index],word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }

        void deleteUtil(TrieNode *root, string word){
            //if all elements are seend and the last element is terminal, delete the node
            //by marking it as non-terminal
            if(word.length()==0){
                root->isTerminal=false; //mark the node as non-terminal
                return;
            }
            //get the index of current character
            int index=word[0]-'a';
            //if current character is not present in children, return
            if(root->children[index]==NULL){
                return;
            }
            //recursive call to delete rest of the word
            deleteUtil(root->children[index],word.substr(1));
        }
        void deleteWord(string word){
            deleteUtil(root,word);
        } 

};

int main(){
    // string keys[]={"the","a","there","answer","any","by","bye","their"};
    // int n=sizeof(keys)/sizeof(keys[0]);

    // TrieNode *root=getNode();
    // //construct a trie
    // for(int i=0;i<n;i++){
    //     insert(root,keys[i]);
    // }

    // //search for different keys
    // cout<<"\nSearch for different keys: ";
    // for(int i=0;i<n;i++){
    //     if(search(root,keys[i])){
    //         cout<<"\n"<<keys[i]<<" found";
    //     }
    //     else{
    //         cout<<"\n"<<keys[i]<<" not found";
    //     }
    // }

    Trie *t = new Trie();
    t->insertWord("arm");
    t->insertWord("do");
    t->insertWord("time");
    cout<<t->searchWord("tim")<<'\n';

    t->deleteWord("arm");
    cout<<t->searchWord("arm")<<'\n';
}