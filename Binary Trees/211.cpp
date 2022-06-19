#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}

void insert(Node *root, int key){

    Node* prev=NULL;
    Node *n=createNode(key);
    while(root!=NULL){
        prev=root;
        if(key==root->data) return;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    if(key>prev->data) prev->right=n;
    else prev->left=n;
    
}

string helper(Node *root, unordered_map<string,int> &m, vector<Node*> &v){
    if(root==NULL) return "";

    string s="(";
    s+=helper(root->left,m,v);
    s+=root->data;
    s+=helper(root->right,m,v);
    s+=")";

    if(m[s]==1 and s.length()>=3){
        v.push_back(root);
    }
    m[s]++;

    return s;
}
vector<Node*> printAllDups(Node* root)
{
    vector<Node*> v;
    unordered_map <string,int> m;
    helper(root,m,v);
    return v;
}