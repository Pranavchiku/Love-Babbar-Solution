#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    char data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}

string helper(Node *root, unordered_map<string,int> &m, vector<int> &v){
    if(root==NULL) return "";
    string s="(";
    s+=helper(root->left,m,v);
    s+=root->data;
    s+=helper(root->right,m,v);
    s+=")";
    
    if(m[s]==1 and s.length()>=4){
        v.push_back(root->data);
    }
    m[s]++;
    
    return s;
}

int dupSub(Node *root){
    unordered_map<string,int> m;
    vector<int> v;
    helper(root,m,v);
    return v.size()>0;
}