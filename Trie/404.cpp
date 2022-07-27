#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class TrieNode{
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int count;
        TrieNode(char ch){
            data=ch;
            count=0;
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
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            root->count++;
            int index=word[0]-'a';
            if(root->children[index]==NULL){
                root->children[index]=new TrieNode(word[0]);
            }

            insertUtil(root->children[index],word.substr(1));

        }

        void insert(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode *root, string word){
            if(word.length()==0){
                return root->isTerminal;
            }

            int index=word[0]-'a';
            if(root->children[index]==NULL){
                return false;
            }

            return searchUtil(root->children[index],word.substr(1));
        }

        bool search(string word){
            return searchUtil(root,word);
        }
};

void findPrefixUtil(TrieNode *root, string word, string &prefix, set<string> &ans){
    if(word.length()==0){
        ans.insert(prefix);
        return;
    }
    int index=word[0]-'a';
    

    if(root->count==1){
        if(ans.find(prefix)==ans.end()){
            ans.insert(prefix);
            return;
        }
        else{
            prefix+=word[0];
            findPrefixUtil(root,word.substr(1),prefix,ans);
        }
        
    }
    else{
        prefix+=word[0];
        findPrefixUtil(root->children[index],word.substr(1),prefix,ans);
    }
}

void prefixUtil(vector<string> &words){
    Trie *t=new Trie();
    for(auto it: words){
        // cout<<it<<endl;
        t->insert(it);
    }
    for(auto it: words){
        cout<<it<<' '<<t->search(it)<<'\n';
    }
    set<string> ans;
    string prefix="";
    for(auto it: words){
        prefix="";
        findPrefixUtil(t->root,it,prefix,ans);
    }

    for(auto it: ans){
        cout<<it<<endl;
    }

}

int main(){
    vector<string> words={"zebra", "dog", "duck", "dove"};
    prefixUtil(words);
    return 0;
}



