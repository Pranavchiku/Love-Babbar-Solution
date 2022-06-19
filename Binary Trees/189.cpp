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

vector <int> bottomView(Node *root) {

    queue<pair<Node*,int>> q;
    map<int,int> m;
    vector<int> v;
    if(root==NULL) return v;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        Node *curr=p.first;
        int h=p.second;

        m[h]=curr->data; //as we want the value at the bottom most level
        if(curr->left) q.push({curr->left,h-1});
        if(curr->right) q.push({curr->right,h+1});
    }

    for(auto x:m){
        v.push_back(x.second);
    }
}